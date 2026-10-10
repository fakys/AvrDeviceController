//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_KERNEL_H
#define AVR_PROTO_LINUX_KERNEL_H

#include <string>

#include "Communications.h"
#include "ConfigurateLoader.h"
#include "FileController.h"
#include "PluginLoader.h"
#include "Singleton.h"
#include "ProcessArgument.h"
#include "LogerService.h"

class Kernel : public Singleton<Kernel> {
    private:
        ProcessArgument* processArgument;
        Communications *communication;
        FileController* fileController;
        Configurate* configurate;
        ConfigurateLoader* configLoader;
        LogerService* logger;
        PluginLoader* pluginLoader;
    public:
    Kernel();
    PluginLoader* getPluginLoader();
    void handleArguments(int argc, char* argv[]);
    ProcessArgument* getProcessArgument();
    Communications* getCommunication();
    FileController* getFileController();
    void initConfig();
    ConfigurateLoader* getConfigLoader();
    void loadConfig();
    void initLogerService();
    Configurate* getConfigurate();
    LogerService* getLogerService();
};

#endif //AVR_PROTO_LINUX_KERNEL_H
