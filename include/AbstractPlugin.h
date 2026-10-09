//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_ABSTRACTPLUGIN_H
#define AVR_PROTO_LINUX_ABSTRACTPLUGIN_H
#include "main.h"
#include "AbstractConfigType.h"

class AbstractPlugin {
private:
    bool pluginLoaded = false;
public:
    virtual std::string getPluginName() = 0;
    virtual std::vector<std::string>* getDependPlugins()=0;
    virtual int pluginLoad() = 0;
    virtual std::vector<AbstractConfigType*> getConfigs() = 0;

    void pluginIsLoaded() {
        pluginLoaded = true;
    }

    bool getPluginLoaded() {
        return pluginLoaded;
    }
};

#endif //AVR_PROTO_LINUX_ABSTRACTPLUGIN_H
