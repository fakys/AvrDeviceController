

#include "ProcessManager.h"
#include "Kernel.h"
#include <unistd.h>

thread_local Thread* ProcessManager::thread;

__pid_t ProcessManager::cloneProcess() {
    __pid_t ret;
    switch(ret=fork())
    {
        case -1:
            Kernel::getObject()->getCommunication()->sendOutputErrorMessage("Error create fork process");
        case 0 :
            Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Success create fork process pid = "+std::to_string(getpid()));
            Kernel::getObject()->initProcessManager();
            break;
    }

    return ret;
}

void ProcessManager::deleteThread(Thread *thread) {
    int index;
    for (Thread* th : threads) {
        if (th == thread) {
            this->threads.erase(this->threads.begin() + index);
        }
        index++;
    }
}

void* ThreadCreate(void* arg) {
    auto* task = (AbstractTask*) arg;
    auto* thread = new Thread(gettid());

    Kernel::getObject()->getProcessManager()->setThread(thread);
    Kernel::getObject()->getProcessManager()->appendThread(thread);

    thread->setTask(task);
    //Выполняем задачу
    Kernel::getObject()->getTaskManager()->TaskExecute(task);
    //Удаляем запершенный поток
    Kernel::getObject()->getProcessManager()->deleteThread(thread);
    //Завершаем процесс
    pthread_exit(nullptr);
}

void ProcessManager::createThread(AbstractTask* task) {
    pthread_t thread_id;
    int result = pthread_create(&thread_id, NULL, ThreadCreate, task);
}

int ProcessManager::whoami() {
    if (thread) {
        return THREAD_BYTE;
    } else {
        return PROCESS_BYTE;
    }
}
