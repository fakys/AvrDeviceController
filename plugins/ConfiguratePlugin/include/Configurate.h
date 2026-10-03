//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H
#include "ConfigLogAcceptPathEntity.h"
#include "ConfigLogErrorPathEntity.h"

class Configurate {
    private:
        ConfigLogAcceptPathEntity* acceptLogPath;
        ConfigLogErrorPathEntity* errorLogPath;
    public:
    Configurate(ConfigLogAcceptPathEntity* acceptLogPath, ConfigLogErrorPathEntity* errorLogPath) : acceptLogPath(acceptLogPath), errorLogPath(errorLogPath) {};

    ConfigLogAcceptPathEntity* getAcceptLogPath() {return acceptLogPath;};
    ConfigLogErrorPathEntity* getErrorLogPath() {return errorLogPath;};

    ~Configurate() {
        delete acceptLogPath;
        delete errorLogPath;
    };
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
