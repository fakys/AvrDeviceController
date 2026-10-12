//
// Created by fakys on 12.10.2026.
//

#include "ProcessStatusMethod.h"
#include "Kernel.h"

void ProcessStatusMethod::registerMethod(crow::SimpleApp *app) {
    CROW_ROUTE((*app), "/process/status")([]() {
        crow::json::wvalue jsonResponse(
            {
                {
                    "process", crow::json::wvalue{
                        {"pid", std::to_string(Kernel::getObject()->getProcessManager()->getProcess()->getPid())},
                        {
                            "task", Kernel::getObject()->getProcessManager()->getProcess()->getTask()
                                        ? crow::json::wvalue{
                                            {
                                                "name",
                                                Kernel::getObject()->getProcessManager()->getProcess()->getTask()->
                                                getTaskName()
                                            },
                                            {
                                                "description",
                                                Kernel::getObject()->getProcessManager()->getProcess()->getTask()->
                                                getTaskDescription()
                                            },
                                            {
                                                "status",
                                                std::to_string(
                                                    Kernel::getObject()->getProcessManager()->getProcess()->getTask()->
                                                    getStatus())
                                            }
                                        }
                                        : nullptr,
                        }
                    }
                }
            }
        );

        int index = 0;
        for (Thread *thread: Kernel::getObject()->getProcessManager()->getThreads()) {
            jsonResponse["threads"][index] = crow::json::wvalue{
                {"tid", std::to_string(thread->getThreadId())},
                {
                    "task", thread->getTask()
                                ? crow::json::wvalue{
                                    {
                                        "name",
                                        thread->getTask()->
                                        getTaskName()
                                    },
                                    {
                                        "description",
                                        thread->getTask()->
                                        getTaskDescription()
                                    },
                                    {
                                        "status",
                                        std::to_string(
                                            thread->getTask()->
                                            getStatus() )
                                    }
                                }
                                : nullptr,
                }
            };
            index++;
        }

        return jsonResponse;
    });
}
