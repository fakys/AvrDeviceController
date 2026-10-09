//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
#include "AbstractParentConfigField.h"
#include "config_parser_helper.h"
#include "ConfigurateException.h"

#define OBJECT_TYPE "object"

class ObjectConfigFieldType : public AbstractParentConfigField {
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
public:
    std::string getType() {
        return OBJECT_TYPE;
    };
};

#endif //AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
