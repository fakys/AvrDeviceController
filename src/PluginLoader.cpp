//
// Created by fakys on 01.10.2026.
//

#include "PluginLoader.h"
#include "plugins.h"
#include "FailLoadPluginException.h"


void PluginLoader::loadPlugins() {
    for (AbstractPlugin* plugin : *this->plugins) {
        this->loadPlugin(plugin);
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

        //Загружаем плагин
        if (plugin->pluginLoad() < 0) {
            throw FailLoadPluginException("Fail load plugin: "+plugin->getPluginName());
        }
        //Ставим метку что он уже загружен
        plugin->pluginIsLoaded();
    }
}