//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_COMMUNICATION_H
#define AVRDEVICECONTROLLER_COMMUNICATION_H
#include "CommunicationInputDriver.h"
#include "CommunicationOutputDriver.h"

class Communications {
    private:
        CommunicationInputDriver *inputDriver;
        CommunicationOutputDriver *outputDriver;
    public:
    Communications() {
        this->inputDriver = new CommunicationInputDriver();
        this->outputDriver = new CommunicationOutputDriver();
    }

    void sendOutputWarningMessage(std::string message);

    void sendOutputErrorMessage(std::string message);

    void sendOutputInfoMessage(std::string message);

    CommunicationInputDriver *getInputDriver() {
        return inputDriver;
    }

    CommunicationOutputDriver *getOutputDriver() {
        return outputDriver;
    }
};

#endif //AVRDEVICECONTROLLER_COMMUNICATION_H
