//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGALLDEVICES_H
#define AVRDEVICECONTROLLER_CONFIGALLDEVICES_H

#include "ArrayConfigFieldType.h"
#include "ConfigDevice.h"

class ConfigAllDevices : public ArrayConfigFieldType {
public:
     AbstractParentConfigField* createChildConf() override {
        return new ConfigDevice();
    }
    std::string getConfigName() override {
        return "devices";
    };
    bool requiredField() override {
        return false;
    };
};

#endif //AVRDEVICECONTROLLER_CONFIGALLDEVICES_H
