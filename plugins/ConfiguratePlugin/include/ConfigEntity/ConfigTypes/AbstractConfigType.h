//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#define AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#include <string>
#include <cstdint>

class AbstractConfigType {
    private:
        bool fieldCompleted = false;
    public:
    virtual std::string getConfigName()=0;
    virtual bool requiredField() = 0;
    virtual bool handelField(uint8_t byte) = 0;

    bool isCompleted() {
        return fieldCompleted;
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
