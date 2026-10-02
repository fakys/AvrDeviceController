#ifndef AVR_PROTO_LINUX_AllREADDRIVER_H
#define AVR_PROTO_LINUX_AllREADDRIVER_H
#include "abstracts/AbstractReadDriver.h"

class AllFileReadDriver : public AbstractReadDriver {
    public:
        bool readFile(std::vector<uint8_t>* buffer) override {
            return false;
        }
};

#endif //AVR_PROTO_LINUX_AllREADDRIVER_H
