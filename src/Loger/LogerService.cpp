//
// Created by fakys on 09.10.2026.
//


#include "LogerService.h"
#include "AbstractReadDriver.h"
#include <fcntl.h>
#include "AbstractWriteDriver.h"
#include "Kernel.h"
#include "StringConfigFieldType.h"
#include "ConfigAcceptLogPath.h"
#include "LineWriteDriver.h"
#include "ConfigErrorLogPath.h"
#include "ConfigLogLevel.h"
#include "Exceptions/LogerException.h"


LogerService::LogerService() {
    auto* acceptLogPath = (StringConfigFieldType*)Kernel::getObject()->getConfigurate()->getFieldByName(ACCEPT_LOG_PATH);
    auto* errorLogPath = (StringConfigFieldType*)Kernel::getObject()->getConfigurate()->getFieldByName(ERROR_LOG_PATH);
    auto logLevelCong = (StringConfigFieldType*)Kernel::getObject()->getConfigurate()->getFieldByName(LOG_LEVEL);
    //Проверяем файлы для логов
    Kernel::getObject()->getFileController()->checkAccessFile(acceptLogPath->getValue());
    Kernel::getObject()->getFileController()->checkAccessFile(errorLogPath->getValue());

    //Открываю файлы для логов
    this->acceptLogFile = Kernel::getObject()->getFileController()->openFile(acceptLogPath->getValue(), nullptr, new LineWriteDriver('\n'));
    this->errorLogFile = Kernel::getObject()->getFileController()->openFile(errorLogPath->getValue(), nullptr, new LineWriteDriver('\n'));
    if (logLevelCong->getValue() == LOG_LEVEL_NONE || logLevelCong->getValue() == LOG_LEVEL_ONLY_ERRORS || logLevelCong->getValue() == LOG_LEVEL_ALL_MESSAGES) {
        this->logLevel = logLevelCong->getValue();
    } else {
        throw LogerException("Log level not supported: "+logLevelCong->getValue());
    }

}


bool LogerService::writeErrorLog(std::string log) {
    if (this->logLevel != LOG_LEVEL_NONE ) {
        return this->errorLogFile->getWriteDriver()->writeFile(std::vector<uint8_t>(log.begin(), log.end()));
    }
    return true;
}

bool LogerService::writeAcceptLog(std::string log) {
    if (this->logLevel == LOG_LEVEL_ALL_MESSAGES) {
        return this->acceptLogFile->getWriteDriver()->writeFile(std::vector<uint8_t>(log.begin(), log.end()));
    }
    return true;
}

