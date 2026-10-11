//
// Created by fakys on 08.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPCLIENTPLUGIN_H
#define AVRDEVICECONTROLLER_HTTPCLIENTPLUGIN_H

#include "AbstractConfigType.h"
#include "AbstractPlugin.h"
#include "HttpObjectConfig.h"
#include "HttpWorkerTask.h"
#include "Kernel.h"

class HttpClientPlugin :public AbstractPlugin {
    public:
    std::string getPluginName() override {
        return "HttpClientPlugin";
    }

    std::vector<AbstractConfigType*> getConfigs() override {
        return std::vector<AbstractConfigType*>{
            new HttpObjectConfig()
        };
    }

    int pluginLoad() override {
        ObjectConfigFieldType* httpConfig = (ObjectConfigFieldType*)Kernel::getObject()->getConfigurate()->getFieldByName("http");
        if (httpConfig) {
            Kernel::getObject()->getProcessManager()->createThread(
                new HttpWorkerTask()
            );
        }

        return 0;
    }

    std::vector<std::string>* getDependPlugins() override {
        return new std::vector<std::string>{};
    }
};

#endif //AVRDEVICECONTROLLER_HTTPCLIENTPLUGIN_H
