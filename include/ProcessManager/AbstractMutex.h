//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTMUTEX_H
#define AVRDEVICECONTROLLER_ABSTRACTMUTEX_H

#include <atomic>
#include <thread>

class AbstractMutex {
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
    void lock(bool waiting = true) {
        //todo тут было бы круто указывать в потоке или в процессе что он именно ждет а не выполняет задачу
        while (flag.test_and_set(std::memory_order_acquire)) {
            if (!waiting) {
                throw MainException("mutex is licked");
            }
            std::this_thread::yield();
        }
    }

    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

#endif //AVRDEVICECONTROLLER_ABSTRACTMUTEX_H
