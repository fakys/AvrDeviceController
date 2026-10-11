//
// Created by fakys on 12.10.2026.
//

#ifndef AVRDEVICECONTROLLER_PROCESESSTATUSMETHOD_H
#define AVRDEVICECONTROLLER_PROCESESSTATUSMETHOD_H
#include "AbstractHttpMethod.h"
#include "crow.h"

class ProcessStatusMethod : public AbstractHttpMethod {
public:
    void registerMethod(crow::SimpleApp *app) override;
};
#endif //AVRDEVICECONTROLLER_PROCESESSTATUSMETHOD_H
