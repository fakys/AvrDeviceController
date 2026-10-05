#include "main.h"
#include "plugins.h"

#include "Kernel.h"
#include "PluginLoader.h"

void initKernel(int argc, char* argv[]) {
    //Создаем загрузчик ядра
    Kernel::getObject();
    Kernel::getObject()->handleArguments(argc, argv);
    //Загружаем все наши плагины
    Kernel::getObject()->getPluginLoader()->loadPlugins();
}

int startService() {

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