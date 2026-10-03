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

    AbstractReadDriver* getReadDriver();
    AbstractWriteDriver* getWriteDriver();
    void closeFile();

    ~FileEntity();
};

#endif //AVR_PROTO_LINUX_FILEENTITY_H
