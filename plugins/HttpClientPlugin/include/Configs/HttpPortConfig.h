//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPPORTCONFIG_H
#define AVRDEVICECONTROLLER_HTTPPORTCONFIG_H
#include "StringConfigFieldType.h"

class HttpPortConfig : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "http_port";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_HTTPPORTCONFIG_H
