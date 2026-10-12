//
// Created by fakys on 12.10.2026.
//



#include "AbstractExecuter.h"
#include "Kernel.h"


void AbstractExecuter::stop() {
    //Если задача есть то останавливаем её
    if (this->getTask()) {
        Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Task "+task->getTaskName()+" stopped");
        this->getTask()->stopTask();
    }
}
