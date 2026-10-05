//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_KERNEL_H
#define AVR_PROTO_LINUX_KERNEL_H

#include <string>

#include "Communication.h"
#include "PluginLoader.h"
#include "Singleton.h"
#include "ProcessArgument.h"

class Kernel : public Singleton<Kernel> {
    private:
        PluginLoader* pluginLoader;
        ProcessArgument* processArgument;
        Communication *communication;
    public:
    Kernel();
    PluginLoader* getPluginLoader();
    void handleArguments(int argc, char* argv[]);
    ProcessArgument* getProcessArgument();
    Communication* getCommunication();
};

#endif //AVR_PROTO_LINUX_KERNEL_H
