//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPWORKERCOUNT_H
#define AVRDEVICECONTROLLER_HTTPWORKERCOUNT_H
#include "StringConfigFieldType.h"

class HttpWorkerCount : public StringConfigFieldType {
    public:
    std::string getConfigName() override {
        return "http_worker_count";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_HTTPWORKERCOUNT_H
