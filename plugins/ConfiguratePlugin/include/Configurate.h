//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H
#include "ConfigHttpPort.h"
#include "ConfigLogAcceptPathEntity.h"
#include "ConfigLogErrorPathEntity.h"
#include "ConfigLogLevelEntity.h"

class Configurate {
    private:
        ConfigLogAcceptPathEntity* acceptLogPath;
        ConfigLogErrorPathEntity* errorLogPath;
        ConfigLogLevelEntity* logLevel;
        ConfigHttpPort* httpPort;
    public:
    Configurate(ConfigLogAcceptPathEntity* acceptLogPath, ConfigLogErrorPathEntity* errorLogPath, ConfigLogLevelEntity* logLevel, ConfigHttpPort* configHttpPort) :
    acceptLogPath(acceptLogPath), errorLogPath(errorLogPath), logLevel(logLevel), httpPort(configHttpPort) {};

    ConfigLogAcceptPathEntity* getAcceptLogPath() {return acceptLogPath;};
    ConfigLogErrorPathEntity* getErrorLogPath() {return errorLogPath;};
    ConfigLogLevelEntity* getLogLevel() {return logLevel;};
    ConfigHttpPort* getHttpPort() {return httpPort;};

    ~Configurate() {
        delete acceptLogPath;
        delete errorLogPath;
        delete logLevel;
        delete httpPort;
    };
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
