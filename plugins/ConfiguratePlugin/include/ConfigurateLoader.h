//
// Created by fakys on 02.10.2026.
//

#ifndef AVRDEVICECONTROLLER_CONFIGURATELOADER_H
#define AVRDEVICECONTROLLER_CONFIGURATELOADER_H

#include "Configurate.h"

class ConfigurateLoader {
    public:
    ConfigurateLoader();
    bool checkConfig();
    Configurate* loadConfig();

};

#endif //AVRDEVICECONTROLLER_CONFIGURATELOADER_H
