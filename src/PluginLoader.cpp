//
// Created by fakys on 01.10.2026.
//

#include "PluginLoader.h"
#include <algorithm>

std::vector<AbstractPlugin*> PluginLoader::plugins;

void PluginLoader::loadPlugins() {
    std::vector<AbstractPlugin*> contextPlugins = PluginLoader::plugins;

    for (AbstractPlugin* plugin : contextPlugins) {
        this->loadPlugin(plugin, &contextPlugins);
    }
}


void PluginLoader::loadPlugin(AbstractPlugin* plugin, std::vector<AbstractPlugin*>* contextPlugins) {
    if (!plugin->getDependPlugins()->empty()) {
        for (std::string dependsPluginName : *plugin->getDependPlugins()) {
            for (AbstractPlugin* dependsPlugin : *contextPlugins) {
                if (dependsPlugin->getPluginName() == dependsPluginName) {
                    this->loadPlugin(dependsPlugin, contextPlugins);
                }
            }
        }
    }

    if (plugin->pluginLoad() < 0) {
        //todo Ошибка
    }

    auto it = std::find(contextPlugins->begin(), contextPlugins->end(), plugin);
    if (it != contextPlugins->end()) {
        contextPlugins->erase(it);
    }
}