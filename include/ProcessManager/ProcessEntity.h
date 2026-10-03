//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_PROCESSENTITY_H
#define AVR_PROTO_LINUX_PROCESSENTITY_H

#define PARENT_PROCESS 0xFF //Родительский процесс
#define CHILD_PROCESS 0x3F //Дочерний
#include <cstdint>

class ProcessEntity {
    private:
        __pid_t pid;
        uint8_t processType;
    public:
        ProcessEntity(__pid_t pid, uint8_t processType) : pid(pid), processType(processType) {};
};

#endif //AVR_PROTO_LINUX_PROCESSENTITY_H
