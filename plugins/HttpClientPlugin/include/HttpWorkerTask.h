//
// Created by fakys on 11.10.2026.
//

#ifndef AVRDEVICECONTROLLER_HTTPWORKERQUEUE_H
#define AVRDEVICECONTROLLER_HTTPWORKERQUEUE_H
#include "AbstractTask.h"

class HttpWorkerTask : public AbstractTask {
    public:
        int Execute() override;
};

#endif //AVRDEVICECONTROLLER_HTTPWORKERQUEUE_H
