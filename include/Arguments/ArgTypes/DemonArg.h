//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEMONARG_H
#define AVRDEVICECONTROLLER_DEMONARG_H

#include "AbstractArgType.h"

class DemonArg : public AbstractArgType
{
public:
    std::string getArgName() override {
        return "demon";
    }
    std::string getAbbreviation() override {
        return "d";
    }
    bool argumentHasValue() override {
        return false;
    }
};

#endif //AVRDEVICECONTROLLER_DEMONARG_H
