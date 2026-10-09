//
// Created by fakys on 01.10.2026.
//


#include "Kernel.h"
Kernel::Kernel() {
    this->pluginLoader = new PluginLoader();
    this->communication = new Communication();
    this->fileController = new FileController();
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

Communication *Kernel::getCommunication() {
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

LogerService* Kernel::getLogerService() {
    return this->logger;
}