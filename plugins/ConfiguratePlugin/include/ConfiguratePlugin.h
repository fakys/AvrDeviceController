//
// Created by fakys on 02.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
#define AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
#include "AbstractPlugin.h"
#include "PluginLoader.h"

class ConfiguratePlugin :public AbstractPlugin {
    public:
    std::string getPluginName() override {
        return "ConfiguratePlugin";
    }

    int pluginLoad() override {
        std::cout << "dasd"<< std::endl;
        return 0;
    }

    std::vector<std::string>* getDependPlugins() override {
        return new std::vector<std::string>{
            "FileRWPlugin"
        };
    }
};

registerPlugin(ConfiguratePlugin);

#endif //AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
