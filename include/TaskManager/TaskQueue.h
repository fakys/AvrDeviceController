//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTTASKQUEUE_H
#define AVRDEVICECONTROLLER_ABSTRACTTASKQUEUE_H
#include <string>
#include <vector>
#include "AbstractTask.h"
#include "AbstractMutex.h"

class TaskQueue : public AbstractMutex {
private:
    std::string taskQueueName;
    std::vector<AbstractTask*> tasks;
public:
    TaskQueue(std::string taskQueueName):taskQueueName(taskQueueName) {};

    std::string getTaskQueueName() {
        return taskQueueName;
    };

    void appendQueue(AbstractTask* task) {
        this->lock();
        tasks.push_back(task);
        this->unlock();
    }

    AbstractTask* popTask() {
        this->lock();
        AbstractTask* task = tasks.back();
        tasks.pop_back();
        this->unlock();
        return task;
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTTASKQUEUE_H
