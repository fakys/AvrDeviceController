//
// Created by fakys on 06.10.2026.
//

#include "Configurate.h"

#include <iostream>

#include "config_parser_helper.h"
#include "ConfigurateException.h"



bool Configurate::handelRow(std::vector<uint8_t> row) {
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
        if (property->propertyValueType == PROPERTY_VALUE_STRING_TYPE) {
            if (property->propertyName == "error_log_path") {
                this->errorLogPath = new ConfigErrorLogPath(property->propertyValue);
            } else if (property->propertyName == "accept_log_path") {
                this->acceptLogPath = new ConfigAcceptLogPath(property->propertyValue);
            } else {
                throw ConfigurateException("Unsupported property name in "+this->getConfigName());
            }
        } else if (property->propertyValueType == PROPERTY_VALUE_ARRAY_TYPE) {
            if (property->propertyName == "devices") {
                this->devices = new ConfigAllDevices();
                this->lastHandelObject = this->devices;
            } else {
                throw ConfigurateException("Unsupported property name in "+this->getConfigName());
            }
        } else {
            throw ConfigurateException("Unsupported property type in "+this->getConfigName());
        }
        delete property;
    } else {
        if (this->checkCloseObject(row)) {
            if (!this->acceptLogPath) {
                throw ConfigurateException("Undefined required field: accept_log_path");
            } else if (!this->errorLogPath) {
                throw ConfigurateException("Undefined required field: error_log_path");
            }
        }
    }
    if (fieldCompleted) {
        return false;
    }

    return true;
}
