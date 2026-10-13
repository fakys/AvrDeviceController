//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_DEVICEPROTO_H
#define AVRDEVICECONTROLLER_DEVICEPROTO_H
#include "StringConfigFieldType.h"


#define DEVICE_PROTO_FIELD "proto"

class DeviceProto : public StringConfigFieldType {
public:
    std::string getConfigName() override {
        return "proto";
    }

    bool requiredField() override {
        return true;
    }
};
#endif //AVRDEVICECONTROLLER_DEVICEPROTO_H
