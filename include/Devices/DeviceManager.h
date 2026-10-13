//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICEMANAGER_H
#define AVRDEVICECONTROLLER_DEVICEMANAGER_H
#include <vector>

#include "Device.h"

class DeviceManager {
    private:
        std::vector<Device*> devices;
    public:

    void registerDevice(Device* device) {
        devices.push_back(device);
    }

    std::vector<Device*>& getAllDevices() {
        return devices;
    }

    Device* getDeviceByArchitectureName(const std::string& architectureName) {
        for (Device* device : getAllDevices()) {
            if (device->getArchitecture() == architectureName) {
                return device;
            }
        }
        return nullptr;
    }
};

#endif //AVRDEVICECONTROLLER_DEVICEMANAGER_H
