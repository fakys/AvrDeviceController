//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTOUTPUTDRIVER_H
#define AVRDEVICECONTROLLER_ABSTRACTOUTPUTDRIVER_H
#include <string>

class CommunicationOutputDriver {
    public:
    bool sendOutputMessage(std::string message);
};

#endif //AVRDEVICECONTROLLER_ABSTRACTOUTPUTDRIVER_H
