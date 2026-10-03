//
// Created by fakys on 01.10.2026.
//


#include "Kernel.h"
Kernel::Kernel() {
    this->processManager = new ProcessManager();
    this->pluginLoader = new PluginLoader();
    this->communication = new Communication();
}

PluginLoader *Kernel::getPluginLoader() {
    return this->pluginLoader;
}

ProcessManager *Kernel::getProcessManager() {
    return this->processManager;
}

void Kernel::handleArguments(int argc, char* argv[]) {
    this->processArgument = new ProcessArgument(argc, argv);
}

ProcessArgument *Kernel::getProcessArgument() {
    return this->processArgument;
}

Communication *Kernel::getCommunication() {
    return this->communication;
}
