//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_UARTPROTOPLUGIN_H
#define AVRDEVICECONTROLLER_UARTPROTOPLUGIN_H

#include "AbstractPlugin.h"
#include "Kernel.h"
#include "UartProto.h"

class UartProtoPlugin : public AbstractPlugin {
public:

    std::string getPluginName() {
        return "UartProtoPlugin";
    };

    std::vector<std::string>* getDependPlugins() {
        return new std::vector<std::string>{};
    };

    int pluginLoad() {
        Kernel::getObject()->getProtocolsManager()->registerProtocol(
            new UartProto()
        );
        return 0;
    };
    std::vector<AbstractConfigType*> getConfigs() {
        return std::vector<AbstractConfigType*>();
    };
};

#endif //AVRDEVICECONTROLLER_UARTPROTOPLUGIN_H
