//
// Created by fakys on 09.10.2026.
//

#ifndef AVRDEVICECONTROLLER_AVRDEVICESPLUGIN_H
#define AVRDEVICECONTROLLER_AVRDEVICESPLUGIN_H

#include "AbstractPlugin.h"
#include "ArrayConfigFieldType.h"
#include "AvrDeviceException.h"
#include "ConfigAllDevices.h"


class AvrDevicesPlugin : public AbstractPlugin {
public:
    std::string getPluginName() override {
        return "AvrDevicesPlugin";
    }

    std::vector<AbstractConfigType *> getConfigs() override {
        return std::vector<AbstractConfigType *>{};
    }

    int pluginLoad() override {
        ConfigAllDevices *devices = (ConfigAllDevices *) Kernel::getObject()->getConfigurate()->getFieldByName(DEVICES);
        if (devices) {
            for (AbstractConfigType *abstractConfDevice: devices->getElements()) {
                auto *confDevice = (ConfigDevice *) abstractConfDevice;
                std::string name = ((StringConfigFieldType *) confDevice->getFieldByName(DEVICE_FIELD_NAME))->
                        getValue();
                std::string type = ((StringConfigFieldType *) confDevice->getFieldByName(DEVICE_TYPE_FIELD))->
                        getValue();
                std::string proto_name = ((StringConfigFieldType *) confDevice->getFieldByName(DEVICE_PROTO_FIELD))->
                        getValue();
                std::string operation_system_name = ((StringConfigFieldType *) confDevice->getFieldByName(
                    DEVICE_OPERATION_SYSTEM_FIELD))->getValue();
                std::string architecture_name = ((StringConfigFieldType *) confDevice->getFieldByName(
                    ARCHITECTURE_FIELD_NAME))->getValue();
                if (architecture_name == AVR_ARCHITECTURE) {
                    AbstractOperationSystem* operation_system = Kernel::getObject()->getOperationSystemsManager()->getOperationSystemByName(operation_system_name);
                    if (!operation_system) {
                        throw AvrDeviceException("OperationSystem not found: " + operation_system_name);
                    }

                    AbstractDeviceProto* proto = Kernel::getObject()->getProtocolsManager()->getProtoByName(proto_name);
                    if (!proto) {
                        throw AvrDeviceException("Protocol not found: " + proto_name);
                    }

                    Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Register device: "+name);
                    Device* device = new Device(
                        name,
                        architecture_name,
                        DEVICE_DISABLED_STATUS,
                        operation_system,
                        proto
                    );
                    Kernel::getObject()->getDeviceManager()->registerDevice(device);

                }
            }
        }

        return 0;
    }

    std::vector<std::string> *getDependPlugins() override {
        return new std::vector<std::string>{
            "UartProtoPlugin",
            "UnixMicroControllersOperationSystemPlugin"
        };
    }
};


#endif //AVRDEVICECONTROLLER_AVRDEVICESPLUGIN_H
