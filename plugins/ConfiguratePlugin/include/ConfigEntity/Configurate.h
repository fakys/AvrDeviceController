//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H


#include "ConfigAcceptLogPath.h"
#include "ConfigAllDevices.h"
#include "ObjectConfigFieldType.h"
#include "ConfigErrorLogPath.h"


class Configurate : public ObjectConfigFieldType {
private:
    ConfigErrorLogPath* errorLogPath;
    ConfigAcceptLogPath* acceptLogPath;
    ConfigAllDevices* devices;
public:
    Configurate() = default;
    std::string getConfigName() override {
        return "configurate";
    }

    bool requiredField() override {
        return true;
    }

    bool handelRow(std::vector<uint8_t> row) override;

    std::string getErrorLogPath() {
        return errorLogPath->getValue();
    }

    std::string getAcceptLogPath() {
        return acceptLogPath->getValue();
    }

    std::vector<ConfigDevice*> getDevices() {
        return devices->getDevices();
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
