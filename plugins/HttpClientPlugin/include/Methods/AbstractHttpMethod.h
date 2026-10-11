//
// Created by fakys on 12.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTHTTPMETHOD_H
#define AVRDEVICECONTROLLER_ABSTRACTHTTPMETHOD_H

#include "crow.h"

class AbstractHttpMethod {
    public:
        virtual void registerMethod(crow::SimpleApp* app) = 0;
};

#endif //AVRDEVICECONTROLLER_ABSTRACTHTTPMETHOD_H
