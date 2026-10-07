//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGALLDEVICES_H
#define AVRDEVICECONTROLLER_CONFIGALLDEVICES_H

#include "ArrayConfigFieldType.h"
#include "ConfigDevice.h"

class ConfigAllDevices : public ArrayConfigFieldType {
private:
    std::vector<ConfigDevice*> devices;
public:
    ConfigAllDevices() = default;
    std::string getConfigName() override {
        return "devices";
    };
    bool requiredField() override {
        return false;
    };
    bool handelRow(std::vector<uint8_t> row) override;

    std::vector<ConfigDevice*> getDevices() {
        return devices;
    };
};

#endif //AVRDEVICECONTROLLER_CONFIGALLDEVICES_H
