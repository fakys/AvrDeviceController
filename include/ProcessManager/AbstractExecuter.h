//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTEXECUTER_H
#define AVRDEVICECONTROLLER_ABSTRACTEXECUTER_H
#include "AbstractTask.h"

class AbstractExecuter {
    private:
        AbstractTask* task;
    public:
        AbstractTask* getTask() { return task; }
        void setTask(AbstractTask* task) { this->task = task; }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTEXECUTER_H
