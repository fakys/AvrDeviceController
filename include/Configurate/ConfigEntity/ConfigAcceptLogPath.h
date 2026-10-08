//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGACCEPTLOGPATH_H
#define AVRDEVICECONTROLLER_CONFIGACCEPTLOGPATH_H
#include "StringConfigFieldType.h"

class ConfigAcceptLogPath : public StringConfigFieldType {
public:
    ConfigAcceptLogPath(std::string value) : StringConfigFieldType(value) {}

    std::string getConfigName() override {
        return "accept_log_path";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGACCEPTLOGPATH_H
