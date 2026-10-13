//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_PROTOCOLSMANAGER_H
#define AVRDEVICECONTROLLER_PROTOCOLSMANAGER_H
#include <vector>

#include "AbstractDeviceProto.h"

class ProtocolsManager {
    private:
        std::vector<AbstractDeviceProto*> protocols;
    public:
        ProtocolsManager() {}

        std::vector<AbstractDeviceProto*>& getAllProtocols() {
            return protocols;
        }

        AbstractDeviceProto* getProtoByName(std::string& name) {
            for (AbstractDeviceProto* proto : protocols) {
                if (proto->getName() == name) {
                    return proto;
                }
            }
            return nullptr;
        }

        void registerProtocol(AbstractDeviceProto* protocol) {
            protocols.push_back(protocol);
        }
};

#endif //AVRDEVICECONTROLLER_PROTOCOLSMANAGER_H
