//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIG_PARSER_H
#define AVRDEVICECONTROLLER_CONFIG_PARSER_H
#include <string>
#include <vector>
#include <cstdint>


#define OBJECT_START '{'
#define OBJECT_END '}'
#define ARRAY_START '['
#define ARRAY_END ']'
#define STRING_END ';'
#define CREATE_PROPERTY '='
#define PASSIVE_BYTES {' ', '\n'}
#define ACTIVE_BYTES {OBJECT_START, OBJECT_END, ARRAY_START, ARRAY_END, STRING_END, CREATE_PROPERTY}

#define PROPERTY_VALUE_OBJECT_TYPE "object"
#define PROPERTY_VALUE_ARRAY_TYPE "array"
#define PROPERTY_VALUE_STRING_TYPE "string"

struct PropertyParser {
    public:
        std::string propertyName;
        std::string propertyValueType;
};

PropertyParser* propertyParser(std::vector<uint8_t> buffer);

#endif //AVRDEVICECONTROLLER_CONFIG_PARSER_H
