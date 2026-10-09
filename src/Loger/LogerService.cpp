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




LogerService::LogerService() {
    auto* acceptLogPath = (StringConfigFieldType*)Kernel::getObject()->getConfigurate()->getFieldByName(ACCEPT_LOG_PATH);
    auto* errorLogPath = (StringConfigFieldType*)Kernel::getObject()->getConfigurate()->getFieldByName(ERROR_LOG_PATH);
    //Проверяем файлы для логов
    Kernel::getObject()->getFileController()->checkAccessFile(acceptLogPath->getValue());
    Kernel::getObject()->getFileController()->checkAccessFile(errorLogPath->getValue());

    //Открываю файлы для логов
    this->acceptLogFile = Kernel::getObject()->getFileController()->openFile(acceptLogPath->getValue(), nullptr, new LineWriteDriver('\n'));
    this->errorLogFile = Kernel::getObject()->getFileController()->openFile(errorLogPath->getValue(), nullptr, new LineWriteDriver('\n'));
}
