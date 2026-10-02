#ifndef AVR_PROTO_LINUX_ABSTRACTWRITE_H
#define AVR_PROTO_LINUX_ABSTRACTWRITE_H

class AbstractWriteDriver {
protected:
    int fileIndex = 0;
public:
    AbstractWriteDriver() = default;
    virtual ~AbstractWriteDriver() = default;
    void setFileIndex(int fileIndex) {
        this->fileIndex = fileIndex;
    }
    int getFileIndex() {
        return this->fileIndex;
    }};

#endif
