//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTSTRINGCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_ABSTRACTSTRINGCONFIGFIELDTYPE_H
#include "AbstractConfigType.h"

class StringConfigFieldType : public AbstractConfigType {
private:
    std::string value;
public:
    StringConfigFieldType(std::string value) : value(value) {};


    std::string getValue() {
        return value;
    }

    bool handelRow(std::vector<uint8_t> row) {
        for (uint8_t byte : row) {
            value += byte;
        }
        return true;
    };
};

#endif //AVRDEVICECONTROLLER_ABSTRACTSTRINGCONFIGFIELDTYPE_H
