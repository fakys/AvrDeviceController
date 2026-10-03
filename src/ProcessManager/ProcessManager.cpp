//
// Created by fakys on 02.10.2026.
//


#include "ProcessManager.h"

ProcessManager::ProcessManager() {
    this->processFactory = new ProcessFactory();
    //Сохроняем наш родительский пид при создании менеджера процессов
    this->processFactory->createProcess(getpid());
}
