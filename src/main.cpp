#include "main.h"
#include "plugins.h"
#include "Kernel.h"
#include "PluginLoader.h"
#include <MainException.h>

#include "tasks/BaseProcessTask.h"

void signalHandler(int signum) {
    for (Thread* thread : Kernel::getObject()->getProcessManager()->getThreads()) {
        thread->stop();
    }
    Kernel::getObject()->getProcessManager()->getProcess()->stop();
}

void initKernel(int argc, char* argv[]) {
    //Создаем загрузчик ядра
    Kernel::getObject();

    //Создаем менеджер процессов
    Kernel::getObject()->initProcessManager();

    //Загрузка и парсинг аргументов
    Kernel::getObject()->handleArguments(argc, argv);

    //Инит конфига
    Kernel::getObject()->initConfig();

    //Загружаем поля для конфига у плагинов
    Kernel::getObject()->getPluginLoader()->loadConfigPlugin();

    //Загрузка конфига
    Kernel::getObject()->loadConfig();
    //Инит логирования
    Kernel::getObject()->initLogerService();

    //Загружаем все наши плагины
    Kernel::getObject()->getPluginLoader()->loadPlugins();
}

int startService() {

    //todo делать демонизацию сразу после инита аргументов
    // if (!Kernel::getObject()->getProcessArgument()->getDemon()->getValue().empty()) {
    // __pid_t ret;
    // switch(ret=fork())
    // {
    //     case -1:
    //         Kernel::getObject()->getCommunication()->sendOutputErrorMessage("Error create fork process");
    //         return -1;
    //     case 0 :
    //         Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Success create fork process");
    //         break;
    //     default :
    //         return  0;
    //         break;
    //   }
    // }
    Kernel::getObject()->getTaskManager()->TaskExecute(new BaseProcessTask(signalHandler));
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