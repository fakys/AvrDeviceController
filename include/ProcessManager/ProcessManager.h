//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_THREADMANAGER_H
#define AVRDEVICECONTROLLER_THREADMANAGER_H
#include <sched.h>

#include "Process.h"
#include "Thread.h"
#include <vector>


#define PROCESS_BYTE 1
#define THREAD_BYTE 2

class ProcessManager {
private:
    Process *ParentProcess;
    std::vector<Thread *> threads;
    thread_local static Thread *thread;

public:
    ProcessManager(pid_t pid) {
        this->ParentProcess = new Process(pid);
    }

    __pid_t cloneProcess();

    void createThread(AbstractTask *task);

    int whoami();

    Process *getProcess() {
        return this->ParentProcess;
    }

    void appendThread(Thread *thread) {
        this->threads.push_back(thread);
    }

    Thread *getThread() {
        return thread;
    }

    void deleteThread(Thread *thread);

    std::vector<Thread *> getThreads() {
        return threads;
    }

    void setThread(Thread *th) {
        thread = th;
    }
};

#endif //AVRDEVICECONTROLLER_THREADMANAGER_H
