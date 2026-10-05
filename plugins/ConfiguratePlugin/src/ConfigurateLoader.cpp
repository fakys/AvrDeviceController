


#include "ConfigurateLoader.h"
#include "main.h"
#include "Kernel.h"
#include "FileRWPlugin.h"
#include "LineReadDriver.h"
#include "ConfigurateException.h"
#include "string_helpers.h"

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
    auto* acceptLogPath = new ConfigLogAcceptPathEntity();
    auto* errorLogPath = new ConfigLogErrorPathEntity();
    auto* logLevel = new ConfigLogLevelEntity();
    std::vector<AbstractConfigEntity*> paramsVector {
        acceptLogPath,
        errorLogPath,
        logLevel
    };

    FileEntity* file = plugin->openFile(this->configPath, new LineReadDriver(';'));
    if (!file) {
        throw ConfigurateException("Fail open config file");
    }

    //Читаем конфиг по одной строке, формат ключ=значение
    std::vector<uint8_t> buffer;
    while (file->getReadDriver()->readFile(&buffer)) {
        std::string str(buffer.begin(), buffer.end());
        if (str.find('=') != std::string::npos) {
            std::string value;
            value = str;
            value.erase(0, value.find('=')+1);
            value.erase(value.length()-1);

            str.erase(str.find('='));

            trimInPlace(value);
            trimInPlace(str);

            bool attr_exists = false;
            for (AbstractConfigEntity* entity : paramsVector) {
                if (str == entity->getConfigName()) {
                    entity->setValue(value);
                    attr_exists = true;
                }
            }
            if (!attr_exists) {
                throw ConfigurateException("Invalid attribute: "+ str);
            }
        } else {
            // todo выводить линию на которой находится ошибка
            throw ConfigurateException("Invalid config file");
        }
    }

    for (AbstractConfigEntity* entity : paramsVector) {
        if (entity->requiredField() && entity->getValue().empty()) {
            throw ConfigurateException("Undefined required param " + entity->getConfigName() +" in configuration");
        }
    }

    return nullptr;
}