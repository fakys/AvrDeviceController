//
// Created by fakys on 09.10.2026.
//

#ifndef AVRDEVICECONTROLLER_LOGERSERVICE_H
#define AVRDEVICECONTROLLER_LOGERSERVICE_H
#include "FileEntity.h"

class LogerService {
    private:
        FileEntity* acceptLogFile = nullptr;
        FileEntity* errorLogFile = nullptr;
        std::string logType;
    public:
        LogerService();
};

#endif //AVRDEVICECONTROLLER_LOGERSERVICE_H
