//
// Created by fakys on 11.10.2026.
//


#include "HttpWorkerTask.h"
#include "crow.h"
#include <unistd.h>

int HttpWorkerTask::Execute() {

    for (auto method: methods) {
        method->registerMethod(this->app);
    }

    this->app->port(80).multithreaded().run();
    return 0;
}
