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
private:
    DeviceName *deviceName = nullptr;
    DeviceType *deviceType = nullptr;
    DevicePath *devicePath = nullptr;

public:
    std::string getConfigName() override {
        return "device";
    };

    bool requiredField() override {
        return false;
    };

    bool handelRow(std::vector<uint8_t> row) override;

    std::string getName() {
        return this->deviceName->getValue();
    }

    std::string getType() {
        return this->deviceType->getValue();
    }

    std::string getDevicePath() {
        return this->devicePath->getValue();
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGDEVICE_H
