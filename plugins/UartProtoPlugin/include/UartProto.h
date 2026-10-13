//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_UARTPROTO_H
#define AVRDEVICECONTROLLER_UARTPROTO_H
#include <string>

#include "AbstractDeviceProto.h"

class UartProto : public AbstractDeviceProto {
public:
    std::string getName() override {
        return "uart_proto";
    }
};

#endif //AVRDEVICECONTROLLER_UARTPROTO_H
