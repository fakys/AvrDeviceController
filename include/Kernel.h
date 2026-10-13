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
#include "TaskManager.h"
#include "ProcessManager.h"
#include "DeviceManager.h"
#include "OperationSystemsManager.h"
#include "ProtocolsManager.h"

class Kernel : public Singleton<Kernel> {
    private:
        ProcessArgument* processArgument;
        Communications *communication;
        FileController* fileController;
        Configurate* configurate;
        ConfigurateLoader* configLoader;
        LogerService* logger = nullptr;
        PluginLoader* pluginLoader;
        ProcessManager* processManager = nullptr;
        TaskManager* taskManager;
        DeviceManager* deviceManager;
        OperationSystemsManager* operationSystemsManager;
        ProtocolsManager* protocolsManager;
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
    void initProcessManager();
    ProcessManager* getProcessManager();
    TaskManager* getTaskManager();
    DeviceManager* getDeviceManager();
    OperationSystemsManager* getOperationSystemsManager();
    ProtocolsManager* getProtocolsManager();
};

#endif //AVR_PROTO_LINUX_KERNEL_H
