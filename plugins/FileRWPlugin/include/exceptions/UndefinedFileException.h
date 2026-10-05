#ifndef AVR_PROTO_LINUX_UNDEFINDFILEEXCEPTION_H
#define AVR_PROTO_LINUX_UNDEFINDFILEEXCEPTION_H
#include "FileErrorException.h"

class UndefinedFileException: public FileErrorException {
public:
    UndefinedFileException(std::string message): FileErrorException(message, ENOENT) {};
};

#endif
