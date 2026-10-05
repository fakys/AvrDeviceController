#include "main.h"
#include "plugins.h"

#include "Kernel.h"
#include "PluginLoader.h"
#include <pthread.h>
#include <unistd.h>

void initKernel(int argc, char* argv[]) {
    //Создаем загрузчик ядра
    Kernel::getObject();
    Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Start init Kernel");
    Kernel::getObject()->handleArguments(argc, argv);
    //Загружаем все наши плагины
    Kernel::getObject()->getPluginLoader()->loadPlugins();
    Kernel::getObject()->getCommunication()->sendOutputInfoMessage("End init Kernel");
}

int startService() {

    if (!Kernel::getObject()->getProcessArgument()->getDemon()->getValue().empty()) {
        __pid_t ret;
        switch(ret=fork())
        {
            case -1:
                Kernel::getObject()->getCommunication()->sendOutputErrorMessage("Error create fork process");
                return -1;
            case 0 :
                Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Success create fork process pid="+std::to_string(getpid()));
                break;
            default :
                return  0;
                break;
          }
    }

    while (true) {
        //todo выполнять различные проверки
    }
    return 0;
}


int main(int argc, char* argv[]) {
    try {
        initKernel(argc, argv);
        return startService();
    } catch (MainException &e) {
        Kernel::getObject()->getCommunication()->sendOutputErrorMessage(e.getMessage());
        return -1;
    }
}