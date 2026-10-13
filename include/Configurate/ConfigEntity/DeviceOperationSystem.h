//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICEOPERATIONSYSTEM_H
#define AVRDEVICECONTROLLER_DEVICEOPERATIONSYSTEM_H

#include "StringConfigFieldType.h"

#define DEVICE_OPERATION_SYSTEM_FIELD "operation_system"

class DeviceOperationSystem : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "operation_system";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_DEVICEOPERATIONSYSTEM_H
