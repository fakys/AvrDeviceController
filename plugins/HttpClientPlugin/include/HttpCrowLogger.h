//
// Created by fakys on 12.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPCROWLOGGER_H
#define AVRDEVICECONTROLLER_HTTPCROWLOGGER_H

#include "crow.h"

class HttpCrowLogger : public crow::ILogHandler {
public:
    void log(const std::string& message, crow::LogLevel level) override {
        switch (level)
        {
            case crow::LogLevel::Debug:
            case crow::LogLevel::Info:
                Kernel::getObject()->getCommunication()->sendOutputInfoMessage(message);
                break;
            case crow::LogLevel::Warning:
                Kernel::getObject()->getCommunication()->sendOutputWarningMessage(message);
                break;
            case crow::LogLevel::Error:
            case crow::LogLevel::Critical:
                Kernel::getObject()->getCommunication()->sendOutputErrorMessage(message);
                break;
        }
    }
};

#endif //AVRDEVICECONTROLLER_HTTPCROWLOGGER_H
