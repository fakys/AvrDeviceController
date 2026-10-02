#ifndef AVR_PROTO_LINUX_LINEREADDRIVER_H
#define AVR_PROTO_LINUX_LINEREADDRIVER_H
#include "AbstractReadDriver.h"
#include <unistd.h>

class LineReadDriver: public AbstractReadDriver {
    private:
        uint8_t separator;
        int currentLine = 0;
    public:
        LineReadDriver(uint8_t separator = '\n') : separator(separator), AbstractReadDriver() {
        }

        bool readFile(std::vector<uint8_t>* buffer) override {
            buffer->clear();

            uint8_t byte;
            ssize_t bytes_read;
            //Линия на которой мы находимся, 0 = наша актуальная
            int line = currentLine;

            while ((bytes_read = read(this->fileIndex, &byte, 1)) > 0) {
                if (line == 0) {
                    buffer->push_back(byte);
                    if (byte == separator) {
                        currentLine++;
                        break;
                    }
                } else {
                    line--;
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
