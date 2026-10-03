#ifndef AVRDEVICECONTROLLER_CONFIGLOGERRORPATHENTITY_H
#define AVRDEVICECONTROLLER_CONFIGLOGERRORPATHENTITY_H
#include "AbstractConfigEntity.h"

class ConfigLogAcceptPathEntity :public AbstractConfigEntity {
    public:
        std::string getConfigName() override {
            return "accept_log_path";
        }
};

#endif
