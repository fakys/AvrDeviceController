//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_FILENOTSUPORTEDDRIVER_H
#define AVR_PROTO_LINUX_FILENOTSUPORTEDDRIVER_H
#include "../../../../include/Exceptions/MainException.h"

class FileNotSupportedDriver: public MainException {
public:
    FileNotSupportedDriver(std::string message): MainException(message) {};
};

#endif //AVR_PROTO_LINUX_FILENOTSUPORTEDDRIVER_H
