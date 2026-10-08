//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ARRAYCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_ARRAYCONFIGFIELDTYPE_H

#include "AbstractConfigType.h"
#include "config_parser_helper.h"
#include "ConfigurateException.h"

class ArrayConfigFieldType : public AbstractConfigType {
protected:
    bool checkCloseArray(std::vector<uint8_t> row) {
        std::string str(row.begin(), row.end());
        for (uint8_t byte : row) {
            if (byte == ARRAY_END) {
                fieldCompleted = true;
            }else {
                throw ConfigurateException("Fail parse config: "+ str);
            }
        }
        return fieldCompleted;
    }
};

#endif //AVRDEVICECONTROLLER_ARRAYCONFIGFIELDTYPE_H
