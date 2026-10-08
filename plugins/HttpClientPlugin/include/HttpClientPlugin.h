//
// Created by fakys on 08.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPCLIENTPLUGIN_H
#define AVRDEVICECONTROLLER_HTTPCLIENTPLUGIN_H

#include "AbstractPlugin.h"

class HttpClientPlugin :public AbstractPlugin {
    public:
    std::string getPluginName() override {
        return "HttpClientPlugin";
    }

    int pluginLoad() override {
        return 0;
    }

    std::vector<std::string>* getDependPlugins() override {
        return new std::vector<std::string>{
            "ConfiguratePlugin"
        };
    }
};

#endif //AVRDEVICECONTROLLER_HTTPCLIENTPLUGIN_H
