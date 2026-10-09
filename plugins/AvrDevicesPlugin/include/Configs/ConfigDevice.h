//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGDEVICE_H
#define AVRDEVICECONTROLLER_CONFIGDEVICE_H
#include "DeviceName.h"
#include "DevicePath.h"
#include "DeviceType.h"
#include "ObjectConfigFieldType.h"

class ConfigDevice : public ObjectConfigFieldType {
public:
    ConfigDevice() {
        this->childs = std::vector<AbstractConfigType*> {
            new DeviceName(),
            new DevicePath(),
            new DeviceType(),
        };
    }
    std::string getConfigName() override {
        return "device";
    };

    bool requiredField() override {
        return false;
    };
};

#endif //AVRDEVICECONTROLLER_CONFIGDEVICE_H
