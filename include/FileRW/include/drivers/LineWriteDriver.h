#ifndef AVR_PROTO_LINUX_LINEREADDRIVER_H
#define AVR_PROTO_LINUX_LINEREADDRIVER_H

#include "AbstractWriteDriver.h"
#include <unistd.h>
#include <vector>


class LineWriteDriver: public AbstractWriteDriver {
private:
    uint8_t separator;
public:
    LineWriteDriver(uint8_t separator) : separator(separator) {};

    bool writeFile(std::vector<uint8_t> buffer) override {
        buffer.push_back(this->separator);
        ssize_t writeSize = write(this->getFileIndex(), &buffer[0], buffer.size());

        return writeSize == buffer.size();
    }
};

#endif
