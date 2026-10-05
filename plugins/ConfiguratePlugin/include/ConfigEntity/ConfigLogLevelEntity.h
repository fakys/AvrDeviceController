#ifndef AVRDEVICECONTROLLER_CONFIGLOGLEVELENTITY_H
#define AVRDEVICECONTROLLER_CONFIGLOGLEVELENTITY_H
#include "AbstractConfigEntity.h"

class ConfigLogLevelEntity : public AbstractConfigEntity {
    public:
    std::string getConfigName() override {
        return "log_level";
    }

    bool requiredField() override {
        return false;
    }

    bool isGroup() override {
        return false;
    }
};

#endif
