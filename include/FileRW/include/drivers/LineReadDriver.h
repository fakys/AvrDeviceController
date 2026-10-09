#ifndef AVR_PROTO_LINUX_LINEREADDRIVER_H
#define AVR_PROTO_LINUX_LINEREADDRIVER_H
#include "AbstractReadDriver.h"
#include <unistd.h>
#include <algorithm>


class LineWriteDriver: public AbstractReadDriver {
    private:
        std::vector<uint8_t> separators;
        int currentLine = 0;
    public:
        LineWriteDriver(std::vector<uint8_t> separators) : separators(std::move(separators)), AbstractReadDriver() {
        }

        bool readFile(std::vector<uint8_t>* buffer) override {
            buffer->clear();

            uint8_t byte;
            ssize_t bytes_read;

            while ((bytes_read = read(this->fileIndex, &byte, 1)) > 0) {
                buffer->push_back(byte);
                auto it = std::find(separators.begin(), separators.end(), byte);
                if (it != separators.end())
                {
                    currentLine++;
                    break;
                }
            }

            if (!bytes_read) {
                return false;
            }

            if (bytes_read == -1) {
                //todo log или ошибку
                return false;
            }

            return true;
        }
};

#endif
