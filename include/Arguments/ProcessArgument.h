#ifndef AVRDEVICECONTROLLER_PROCESSARGUMENT_H
#define AVRDEVICECONTROLLER_PROCESSARGUMENT_H
#include <iostream>
#include <ostream>
#include <vector>

#include "ArgTypes/ConfigPathArg.h"

class ProcessArgument {
    private:
    char** argv;
    int argc;

    std::vector<AbstractArgType*> argTypes;
    ConfigPathArg* configPathArg;

    void parseArguments();

    public:
    ProcessArgument(int argc, char* argv[]);

    ConfigPathArg* getConfigPathArg() {
        return configPathArg;
    }

    ~ProcessArgument();
};

#endif
