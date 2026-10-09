//
// Created by fakys on 09.10.2026.
//


#include "ArrayConfigFieldType.h"

#include <iostream>


bool ArrayConfigFieldType::handelRow(std::vector<uint8_t> row) {
    if (fieldCompleted) {
        return false;
    }

    //Если есть не законченный объект, то продолжаем его постройку
    if (this->lastHandelObject && !this->lastHandelObject->isCompleted()) {
        if (this->lastHandelObject->getType() == PROPERTY_VALUE_ARRAY_TYPE) {
            auto* lastHand = (ArrayConfigFieldType*)this->lastHandelObject;
            lastHand->handelRow(row);
            return true;

        }
        this->lastHandelObject->handelRow(row);
        return true;
    }

    if (objectInArray(row)) {
        this->lastHandelObject = this->createChildConf();
        this->appendChild(this->lastHandelObject);

    } else {
        this->checkCloseParent(row);
    }
    return true;
}
