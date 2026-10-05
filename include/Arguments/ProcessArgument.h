#ifndef AVRDEVICECONTROLLER_PROCESSARGUMENT_H
#define AVRDEVICECONTROLLER_PROCESSARGUMENT_H
#include <vector>

#include "ArgTypes/ConfigPathArg.h"
#include "ArgTypes/DemonArg.h"

class ProcessArgument {
    private:
    char** argv;
    int argc;

    std::vector<AbstractArgType*> argTypes;
    ConfigPathArg* configPathArg;
    DemonArg* demon;

    void parseArguments();

    public:
    ProcessArgument(int argc, char* argv[]);

    ConfigPathArg* getConfigPathArg() {
        return configPathArg;
    }

    DemonArg* getDemon() {
        return demon;
    }

    ~ProcessArgument();
};

#endif
