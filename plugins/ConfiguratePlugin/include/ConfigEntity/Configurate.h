//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATE_H
#define AVRDEVICECONTROLLER_CONFIGURATE_H


#include "ObjectConfigFieldType.h"


class Configurate : public ObjectConfigFieldType {
public:
    Configurate() = default;
    std::string getConfigName() override {
        return "configurate";
    }

    bool requiredField() override {
        return true;
    }

    bool handelRow(std::vector<uint8_t> row) override;
};

#endif //AVRDEVICECONTROLLER_CONFIGURATE_H
