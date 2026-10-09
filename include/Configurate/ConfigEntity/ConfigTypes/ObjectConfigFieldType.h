//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
#define AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
#include "AbstractParentConfigField.h"
#include "config_parser_helper.h"

#define OBJECT_TYPE "object"

class ObjectConfigFieldType : public AbstractParentConfigField {
public:
    std::string getType() {
        return OBJECT_TYPE;
    };
};

#endif //AVRDEVICECONTROLLER_OBJECTCONFIGFIELDTYPE_H
