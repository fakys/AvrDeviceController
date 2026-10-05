//
// Created by fakys on 04.10.2026.
//

#ifndef AVRDEVICECONTROLLER_FILEERROREXCEPTION_H
#define AVRDEVICECONTROLLER_FILEERROREXCEPTION_H

#include "../../../../include/Exceptions/MainException.h"

class FileErrorException: public MainException {
private:
    int fileErrorCode;
public:
    FileErrorException(std::string message, int fileErrorCode): MainException(message), fileErrorCode(fileErrorCode) {};

    int getFileErrorCode() {
        return fileErrorCode;
    }
};

#endif //AVRDEVICECONTROLLER_FILEERROREXCEPTION_H
