//
// Created by fakys on 01.10.2026.
//

#include "PluginLoader.h"
#include "plugins.h"
#include "FailLoadPluginException.h"
#include "Kernel.h"


void PluginLoader::loadPlugins() {
    for (AbstractPlugin* plugin : *this->plugins) {
        this->loadPlugin(plugin);
    }
}
//Загружаем файлы конфига
void PluginLoader::loadConfigPlugin() {
    for (AbstractPlugin* plugin : *this->plugins) {
        Kernel::getObject()->getConfigLoader()->appendConfigFields(plugin->getConfigs());
    }
}

PluginLoader::PluginLoader() {
    this->plugins = new std::vector<AbstractPlugin*>{
        ALL_PLUGIN_OBJECTS
    };
}

void PluginLoader::loadPlugin(AbstractPlugin* plugin) {
    if (!plugin->getPluginLoaded()) {
        if (plugin->getDependPlugins() && !plugin->getDependPlugins()->empty()) {
            for (std::string dependsPluginName : *plugin->getDependPlugins()) {
                //todo проверять что плагин был найден, если нет то ошибка
                for (AbstractPlugin* dependsPlugin : *this->plugins) {
                    if (dependsPlugin->getPluginName() == dependsPluginName) {
                        this->loadPlugin(dependsPlugin);
                    }
                }
            }
        }

        Kernel::getObject()->getCommunication()->sendOutputInfoMessage("Init plugin: "+plugin->getPluginName());
        //Загружаем плагин
        if (plugin->pluginLoad() < 0) {
            throw FailLoadPluginException("Fail load plugin: "+plugin->getPluginName());
        }
        //Ставим метку что он уже загружен
        plugin->pluginIsLoaded();
    }
}