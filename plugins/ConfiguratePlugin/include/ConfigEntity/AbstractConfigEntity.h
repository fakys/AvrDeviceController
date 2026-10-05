//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#define AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#include <string>

class AbstractConfigEntity {
    private:
    std::string value;
    public:
    virtual std::string getConfigName()=0;
    void setValue(std::string v) {
        this->value = v;
    }

    std::string getValue() {
        return value;
    }

    virtual bool requiredField() = 0;
    virtual bool isGroup() = 0;

    virtual ~AbstractConfigEntity()=default;
};

#endif //AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
