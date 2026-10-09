//
// Created by fakys on 02.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATELOADER_H
#define AVRDEVICECONTROLLER_CONFIGURATELOADER_H

#include <algorithm>

#include "Configurate.h"

class ConfigurateLoader {
    private:
        std::string configPath;
        std::vector<AbstractConfigType*> fields;
        void registerBaseConfigs();
    public:
    ConfigurateLoader();
    bool checkConfig();
    void appendConfigFields(std::vector<AbstractConfigType*> fields_vector) {
        for (AbstractConfigType* field : fields_vector) {
            this->fields.push_back(field);
        }
    };
    Configurate* loadConfig();

};

#endif //AVRDEVICECONTROLLER_CONFIGURATELOADER_H
