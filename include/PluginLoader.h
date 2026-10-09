//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_PLUGINLOADER_H
#define AVR_PROTO_LINUX_PLUGINLOADER_H

#include <iostream>
#include <vector>
#include "AbstractPlugin.h"


class PluginLoader {
    private:
    std::vector<AbstractPlugin*>* plugins;

        void loadPlugin(AbstractPlugin* plugin);
    public:
        PluginLoader();
        AbstractPlugin* getPluginByName(const std::string& name) {
            for (AbstractPlugin* plugin : *this->plugins) {
                if (plugin->getPluginName() == name) {
                    return plugin;
                }
            }
            return nullptr;
        }
        void loadPlugins();
        void loadConfigPlugin();

};

#endif //AVR_PROTO_LINUX_PLUGINLOADER_H
