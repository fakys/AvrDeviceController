//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#define AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#include <string>

class AbstractConfigType {
    protected:
        bool fieldCompleted = false;
    public:
    virtual std::string getConfigName()=0;
    virtual std::string getType() = 0;
    virtual bool requiredField() = 0;

    bool isCompleted() {
        return fieldCompleted;
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
