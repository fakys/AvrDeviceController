//
// Created by fakys on 01.10.2026.
//


#include "Kernel.h"
Kernel::Kernel() {
    this->processManager = new ProcessManager();
    this->pluginLoader = new PluginLoader();
}

PluginLoader *Kernel::getPluginLoader() {
    return this->pluginLoader;
}

ProcessManager *Kernel::getProcessManager() {
    return this->processManager;
}
