//
// Created by fakys on 02.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
#define AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
#include "AbstractPlugin.h"
#include "PluginLoader.h"

class ConfiguratePlugin :public AbstractPlugin {
    std::string getPluginName() {
        return "ConfiguratePlugin";
    }
};

registerPlugin(ConfiguratePlugin);

#endif //AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
