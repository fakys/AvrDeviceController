//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_AVRDEVICEEXCEPTION_H
#define AVRDEVICECONTROLLER_AVRDEVICEEXCEPTION_H
#include <stdexcept>

#include "MainException.h"

class AvrDeviceException : public MainException {
public:
    AvrDeviceException(std::string message): MainException(message) {};
};

#endif //AVRDEVICECONTROLLER_AVRDEVICEEXCEPTION_H
