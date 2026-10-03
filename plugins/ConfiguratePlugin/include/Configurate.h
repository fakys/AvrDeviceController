//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H
#include "ConfigLogAcceptPathEntity.h"
#include "ConfigLogErrorPathEntity.h"
#include "ConfigLogLevelEntity.h"

class Configurate {
    private:
        ConfigLogAcceptPathEntity* acceptLogPath;
        ConfigLogErrorPathEntity* errorLogPath;
        ConfigLogLevelEntity* logLevel;
    public:
    Configurate(ConfigLogAcceptPathEntity* acceptLogPath, ConfigLogErrorPathEntity* errorLogPath, ConfigLogLevelEntity* logLevel) :
    acceptLogPath(acceptLogPath), errorLogPath(errorLogPath), logLevel(logLevel) {};

    ConfigLogAcceptPathEntity* getAcceptLogPath() {return acceptLogPath;};
    ConfigLogErrorPathEntity* getErrorLogPath() {return errorLogPath;};
    ConfigLogLevelEntity* getLogLevel() {return logLevel;};

    ~Configurate() {
        delete acceptLogPath;
        delete errorLogPath;
        delete logLevel;
    };
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
