//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_TAKSMANAGER_H
#define AVRDEVICECONTROLLER_TAKSMANAGER_H
#include <string>
#include <vector>

#include "TaskQueue.h"

class TaskManager {
private:
    std::vector<TaskQueue*> taskQueue;
public:
    TaskQueue* createTaskQueue(std::string taskQueueName) {
        auto* task = new TaskQueue(taskQueueName);
        taskQueue.push_back(task);
        return task;
    }

    TaskQueue* getTaskQueue(std::string taskQueueName) {
        for (TaskQueue* queue : taskQueue) {
            if (queue->getTaskQueueName() == taskQueueName) {
                return queue;
            }
        }
        return nullptr;
    };

    std::vector<TaskQueue*> getAllTaskQueues() {
        return this->taskQueue;
    };

    void TaskExecute(AbstractTask* task);


};

#endif //AVRDEVICECONTROLLER_TAKSMANAGER_H
