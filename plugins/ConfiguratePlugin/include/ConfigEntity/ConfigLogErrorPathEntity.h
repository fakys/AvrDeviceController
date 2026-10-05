#ifndef AVRDEVICECONTROLLER_CONFIGERRORLOGERRORPATHENTITY_H
#define AVRDEVICECONTROLLER_CONFIGERRORLOGERRORPATHENTITY_H

#include "AbstractConfigEntity.h"

class ConfigLogErrorPathEntity :public AbstractConfigEntity {
    public:
        std::string getConfigName() override {
            return "error_log_path";
        }

        bool requiredField() override {
            return true;
        }
};


#endif
