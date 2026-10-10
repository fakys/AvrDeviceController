//
// Created by fakys on 10.10.2026.
//

#include "Communications.h"
#include "Kernel.h"


void Communications::sendOutputWarningMessage(std::string message) {
    if (Kernel::getObject()->getLogerService()) {
        Kernel::getObject()->getLogerService()->writeErrorLog("[Warning] "+message);
    }
    this->outputDriver->sendOutputMessage("[Warning] "+message + '\n');
}

void Communications::sendOutputInfoMessage(std::string message) {
    if (Kernel::getObject()->getLogerService()) {
        Kernel::getObject()->getLogerService()->writeAcceptLog("[Info] "+message);
    }
    this->outputDriver->sendOutputMessage("[Info] "+message + '\n');
}

void Communications::sendOutputErrorMessage(std::string message) {
    if (Kernel::getObject()->getLogerService()) {
        Kernel::getObject()->getLogerService()->writeErrorLog("[Error] "+message);
    }
    this->outputDriver->sendOutputMessage("[Error] "+message + '\n');
}
