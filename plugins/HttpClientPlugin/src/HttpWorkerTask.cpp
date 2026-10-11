//
// Created by fakys on 11.10.2026.
//


#include "HttpWorkerTask.h"
#include "crow.h"
#include <unistd.h>

int HttpWorkerTask::Execute() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    app.port(80).multithreaded().run();
    return 0;
}
