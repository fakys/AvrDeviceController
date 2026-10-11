//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_ABSTRACTMUTEX_H
#define AVRDEVICECONTROLLER_ABSTRACTMUTEX_H

#include <mutex>

#include "AbstractTask.h"

class AbstractMutex : public std::mutex {
};

#endif //AVRDEVICECONTROLLER_ABSTRACTMUTEX_H
