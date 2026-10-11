//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_THEREAD_H
#define AVRDEVICECONTROLLER_THEREAD_H

#include "AbstractExecuter.h"
#include <pthread.h>

class Thread : public AbstractExecuter {
private:
    pthread_t thread_id;
public:
    Thread(pthread_t thread_id) : thread_id(thread_id) {}

    pthread_t getThreadId() {
        return thread_id;
    };
};

#endif //AVRDEVICECONTROLLER_THEREAD_H
