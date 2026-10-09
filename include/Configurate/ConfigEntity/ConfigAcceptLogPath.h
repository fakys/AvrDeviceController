//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGACCEPTLOGPATH_H
#define AVRDEVICECONTROLLER_CONFIGACCEPTLOGPATH_H
#include "StringConfigFieldType.h"

#define ACCEPT_LOG_PATH "accept_log_path"

class ConfigAcceptLogPath : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return ACCEPT_LOG_PATH;
    }

    bool requiredField() override {
        return true;
    }

    std::string getType() {
        return PROPERTY_VALUE_STRING_TYPE;
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGACCEPTLOGPATH_H
