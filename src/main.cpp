#include "PluginLoader.h"
#include "main.h"

#include "Kernel.h"
#include "plugins.h"
#include "drivers/LineReadDriver.h"

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
    initKernel(argc, argv);

    return startService();
}