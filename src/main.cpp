#include "PluginLoader.h"
#include "main.h"

#include "Kernel.h"
#include "plugins.h"
#include "drivers/LineReadDriver.h"

void initKernel() {
    //Создаем загрузчик ядра
    Kernel::getObject();
    //Загружаем все наши плагины
    Kernel::getObject()->getPluginLoader()->loadPlugins();
}

int startService() {

    return 0;
}


int main() {
    initKernel();

    return startService();
}