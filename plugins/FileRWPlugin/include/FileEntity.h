//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_FILEENTITY_H
#define AVR_PROTO_LINUX_FILEENTITY_H
#include "AbstractReadDriver.h"
#include "AbstractWriteDriver.h"
#include "FileNotSupportedDriver.h"
#include <unistd.h>;

class FileEntity {
    private:
        int fileIndex;
        int flag;
        AbstractReadDriver* readDriver;
        AbstractWriteDriver* writeDriver;
    public:
    FileEntity(int fileIndex, int flag, AbstractReadDriver* readDriver, AbstractWriteDriver* writeDriver):
    fileIndex(fileIndex), flag(flag), readDriver(readDriver), writeDriver(writeDriver) {
        if (writeDriver) {
            writeDriver->setFileIndex(fileIndex);
        }
        if (readDriver) {
            readDriver->setFileIndex(fileIndex);
        }
    };

    AbstractReadDriver* getReadDriver() {
        if (!readDriver) {
            throw FileNotSupportedDriver("read driver not supported for this file");
        }
        return readDriver;
    };

    AbstractWriteDriver* getWriteDriver() {
        if (!writeDriver) {
            throw FileNotSupportedDriver("write driver not supported for this file");
        }
        return writeDriver;
    };

    void closeFile() {
        close(this->fileIndex);
    }

    ~FileEntity() {
        if (this->fileIndex) {
            this->closeFile();
        }
    }
};

#endif //AVR_PROTO_LINUX_FILEENTITY_H
