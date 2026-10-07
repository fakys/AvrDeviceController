//
// Created by fakys on 07.10.2026.
//

#include "ConfigurateException.h"
#include "config_parser_helper.h"
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
        std::string str(row.begin(), row.end());
        for (uint8_t byte : row) {
            if (byte == ARRAY_END) {
                fieldCompleted = true;
            }else if (!is_passive_byte(byte)) {
                throw ConfigurateException("Fail parse config: "+ str);
            }
        }
    }
    return true;
}
