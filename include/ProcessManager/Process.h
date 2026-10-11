//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_PROCESS_H
#define AVRDEVICECONTROLLER_PROCESS_H
#include <sched.h>

#include "AbstractExecuter.h"

class Process : public AbstractExecuter {
    private:
        pid_t pid;
    public:
        Process(pid_t pid) : pid(pid) {};
};

#endif //AVRDEVICECONTROLLER_PROCESS_H
