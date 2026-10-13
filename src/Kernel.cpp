//
// Created by fakys on 01.10.2026.
//


#include "Kernel.h"
#include <unistd.h>

Kernel::Kernel() {
    this->pluginLoader = new PluginLoader();
    this->communication = new Communications();
    this->fileController = new FileController();
    this->taskManager = new TaskManager();
    this->deviceManager = new DeviceManager();
    this->operationSystemsManager = new OperationSystemsManager();
    this->protocolsManager = new ProtocolsManager();
}

PluginLoader *Kernel::getPluginLoader() {
    return this->pluginLoader;
}

void Kernel::handleArguments(int argc, char* argv[]) {
    this->processArgument = new ProcessArgument(argc, argv);
}

ProcessArgument *Kernel::getProcessArgument() {
    return this->processArgument;
}

Communications *Kernel::getCommunication() {
    return this->communication;
}

void Kernel::initConfig() {
    this->configLoader = new ConfigurateLoader();
    this->configLoader->checkConfig();
}

ConfigurateLoader* Kernel::getConfigLoader() {
    return this->configLoader;
}

void Kernel::loadConfig() {
    this->configurate = this->configLoader->loadConfig();
}

FileController *Kernel::getFileController() {
    return this->fileController;
}
Configurate* Kernel::getConfigurate() {
    return this->configurate;
}
void Kernel::initLogerService() {
    this->logger = new LogerService();
}
LogerService* Kernel::getLogerService() {
    return this->logger;
}

void Kernel::initProcessManager() {
    if (this->processManager) {
        delete this->processManager;
    }
    this->processManager = new ProcessManager(getpid());
}

ProcessManager* Kernel::getProcessManager() {
    return this->processManager;
}


TaskManager* Kernel::getTaskManager() {
    return this->taskManager;
}

DeviceManager* Kernel::getDeviceManager() {
    return this->deviceManager;
}

ProtocolsManager *Kernel::getProtocolsManager() {
    return this->protocolsManager;
}

OperationSystemsManager *Kernel::getOperationSystemsManager() {
    return this->operationSystemsManager;
}
