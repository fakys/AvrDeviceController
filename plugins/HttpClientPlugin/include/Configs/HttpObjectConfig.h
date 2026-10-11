//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPOBJECTCONFIG_H
#define AVRDEVICECONTROLLER_HTTPOBJECTCONFIG_H
#include "HttpPortConfig.h"
#include "HttpWorkerCount.h"
#include "ObjectConfigFieldType.h"

class HttpObjectConfig : public ObjectConfigFieldType {
public:
    HttpObjectConfig() {
        this->childs = std::vector<AbstractConfigType*> {
            new HttpPortConfig(),
            new HttpWorkerCount(),
        };
    }
    std::string getConfigName() override {
        return "http";
    };

    bool requiredField() override {
        return false;
    };
};

#endif //AVRDEVICECONTROLLER_HTTPOBJECTCONFIG_H
