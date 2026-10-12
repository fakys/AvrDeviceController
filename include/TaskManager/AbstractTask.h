//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTTASK_H
#define AVRDEVICECONTROLLER_ABSTRACTTASK_H

#define PENDING 0
#define ACTIVE 1

#include "AbstractMutex.h"
#include <string>

class AbstractTask : public AbstractMutex {
    private:
        int status = PENDING;
    public:
        virtual int Execute() = 0;
        virtual std::string getTaskName() = 0;
        virtual std::string getTaskDescription() = 0;
        virtual void stopTask() = 0;
        void startTask() {
            this->status = ACTIVE;
        }
        int getStatus() {
            return status;
        }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTTASK_H
