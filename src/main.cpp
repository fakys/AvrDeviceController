#include "main.h"
#include "plugins.h"
#include "Kernel.h"
#include "PluginLoader.h"
#include <MainException.h>
#include <unistd.h>
#include "ConfigAcceptLogPath.h"
#include <csignal>

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
    Kernel::getObject()->getCommunication()->sendOutputInfoMessage(PROJECT_NAME" started pid = "+std::to_string(getpid()));

    while (true) {
        //Небольшая задержка
        std::this_thread::sleep_for(std::chrono::milliseconds(DEMON_PROCESS_SLEEP));
        signal(SIGTERM, signalHandler);
        signal(SIGINT, signalHandler);
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