//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
#include "AbstractConfigType.h"
#include "config_parser_helper.h"
#include "ConfigurateException.h"

class ObjectConfigFieldType : public AbstractConfigType {
protected:
    bool checkCloseObject(std::vector<uint8_t> row) {
        std::string str(row.begin(), row.end());
        for (uint8_t byte : row) {
            if (byte == OBJECT_END) {
                fieldCompleted = true;
            }else {
                throw ConfigurateException("Fail parse config: "+ str);
            }
        }

        return fieldCompleted;
    }

};

#endif //AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
