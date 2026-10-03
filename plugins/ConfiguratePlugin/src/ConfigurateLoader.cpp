


#include "ConfigurateLoader.h"
#include "main.h"
#include "Kernel.h"

ConfigurateLoader::ConfigurateLoader() = default;

bool ConfigurateLoader::checkConfig() {
    std::string value = Kernel::getObject()->getProcessArgument()->getConfigPathArg()->getValue();

    if (value.empty()) {
        std::string path = _PROJECT_CONFIG_PATH_;
    } else {
        std::string path = Kernel::getObject()->getProcessArgument()->getConfigPathArg()->getValue();
    }

    

    return true;
}
