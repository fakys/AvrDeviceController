//
// Created by fakys on 10.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGLOGLEVEL_H
#define AVRDEVICECONTROLLER_CONFIGLOGLEVEL_H
#include "StringConfigFieldType.h"


class ConfigLogLevel :public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "log_level";
    }

    bool requiredField() override {
        return true;
    }

    std::string getType() {
        return PROPERTY_VALUE_STRING_TYPE;
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGLOGLEVEL_H
