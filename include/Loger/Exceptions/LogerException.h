//
// Created by fakys on 10.10.2026.
//


#include "MainException.h"

class LogerException : public MainException {
public:
    LogerException(std::string message) : MainException(message) {};
};
