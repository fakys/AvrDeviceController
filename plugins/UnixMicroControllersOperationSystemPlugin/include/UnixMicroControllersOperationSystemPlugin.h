//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_UNIXMICROCONTROLLERSOPERATIONSYSTEMPLUGIN_H
#define AVRDEVICECONTROLLER_UNIXMICROCONTROLLERSOPERATIONSYSTEMPLUGIN_H
#include "AbstractPlugin.h"
#include "Kernel.h"
#include "UnixMicroControllersOperationSystem.h"

class UnixMicroControllersOperationSystemPlugin : public AbstractPlugin {
    public:

    std::string getPluginName() {
        return "UnixMicroControllersOperationSystemPlugin";
    };

    std::vector<std::string>* getDependPlugins() {
        return new std::vector<std::string>{};
    };

    int pluginLoad() {
        Kernel::getObject()->getOperationSystemsManager()->registerOperationSystem(
            new UnixMicroControllersOperationSystem()
        );
        return 0;
    };
    std::vector<AbstractConfigType*> getConfigs() {
        return std::vector<AbstractConfigType*>();
    };
};

#endif //AVRDEVICECONTROLLER_UNIXMICROCONTROLLERSOPERATIONSYSTEMPLUGIN_H
