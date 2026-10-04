//
// Created by fakys on 01.10.2026.
//

#include "PluginLoader.h"
#include <algorithm>

std::vector<AbstractPlugin*> PluginLoader::plugins;

void PluginLoader::loadPlugins() {

    for (AbstractPlugin* plugin : PluginLoader::plugins) {
        this->loadPlugin(plugin);
    }
}


void PluginLoader::loadPlugin(AbstractPlugin* plugin) {
    if (!plugin->getPluginLoaded()) {
        if (plugin->getDependPlugins() && !plugin->getDependPlugins()->empty()) {
            for (std::string dependsPluginName : *plugin->getDependPlugins()) {
                //todo проверять что плагин был найден, если нет то ошибка
                for (AbstractPlugin* dependsPlugin : PluginLoader::plugins) {
                    if (dependsPlugin->getPluginName() == dependsPluginName) {
                        this->loadPlugin(dependsPlugin);
                    }
                }
            }
        }

        //Загружаем плагин
        if (plugin->pluginLoad() < 0) {
            //todo Ошибка
        }
        //Ставим метку что он уже загружен
        plugin->pluginIsLoaded();
    }
}