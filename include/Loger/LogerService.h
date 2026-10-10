//
// Created by fakys on 09.10.2026.
//

#ifndef AVRDEVICECONTROLLER_LOGERSERVICE_H
#define AVRDEVICECONTROLLER_LOGERSERVICE_H
#include "FileEntity.h"

#define LOG_LEVEL_NONE "none" // Нет логов
#define LOG_LEVEL_ONLY_ERRORS "only_errors" // только ошибки
#define LOG_LEVEL_ALL_MESSAGES "all_messages" //Все ошибки и сообщения

class LogerService {
    private:
        FileEntity* acceptLogFile = nullptr;
        FileEntity* errorLogFile = nullptr;
        std::string logLevel;
    public:
        LogerService();
        bool writeErrorLog(std::string log);
        bool writeAcceptLog(std::string log);
};

#endif //AVRDEVICECONTROLLER_LOGERSERVICE_H
