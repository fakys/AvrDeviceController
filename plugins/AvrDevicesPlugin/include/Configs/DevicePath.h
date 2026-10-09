//
// Created by fakys on 07.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICEPATH_H
#define AVRDEVICECONTROLLER_DEVICEPATH_H

#include "StringConfigFieldType.h"

class DevicePath : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "path";
    }

    bool requiredField() override {
        return true;
    }
};
#endif //AVRDEVICECONTROLLER_DEVICEPATH_H
