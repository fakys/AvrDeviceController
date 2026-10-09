//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGERRORLOGPATH_H
#define AVRDEVICECONTROLLER_CONFIGERRORLOGPATH_H
#include "StringConfigFieldType.h"


class ConfigErrorLogPath : public StringConfigFieldType {
    public:
    std::string getConfigName() override {
        return "error_log_path";
    }

    bool requiredField() override {
        return true;
    }

    std::string getType() {
        return PROPERTY_VALUE_STRING_TYPE;
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGERRORLOGPATH_H
