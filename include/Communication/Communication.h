//
// Created by fakys on 03.10.2026.
//

#ifndef AVRDEVICECONTROLLER_COMMUNICATION_H
#define AVRDEVICECONTROLLER_COMMUNICATION_H
#include "CommunicationInputDriver.h"
#include "CommunicationOutputDriver.h"

class Communication {
    private:
        CommunicationInputDriver *inputDriver;
        CommunicationOutputDriver *outputDriver;
    public:
    Communication() {
        this->inputDriver = new CommunicationInputDriver();
        this->outputDriver = new CommunicationOutputDriver();
    }

    void sendOutputWarningMessage(std::string message) {
        this->outputDriver->sendOutputMessage("[Warning] "+message + '\n');
    }

    void sendOutputErrorMessage(std::string message) {
        this->outputDriver->sendOutputMessage("[Error] "+message + '\n');
    }

    void sendOutputInfoMessage(std::string message) {
        this->outputDriver->sendOutputMessage("[Info] "+message + '\n');
    }

    CommunicationInputDriver *getInputDriver() {
        return inputDriver;
    }

    CommunicationOutputDriver *getOutputDriver() {
        return outputDriver;
    }
};

#endif //AVRDEVICECONTROLLER_COMMUNICATION_H
