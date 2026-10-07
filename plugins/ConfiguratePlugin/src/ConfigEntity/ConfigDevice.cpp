//
// Created by fakys on 07.10.2026.
//
#include "ConfigDevice.h"

#include <iostream>

#include "config_parser_helper.h"
#include "ConfigurateException.h"

bool ConfigDevice::handelRow(std::vector<uint8_t> row) {

    PropertyParser* property = propertyParser(row);
    if (property) {//Ищем переменную с массивами или значениями
        if (property->propertyValueType == PROPERTY_VALUE_STRING_TYPE) {
            if (property->propertyName == "name") {
                this->deviceName = new DeviceName(property->propertyValue);
            } else if (property->propertyName == "type") {
                this->deviceType = new DeviceType(property->propertyValue);
            } else if (property->propertyName == "path") {
                this->devicePath = new DevicePath(property->propertyValue);
            }else {
                throw ConfigurateException("Unsupported property name in "+this->getConfigName());
            }
        } else {
            throw ConfigurateException("Unsupported property type in "+this->getConfigName());
        }
    } else {
        std::string str(row.begin(), row.end());
        for (uint8_t byte : row) {
            if (byte == OBJECT_END) {
                if (!this->deviceName || this->deviceName->getValue().empty()) {
                    throw ConfigurateException("Undefined required field in devices: name");
                } else if (!this->deviceType || this->deviceType->getValue().empty()) {
                    throw ConfigurateException("Undefined required field in devices: type");
                } else if (!this->devicePath || this->devicePath->getValue().empty()) { //todo пофакту это только для uart
                    throw ConfigurateException("Undefined required field in devices: path");
                }

                if (this->deviceType->getValue() != UART_TYPE) {
                    throw ConfigurateException("Unsupported device type: "+this->getConfigName());
                }

                fieldCompleted = true;
            }else if (!is_passive_byte(byte)) {
                throw ConfigurateException("Fail parse config: "+ str);
            }
        }
    }
    return true;
}