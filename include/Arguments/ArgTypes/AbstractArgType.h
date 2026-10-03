//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTARGTYPE_H
#define AVRDEVICECONTROLLER_ABSTRACTARGTYPE_H
#include <string>

class AbstractArgType {
    private:
        std::string value;
    public:
        virtual std::string getArgName() = 0;
        virtual std::string getAbbreviation() = 0;
        virtual bool argumentHasValue() = 0;
        std::string getValue() {
            return value;
        }
        void setValue(std::string value) {
            this->value = value;
        }

        virtual ~AbstractArgType() = default;
};

#endif //AVRDEVICECONTROLLER_ABSTRACTARGTYPE_H
