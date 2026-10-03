//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGPATHARG_H
#define AVRDEVICECONTROLLER_CONFIGPATHARG_H

#include "AbstractArgType.h"

class ConfigPathArg : public AbstractArgType
{
    public:
        std::string getArgName() override {
            return "config_path";
        }
        std::string getAbbreviation() override {
            return "conf";
        }
        bool argumentHasValue() override {
            return true;
        }
        ~ConfigPathArg() override = default;
};

#endif //AVRDEVICECONTROLLER_CONFIGPATHARG_H
