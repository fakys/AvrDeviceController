//
// Created by fakys on 06.10.2026.
//
#include "../../include/Configurate/config_parser_helper.h"

#include <iostream>
#include <ostream>
#include "ConfigurateException.h"


bool is_passive_byte(uint8_t byte) {
    std::vector<uint8_t> bytes = PASSIVE_BYTES;
    for (uint8_t passive_byte : bytes) {
        if (passive_byte == byte) {
            return true;
        }
    }

    return false;
}

bool is_active_byte(uint8_t byte) {
    std::vector<uint8_t> bytes = ACTIVE_BYTES;
    for (uint8_t passive_byte : bytes) {
        if (passive_byte == byte) return true;
    }

    return false;
}

std::vector<uint8_t> cut_out_passive_bytes(std::vector<uint8_t> buffer) {
    std::vector<uint8_t> new_buffer;
    for (uint8_t byte : buffer) {
        if (!is_passive_byte(byte)) {
            new_buffer.push_back(byte);
        }
    }
    return new_buffer;
}

bool objectInArray(std::vector<uint8_t> buffer) {
    bool is_object = false;
    std::string str(buffer.begin(), buffer.end());
    for (uint8_t byte : buffer) {
        bool is_active = is_active_byte(byte);

        if (is_active) {
            if (byte == OBJECT_START) {
                is_object = true;
            } else if (byte != ARRAY_END) {
                throw ConfigurateException("Undefined type in array: "+ str);
            }
        } else {
            throw ConfigurateException("Fail property format: "+ str);
        }
    }
    return is_object;
}

//Функция парсит переменную в строке конфига
//todo оставить подробные комментарии как все работает
PropertyParser* propertyParser(std::vector<uint8_t> buffer) {
    std::string property_name = "";
    uint8_t prev_byte = 0;
    bool property_locked = false;
    bool property_created = false;

    auto* property = new PropertyParser();
    std::string str(buffer.begin(), buffer.end());
    for (uint8_t byte : buffer) {
        bool is_active = is_active_byte(byte);
        if (is_active) {
            if (!property_name.empty() && prev_byte == property_name[property_name.length() - 1]) {
                //Если предыдущий байт ушел в переменную а этот нет, закрываем переменную для пополнения
                property_locked = true;
            }
        }


        if (!is_active) {//Если байт не является активным и пассивным = неизвестный байт
            if (property_locked && !property_created) {
                throw ConfigurateException("Fail property format: "+ str);
            } else if (property_locked && property_created) {
                if (byte == STRING_END) {
                    property->propertyName = property_name;
                    property->propertyValueType = PROPERTY_VALUE_STRING_TYPE;
                    return property;
                } else {
                    property->propertyValue += byte;
                    continue;
                }
            }
            property_name += byte;
        } else if (byte == CREATE_PROPERTY) {
            if (property_locked) {
                property_created = true;
            } else {
                throw ConfigurateException("Fail parse config: "+ str);
            }
        } else if (property_created) {
            switch (byte) {
                case OBJECT_START:
                    return new PropertyParser{property_name, PROPERTY_VALUE_OBJECT_TYPE};
                case ARRAY_START:
                    return new PropertyParser{property_name, PROPERTY_VALUE_ARRAY_TYPE};
                case STRING_END:
                    property->propertyName = property_name;
                    property->propertyValueType = PROPERTY_VALUE_STRING_TYPE;
                    return property;
                default:
                    throw ConfigurateException("Undefined property type: "+ str);
            }
        } else if (!property_name.empty()) {
            throw ConfigurateException("Fail parse property name: "+ str);
        }


        prev_byte = byte;
    }
    return nullptr;
}
