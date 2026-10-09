//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICETYPE_H
#define AVRDEVICECONTROLLER_DEVICETYPE_H

#include "StringConfigFieldType.h"

#define UART_TYPE "UART"

class DeviceType : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "type";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_DEVICETYPE_H
