//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_PROCESSFACTORY_H
#define AVR_PROTO_LINUX_PROCESSFACTORY_H
#include "ProcessEntity.h"


class ProcessFactory {
    public:
    ProcessFactory() = default;
    ProcessEntity* createProcess(__pid_t pid, uint8_t type = PARENT_PROCESS) {
        return new ProcessEntity(pid, type);
    };
};

#endif //AVR_PROTO_LINUX_PROCESSFACTORY_H
