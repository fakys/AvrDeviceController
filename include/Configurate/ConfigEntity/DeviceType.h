//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICETYPE_H
#define AVRDEVICECONTROLLER_DEVICETYPE_H

#include "StringConfigFieldType.h"

#define DEVICE_TYPE_FIELD "type"
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
