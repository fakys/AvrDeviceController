//
// Created by fakys on 10.10.2026.
//

#include "Communications.h"
#include "Kernel.h"


static std::string timestamp()
{
    char date[32];
    time_t t = time(0);

    tm my_tm;

#if defined(_MSC_VER) || defined(__MINGW32__)
#ifdef CROW_USE_LOCALTIMEZONE
    localtime_s(&my_tm, &t);
#else
    gmtime_s(&my_tm, &t);
#endif
#else
#ifdef CROW_USE_LOCALTIMEZONE
    localtime_r(&t, &my_tm);
#else
    gmtime_r(&t, &my_tm);
#endif
#endif

    size_t sz = strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", &my_tm);
    return std::string(date, date + sz);
}

void Communications::sendOutputWarningMessage(std::string message) {
    if (Kernel::getObject()->getLogerService()) {
        Kernel::getObject()->getLogerService()->writeErrorLog("("+timestamp()+")[Warning] "+message);
    }
    this->outputDriver->sendOutputMessage("("+timestamp()+")[Warning] "+message + '\n');
}

void Communications::sendOutputInfoMessage(std::string message) {
    if (Kernel::getObject()->getLogerService()) {
        Kernel::getObject()->getLogerService()->writeAcceptLog("("+timestamp()+")[Info] "+message);
    }
    this->outputDriver->sendOutputMessage("("+timestamp()+")[Info] "+message + '\n');
}

void Communications::sendOutputErrorMessage(std::string message) {
    if (Kernel::getObject()->getLogerService()) {
        Kernel::getObject()->getLogerService()->writeErrorLog("("+timestamp()+")[Error] "+message);
    }
    this->outputDriver->sendOutputMessage("("+timestamp()+")[Error] "+message + '\n');
}
