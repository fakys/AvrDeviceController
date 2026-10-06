//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H


#include "ObjectConfigFieldType.h"


class Configurate : public ObjectConfigFieldType {
private:
    std::string getConfigName() override {
        return "configurate";
    };
    bool requiredField() {
        return true;
    };
    virtual bool handelField(uint8_t byte) = 0;
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
