//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_KERNEL_H
#define AVR_PROTO_LINUX_KERNEL_H

#include <string>

#include "PluginLoader.h"
#include "ProcessManager.h"
#include "Patterns/Singleton.h"

class Kernel : public Singleton<Kernel> {
    private:
        ProcessManager* processManager;
        PluginLoader* pluginLoader;
    public:
    Kernel();
    ProcessManager* getProcessManager();
    PluginLoader* getPluginLoader();

};

#endif //AVR_PROTO_LINUX_KERNEL_H
