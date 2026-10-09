//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ARRAYCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_ARRAYCONFIGFIELDTYPE_H

#include "AbstractParentConfigField.h"
#include "config_parser_helper.h"
#include "ConfigurateException.h"

#define ARRAY_TYPE "array"

class ArrayConfigFieldType : public AbstractParentConfigField {
private:
    std::vector<AbstractParentConfigField*> array;
public:
    virtual AbstractParentConfigField* createChildConf() = 0;
    void appendChild(AbstractParentConfigField* child) {
        array.push_back(child);
    }
    bool handelRow(std::vector<uint8_t> row);
    std::string getType() {
        return ARRAY_TYPE;
    };
};

#endif //AVRDEVICECONTROLLER_ARRAYCONFIGFIELDTYPE_H
