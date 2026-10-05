//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGHTTPPORT_H
#define AVRDEVICECONTROLLER_CONFIGHTTPPORT_H

#include "AbstractConfigEntity.h"

class ConfigHttpPort :public AbstractConfigEntity {
public:
    std::string getConfigName() override {
        return "http_port";
    }
    bool requiredField() override {
        return true;
    }

    bool isGroup() override {
        return false;
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGHTTPPORT_H
