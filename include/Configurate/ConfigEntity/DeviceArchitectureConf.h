//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICEARCHITECTURECONF_H
#define AVRDEVICECONTROLLER_DEVICEARCHITECTURECONF_H

#include "StringConfigFieldType.h"

#define ARCHITECTURE_FIELD_NAME "architecture"

#define AVR_ARCHITECTURE "AVR"

class DeviceArchitectureConf : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "architecture";
    }

    bool requiredField() override {
        return true;
    }
};


#endif //AVRDEVICECONTROLLER_DEVICEARCHITECTURECONF_H
