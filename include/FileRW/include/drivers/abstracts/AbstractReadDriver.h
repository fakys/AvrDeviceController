#ifndef AVR_PROTO_LINUX_ABSTRACTREADDRIVER_H
#define AVR_PROTO_LINUX_ABSTRACTREADDRIVER_H
#include <cstdint>
#include <vector>

class AbstractReadDriver {
    protected:
        int fileIndex = 0;
    public:
    AbstractReadDriver() = default;
    virtual ~AbstractReadDriver() = default;
    virtual bool readFile(std::vector<uint8_t>* buffer) = 0;
    void setFileIndex(int fileIndex) {
        this->fileIndex = fileIndex;
    }
    int getFileIndex() {
        return this->fileIndex;
    }
};

#endif
