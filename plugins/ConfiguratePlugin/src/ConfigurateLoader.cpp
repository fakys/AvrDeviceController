


#include "ConfigurateLoader.h"
#include "main.h"
#include "Kernel.h"
#include "FileRWPlugin.h"

ConfigurateLoader::ConfigurateLoader() = default;

bool ConfigurateLoader::checkConfig() {
    std::string value = Kernel::getObject()->getProcessArgument()->getConfigPathArg()->getValue();
    std::string path;

    if (value.empty()) {
        path = _PROJECT_CONFIG_PATH_;
    } else {
        path = Kernel::getObject()->getProcessArgument()->getConfigPathArg()->getValue();
    }

    FileRWPlugin* plugin = (FileRWPlugin*)Kernel::getObject()->getPluginLoader()->getPluginByName(FileRWP);
    return plugin->checkAccessFile(path);
}
