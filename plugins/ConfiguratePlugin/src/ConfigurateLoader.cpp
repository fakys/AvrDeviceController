


#include "ConfigurateLoader.h"
#include "main.h"
#include "Kernel.h"
#include "FileRWPlugin.h"
#include "LineReadDriver.h"
#include "ConfigurateException.h"
#include "config_parser_helper.h"

ConfigurateLoader::ConfigurateLoader() = default;

bool ConfigurateLoader::checkConfig() {
    std::string value = Kernel::getObject()->getProcessArgument()->getConfigPathArg()->getValue();

    if (value.empty()) {
        this->configPath = _PROJECT_CONFIG_PATH_;
    } else {
        this->configPath = Kernel::getObject()->getProcessArgument()->getConfigPathArg()->getValue();
    }

    FileRWPlugin* plugin = (FileRWPlugin*)Kernel::getObject()->getPluginLoader()->getPluginByName(FileRWP);
    return plugin->checkAccessFile(this->configPath);
}


Configurate* ConfigurateLoader::loadConfig() {
    FileRWPlugin* plugin = (FileRWPlugin*)Kernel::getObject()->getPluginLoader()->getPluginByName(FileRWP);
    std::vector<uint8_t> vectorStrEnd = std::vector<uint8_t>{STRING_END, ARRAY_START, ARRAY_END, OBJECT_START, OBJECT_END, '\n'};

    FileEntity* file = plugin->openFile(this->configPath, new LineReadDriver(vectorStrEnd));
    if (!file) {
        throw ConfigurateException("Fail open config file");
    }

    //Читаем конфиг по одной строке, формат ключ=значение
    std::vector<uint8_t> buffer;
    Configurate* config = nullptr;
    while (file->getReadDriver()->readFile(&buffer)) {
        if (!config) {
            PropertyParser* property = propertyParser(buffer);
            if (property) {
                if (property->propertyName == "configurate" || property->propertyName == "config") {
                    if (property->propertyValueType == PROPERTY_VALUE_OBJECT_TYPE) {
                        config = new Configurate();
                    } else {
                        throw ConfigurateException("Property: "+ property->propertyName + " only object type");
                    }
                } else {
                    throw ConfigurateException("Incorrect property name: " + property->propertyName + " please use configurate or config");
                }
            }
            delete property;
        } else {
            if (!config->isCompleted()) {
                config->handelRow(buffer);
            }
        }
    }
    return config;
}