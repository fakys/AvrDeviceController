//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTSTRINGCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_ABSTRACTSTRINGCONFIGFIELDTYPE_H
#include "AbstractConfigType.h"

#include "config_parser_helper.h"

class StringConfigFieldType : public AbstractConfigType {
private:
    std::string value;
public:
    void setValue(const std::string value) {
        this->value = value;
    }
    std::string getValue() {
        return value;
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTSTRINGCONFIGFIELDTYPE_H
