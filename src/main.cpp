#include "PluginLoader.h"
#include "main.h"
#include "plugins.h"
#include "drivers/LineReadDriver.h"

void initConfig() {

}

void initLoger() {

}

void initKernel() {

}

int startService() {

    return 0;
}


int main() {

    // initKernel();
    // //Инициализируем конфиг
    // initConfig();
    // //Инициализируем лог файлы
    // initLoger();
    //
    //
    // return startService();

    PluginLoader loader;
    loader.loadPlugins();

    FileRWPlugin* plugin = (FileRWPlugin*)loader.getPluginByName("FileRWPlugin");
    FileEntity* file = plugin->openFile("/home/fakys/test.txt", new LineReadDriver(';'));

    std::vector<uint8_t> buffer;
    while (file->getReadDriver()->readFile(&buffer)) {
        for (uint8_t a: buffer) {
            std::cout << a;
        }
    }

    file->closeFile();
    return 0;
}