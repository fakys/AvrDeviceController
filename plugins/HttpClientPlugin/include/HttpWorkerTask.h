//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPWORKERQUEUE_H
#define AVRDEVICECONTROLLER_HTTPWORKERQUEUE_H
#include <string>
#include "AbstractTask.h"
#include <utility>
#include <vector>
#include "AbstractHttpMethod.h"


class HttpWorkerTask : public AbstractTask {
    private:
    std::vector<AbstractHttpMethod*> methods;
    crow::SimpleApp* app;
    public:
        HttpWorkerTask(std::vector<AbstractHttpMethod*> methods, crow::SimpleApp* app) : methods(std::move(methods)), app(app) {};
        int Execute() override;

        std::string getTaskName() override {
            return "Http worker";
        };

        std::string getTaskDescription() override {
            return "Processing incoming HTTP requests";
        }
};

#endif //AVRDEVICECONTROLLER_HTTPWORKERQUEUE_H
