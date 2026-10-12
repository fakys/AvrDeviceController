//
// Created by fakys on 12.10.2026.
//

#ifndef AVRDEVICECONTROLLER_BASEPROCESSTASK_H
#define AVRDEVICECONTROLLER_BASEPROCESSTASK_H

#include <csignal>
#include <string>
#include <thread>
#include <unistd.h>
#include "AbstractTask.h"
#include "Kernel.h"

class BaseProcessTask : public AbstractTask {
    private:
    bool running = true;
    __sighandler_t signalHandler;
    public:
        BaseProcessTask(__sighandler_t signalHandler) : signalHandler(signalHandler) {};
        int Execute() override {
            Kernel::getObject()->getCommunication()->sendOutputInfoMessage(PROJECT_NAME" started pid = "+std::to_string(getpid()));

            while (running) {
                //Небольшая задержка
                std::this_thread::sleep_for(std::chrono::milliseconds(DEMON_PROCESS_SLEEP));
                signal(SIGTERM, signalHandler);
                signal(SIGINT, signalHandler);
            }
            return 0;
        }

    std::string getTaskName() override {
        return "Base process task";
    }

    std::string getTaskDescription() override {
        return "Core task of the main process";
    }

    void stopTask() override {
        this->running = false;
    }
};

#endif //AVRDEVICECONTROLLER_BASEPROCESSTASK_H
