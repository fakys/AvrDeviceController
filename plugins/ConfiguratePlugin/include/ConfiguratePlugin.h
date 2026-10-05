//
// Created by fakys on 02.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
#define AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
#include "AbstractPlugin.h"
#include "PluginLoader.h"
#include "ConfigurateLoader.h"


class ConfiguratePlugin :public AbstractPlugin {
    private:
        ConfigurateLoader* configurateLoader;
        Configurate* config;
    public:
    ConfiguratePlugin() {
        this->configurateLoader = new ConfigurateLoader();
    }

    std::string getPluginName() override {
        return "ConfiguratePlugin";
    }

    int pluginLoad() override {
        if (!this->configurateLoader->checkConfig()) {
            return -1;
        }
        this->config = this->configurateLoader->loadConfig();
        return 0;
    }

    Configurate* getConfigurate() {
        return this->config;
    }

    std::vector<std::string>* getDependPlugins() override {
        return new std::vector<std::string>{
            "FileRWPlugin"
        };
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGURATEPLUGIN_H
