//
// Created by fakys on 09.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTPARENTCONFIGFIELD_H
#define AVRDEVICECONTROLLER_ABSTRACTPARENTCONFIGFIELD_H
#include "AbstractConfigType.h"
#include "ConfigurateException.h"

#include "config_parser_helper.h"
#include "StringConfigFieldType.h"

class AbstractParentConfigField :public AbstractConfigType {
    protected:
        AbstractParentConfigField* lastHandelObject = nullptr;
        std::vector<AbstractConfigType*> childs;

    bool checkCloseParent(std::vector<uint8_t> row);
    public:
    bool checkFieldByName(std::string name) {
        for (auto field : childs) {
            if (field->getConfigName() == name) {
                return true;
            }
        }
        return false;
    }

    bool handelRow(std::vector<uint8_t> row);

    AbstractConfigType* getFieldByName(std::string name) {
        for (auto field : childs) {
            if (field->getConfigName() == name) {
                return field;
            }
        }
        throw ConfigurateException("Config field not found: "+name);
    };
};

#endif //AVRDEVICECONTROLLER_ABSTRACTPARENTCONFIGFIELD_H
