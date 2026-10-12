//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTEXECUTER_H
#define AVRDEVICECONTROLLER_ABSTRACTEXECUTER_H


#include "AbstractTask.h"

class AbstractExecuter {
    private:
        AbstractTask* task = nullptr;
    public:
        AbstractTask* getTask() { return task; }
        void setTask(AbstractTask* t) {
            this->task = t;
        }
        void stop();
};

#endif //AVRDEVICECONTROLLER_ABSTRACTEXECUTER_H
