//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_ABSTRACTPLUGIN_H
#define AVR_PROTO_LINUX_ABSTRACTPLUGIN_H
#include "main.h"

class AbstractPlugin {
public:
    virtual std::string getPluginName() = 0;
    virtual std::vector<std::string>* getDependPlugins()=0;
    virtual int pluginLoad() = 0;
};

#endif //AVR_PROTO_LINUX_ABSTRACTPLUGIN_H
