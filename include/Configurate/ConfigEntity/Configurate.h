//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H


#include "ObjectConfigFieldType.h"
#include <iostream>

class Configurate : public ObjectConfigFieldType {
public:
    Configurate(std::vector<AbstractConfigType*> childs) {
        this->childs = childs;
    };

    std::string getConfigName() override {
        return "configurate";
    }

    bool requiredField() override {
        return true;
    }
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
