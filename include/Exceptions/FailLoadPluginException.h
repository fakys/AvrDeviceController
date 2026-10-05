//
// Created by fakys on 05.10.2026.
//

#ifndef AVRDEVICECONTROLLER_FAILDLOADPLUGINEXCEPTION_H
#define AVRDEVICECONTROLLER_FAILDLOADPLUGINEXCEPTION_H

#include "MainException.h"

class FailLoadPluginException : public MainException {
public:
    FailLoadPluginException(std::string message) : MainException(message) {};
};

#endif //AVRDEVICECONTROLLER_FAILDLOADPLUGINEXCEPTION_H
