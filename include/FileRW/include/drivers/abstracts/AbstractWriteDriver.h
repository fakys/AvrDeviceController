#ifndef AVR_PROTO_LINUX_ABSTRACTWRITE_H
#define AVR_PROTO_LINUX_ABSTRACTWRITE_H

#include <string>

class AbstractWriteDriver {
protected:
    int fileIndex = 0;
public:
    virtual bool writeFile(std::vector<uint8_t>* buffer) = 0;
    void setFileIndex(int fileIndex) {
        this->fileIndex = fileIndex;
    }
    int getFileIndex() {
        return this->fileIndex;
    }};

#endif
