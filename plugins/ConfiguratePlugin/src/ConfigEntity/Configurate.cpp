//
// Created by fakys on 06.10.2026.
//

#include "Configurate.h"

#include <iostream>
#include <ostream>

#include "config_parser_helper.h"
#include "ConfigurateException.h"



bool Configurate::handelRow(std::vector<uint8_t> row) {
    PropertyParser* property = propertyParser(row);
    if (property) {
        std::cout << property->propertyName << std::endl;
    } else {
        std::string str(row.begin(), row.end());
        for (uint8_t byte : row) {
            if (!is_passive_byte(byte)) {
                throw ConfigurateException("Fail parse config: "+ str);
            }
        }
    }
    return true;
}
