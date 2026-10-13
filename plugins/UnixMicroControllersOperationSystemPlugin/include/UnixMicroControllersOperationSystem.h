//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_UNIXMICROCONTROLLERSOPERATIONSYSTEM_H
#define AVRDEVICECONTROLLER_UNIXMICROCONTROLLERSOPERATIONSYSTEM_H

#include <string>
#include "AbstractOperationSystem.h"


class UnixMicroControllersOperationSystem : public AbstractOperationSystem {
    public:
        std::string getName() override {
            return "unix_micro_controllers_operation_system";
        }
};

#endif //AVRDEVICECONTROLLER_UNIXMICROCONTROLLERSOPERATIONSYSTEM_H
