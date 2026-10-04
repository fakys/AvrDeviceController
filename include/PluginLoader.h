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
        static std::vector<AbstractPlugin*> plugins;

        void loadPlugin(AbstractPlugin* plugin);
    public:
        static void appendPlugin(AbstractPlugin* plugin) {
            plugins.push_back(plugin);
        }
        AbstractPlugin* getPluginByName(const std::string& name) {
            for (AbstractPlugin* plugin : plugins) {
                if (plugin->getPluginName() == name) {
                    return plugin;
                }
            }
            return nullptr;
        }
        void loadPlugins();

};

#define registerPlugin(plugin) struct InitStrcut##plugin {\
        InitStrcut##plugin() {\
            PluginLoader::appendPlugin(new plugin);\
        }\
    };\
    InitStrcut##plugin propertyInitStrcut##plugin;\

#endif //AVR_PROTO_LINUX_PLUGINLOADER_H
