//
// Created by fakys on 12.10.2026.
//

#ifndef AVRDEVICECONTROLLER_PINGMETHOD_H
#define AVRDEVICECONTROLLER_PINGMETHOD_H

#include "crow.h"
#include "AbstractHttpMethod.h"

class PingMethod : public AbstractHttpMethod {
public:
    void registerMethod(crow::SimpleApp* app) override {
        CROW_ROUTE((*app), "/ping")([]() {
            return "PONG";
        });
    };
};

#endif //AVRDEVICECONTROLLER_PINGMETHOD_H
