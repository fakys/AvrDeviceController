//
// Created by fakys on 11.10.2026.
//


#include "HttpWorkerTask.h"
#include "crow.h"
#include <unistd.h>

#include "HttpObjectConfig.h"
#include "Kernel.h"
#include "StringConfigFieldType.h"

int HttpWorkerTask::Execute() {

    for (auto method: methods) {
        method->registerMethod(this->app);
    }
    HttpObjectConfig* httpConf = (HttpObjectConfig*)Kernel::getObject()->getConfigurate()->getFieldByName("http");
    StringConfigFieldType* httpPort = (StringConfigFieldType*)httpConf->getFieldByName("http_port");
    this->app->port((uint16_t)std::stoi(httpPort->getValue())).multithreaded().run();
    return 0;
}


void HttpWorkerTask::stopTask() {
    //Стопаем задачу
    std::cout << "2222222 " <<  std::endl;
    this->app->stop();
}