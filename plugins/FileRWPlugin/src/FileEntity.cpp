//
// Created by fakys on 02.10.2026.
//

#include "FileEntity.h"


AbstractReadDriver* FileEntity::getReadDriver() {
    if (!readDriver) {
        throw FileNotSupportedDriver("read driver not supported for this file");
    }
    return readDriver;
}

AbstractWriteDriver* FileEntity::getWriteDriver() {
    if (!writeDriver) {
        throw FileNotSupportedDriver("write driver not supported for this file");
    }
    return writeDriver;
}

void FileEntity::closeFile() {
    close(this->fileIndex);
}

FileEntity::~FileEntity() {
    if (this->fileIndex) {
        this->closeFile();
    }
}