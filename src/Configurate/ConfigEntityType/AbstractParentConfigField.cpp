//
// Created by fakys on 09.10.2026.
//

#include "AbstractParentConfigField.h"

#include <iostream>

bool AbstractParentConfigField::checkCloseParent(std::vector<uint8_t> row) {
    std::string str(row.begin(), row.end());
    for (uint8_t byte : row) {
        if (byte == ARRAY_END) {
            fieldCompleted = true;
        }else {
            throw ConfigurateException("Fail parse config: "+ str);
        }
    }
    return fieldCompleted;
}

bool AbstractParentConfigField::handelRow(std::vector<uint8_t> row) {
    if (fieldCompleted) {
        return false;
    }

    //Если есть не законченный объект, то продолжаем его постройку
    if (this->lastHandelObject && !this->lastHandelObject->isCompleted()) {
        this->lastHandelObject->handelRow(row);
        return true;
    }

    PropertyParser* property = propertyParser(row);
    if (property) { //Ищем переменную с массивами или значениями
        if (!this->checkFieldByName(property->propertyName)) {
            throw ConfigurateException("Unsupported property name in "+this->getConfigName() + " name = "+property->propertyName);
        }
        if (property->propertyValueType == PROPERTY_VALUE_STRING_TYPE) {
            StringConfigFieldType* stringField = (StringConfigFieldType*)this->getFieldByName(property->propertyName);
            stringField->setValue(property->propertyValue);
        } else if (property->propertyValueType == PROPERTY_VALUE_OBJECT_TYPE) {
            AbstractConfigType* field = this->getFieldByName(property->propertyName);
            if (field->getType() == PROPERTY_VALUE_ARRAY_TYPE || field->getType() == PROPERTY_VALUE_OBJECT_TYPE) {
                this->lastHandelObject = (AbstractParentConfigField*)this->getFieldByName(property->propertyName);
            } else {
                throw ConfigurateException("Unsupported property type in "+this->getConfigName());
            }
        } else {
            throw ConfigurateException("Unsupported property type in "+this->getConfigName());
        }
        delete property;
    } else {
        this->checkCloseParent(row);
    }
    if (fieldCompleted) {
        return false;
    }

    return true;
}