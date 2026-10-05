//
// Created by fakys on 06.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTCONFIGGROUPENTITY_H
#define AVRDEVICECONTROLLER_ABSTRACTCONFIGGROUPENTITY_H

#include <vector>

#include "AbstractConfigEntity.h"

class AbstractConfigGroupEntity : public AbstractConfigEntity {
private:
    std::vector<AbstractConfigEntity*> value;
    std::vector<AbstractConfigGroupEntity*> groups;
public:
    virtual std::string getConfigName()=0;

    void setValue(std::vector<AbstractConfigEntity*>&& v) {
        this->value = std::move(v);
    }

    void appendValue(AbstractConfigEntity* v) {
        value.push_back(v);
    }

    void setGroups(std::vector<AbstractConfigGroupEntity*>&& v) {
        this->groups = std::move(v);
    }

    void appendGroup(AbstractConfigGroupEntity* v) {
        groups.push_back(v);
    }

    std::vector<AbstractConfigEntity*> getValue() {
        return value;
    }

    bool isGroup() override {
        return true;
    };

    virtual bool isArrayGroup() = 0;
};

#endif //AVRDEVICECONTROLLER_ABSTRACTCONFIGGROUPENTITY_H
