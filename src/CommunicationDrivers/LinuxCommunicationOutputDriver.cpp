//
// Created by fakys on 03.10.2026.
//


#include <unistd.h>

#include "CommunicationOutputDriver.h"

bool CommunicationOutputDriver::sendOutputMessage(std::string message) {
    write(1, &message[0], message.size());
    return true;
}
