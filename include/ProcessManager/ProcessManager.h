//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_THREADMANAGER_H
#define AVRDEVICECONTROLLER_THREADMANAGER_H
#include <sched.h>

#include "Process.h"
#include "Thread.h"
#include <vector>

static thread_local Thread* thread = nullptr;

#define PROCESS_BYTE 1
#define THREAD_BYTE 2

class ProcessManager {
    private:
        Process* ParentProcess;
        std::vector<Thread*> threads;
    public:
        ProcessManager(pid_t pid) {
            this->ParentProcess = new Process(pid);
        }
        __pid_t cloneProcess();

        void createThread(AbstractTask* task);

        int whoami();

        Process* getProcess() {
            return this->ParentProcess;
        }

        void appendThread(Thread* thread) {
            this->threads.push_back(thread);
        }

        void deleteThread(Thread* thread);

        Thread* getThread() {
            return thread;
        }

        void setThread(Thread* th) {
            thread = th;
        }

};

#endif //AVRDEVICECONTROLLER_THREADMANAGER_H
