//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_LINEREADDRIVER_H
#define AVR_PROTO_LINUX_LINEREADDRIVER_H
#include "abstracts/AbstractReadDriver.h"

class LineReadDriver: public AbstractReadDriver {
    public:
        void readFile(int fileIndex, std::vector<uint8_t> buffer) {

        }
};

#endif //AVR_PROTO_LINUX_LINEREADDRIVER_H
