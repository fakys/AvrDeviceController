//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTDEVICE_H
#define AVRDEVICECONTROLLER_ABSTRACTDEVICE_H

#include <cstdint>

#include "AbstractDeviceProto.h"
#include "AbstractOperationSystem.h"

#define DEVICE_ACTIVE_STATUS 1
#define DEVICE_DISABLED_STATUS 0

class Device {
    protected:
        std::string architectureName;
        uint64_t mac_address;
        uint8_t status;
        AbstractOperationSystem* operation_system;
        AbstractDeviceProto* proto;
    public:
        Device(
            std::string architectureName,
            uint64_t mac_address,
            uint8_t status,
            AbstractOperationSystem* operation_system,
            AbstractDeviceProto* proto
        ): mac_address(mac_address), status(status), operation_system(operation_system), proto(proto), architectureName(architectureName) {};

        AbstractOperationSystem* getOperationSystem() {
            return operation_system;
        }

        AbstractDeviceProto* getProto() {
            return proto;
        }

        std::string getArchitecture() {
            return architectureName;
        }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTDEVICE_H
