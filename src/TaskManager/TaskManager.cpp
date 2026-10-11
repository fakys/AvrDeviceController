//
// Created by fakys on 11.10.2026.
//

#include "TaskManager.h"

#include "Kernel.h"


void TaskManager::TaskExecute(AbstractTask *task) {
    task->lock();
    task->startTask();
    if (Kernel::getObject()->getProcessManager()->whoami() == PROCESS_BYTE) { // процесс
        Kernel::getObject()->getProcessManager()->getProcess()->setTask(task);
        task->Execute();
    } else { // поток
        Kernel::getObject()->getProcessManager()->getThread()->setTask(task);
        task->Execute();
    }
    task->unlock();
}
