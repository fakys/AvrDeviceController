//
// Created by fakys on 05.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATEEXCEPTION_H
#define AVRDEVICECONTROLLER_CONFIGURATEEXCEPTION_H
#include "MainException.h"

class ConfigurateException : public MainException {
    public:
    ConfigurateException(std::string message) : MainException(message) {};
};

#endif //AVRDEVICECONTROLLER_CONFIGURATEEXCEPTION_H
