//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTTASKQUEUE_H
#define AVRDEVICECONTROLLER_ABSTRACTTASKQUEUE_H
#include <string>
#include <vector>
#include "AbstractTask.h"

class TaskQueue {
private:
    std::string taskQueueName;
    std::vector<AbstractTask*> tasks;
public:
    TaskQueue(std::string taskQueueName):taskQueueName(taskQueueName) {};

    std::string getTaskQueueName() {
        return taskQueueName;
    };

    void appendQueue(AbstractTask* task) {
        tasks.push_back(task);
    }

    AbstractTask* popTask() {
        AbstractTask* task = tasks.back();
        tasks.pop_back();
        return task;
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTTASKQUEUE_H
