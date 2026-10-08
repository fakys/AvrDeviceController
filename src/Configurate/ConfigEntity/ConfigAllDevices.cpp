//
// Created by fakys on 07.10.2026.
//

#include "ConfigurateException.h"
#include "../../../../include/Configurate/config_parser_helper.h"
#include "ConfigAllDevices.h"

#include <iostream>

bool ConfigAllDevices::handelRow(std::vector<uint8_t> row) {
    if (fieldCompleted) {
        return false;
    }

    //Если есть не законченный объект, то продолжаем его постройку
    if (this->lastHandelObject && !this->lastHandelObject->isCompleted()) {
        this->lastHandelObject->handelRow(row);
        return true;
    }

    if (objectInArray(row)) {
        this->lastHandelObject = new ConfigDevice();
        this->devices.push_back((ConfigDevice*)this->lastHandelObject);

    } else {
        this->checkCloseArray(row);
    }
    return true;
}
