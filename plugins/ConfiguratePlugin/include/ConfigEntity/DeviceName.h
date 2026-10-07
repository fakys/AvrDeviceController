//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICENAME_H
#define AVRDEVICECONTROLLER_DEVICENAME_H

#include "StringConfigFieldType.h"

class DeviceName : public StringConfigFieldType {
public:
    DeviceName(std::string value) : StringConfigFieldType(value) {}
    std::string getConfigName() override {
        return "name";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_DEVICENAME_H
