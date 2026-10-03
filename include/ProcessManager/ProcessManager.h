//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_PROCESSMANAGER_H
#define AVR_PROTO_LINUX_PROCESSMANAGER_H
#include <vector>

#include "ProcessEntity.h"
#include "ProcessFactory.h"
#include <unistd.h>

class ProcessManager {
  private:
    std::vector<ProcessEntity *> processes;
    ProcessFactory* processFactory;
  public:
    ProcessManager();
};

#endif //AVR_PROTO_LINUX_PROCESSMANAGER_H
