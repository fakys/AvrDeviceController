//
// Created by fakys on 09.10.2026.
//

#ifndef AVRDEVICECONTROLLER_AVRDEVICESPLUGIN_H
#define AVRDEVICECONTROLLER_AVRDEVICESPLUGIN_H

#include "AbstractConfigType.h"
#include "AbstractPlugin.h"
#include "ConfigAllDevices.h"

class AvrDevicesPlugin :public AbstractPlugin {
public:
    std::string getPluginName() override {
        return "AvrDevicesPlugin";
    }

    std::vector<AbstractConfigType*> getConfigs() override {
        return std::vector<AbstractConfigType*>{};
    }

    int pluginLoad() override {
        return 0;
    }

    std::vector<std::string>* getDependPlugins() override {
        return new std::vector<std::string>{};
    }
};


#endif //AVRDEVICECONTROLLER_AVRDEVICESPLUGIN_H
