//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#define AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
#include <string>
#include <cstdint>
#include <vector>

class AbstractConfigType {
    protected:
        bool fieldCompleted = false;
        AbstractConfigType* lastHandelObject = nullptr;
    public:
    virtual std::string getConfigName()=0;
    virtual bool requiredField() = 0;
    virtual bool handelRow(std::vector<uint8_t> row) = 0;

    bool isCompleted() {
        return fieldCompleted;
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTCONFIGENTITY_H
