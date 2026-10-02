#ifndef AVR_PROTO_LINUX_ABSTRACTREADDRIVER_H
#define AVR_PROTO_LINUX_ABSTRACTREADDRIVER_H
#include <cstdint>
#include <vector>

class AbstractReadDriver {
    public:
        void readFile(int fileIndex, std::vector<uint8_t> buffer);
};

#endif
