//
// Created by fakys on 13.10.2026.
//

#ifndef AVRDEVICECONTROLLER_OPERATIONSYSTEMSMANAGER_H
#define AVRDEVICECONTROLLER_OPERATIONSYSTEMSMANAGER_H
#include <vector>

#include "AbstractOperationSystem.h"

class OperationSystemsManager {
    private:
        std::vector<AbstractOperationSystem*> operation_systems;
    public:
        OperationSystemsManager() = default;

        std::vector<AbstractOperationSystem*>& getAllOperationSystems() {
            return operation_systems;
        }

        AbstractOperationSystem* getOperationSystemByName(std::string& name) {
            for (AbstractOperationSystem* operation_system : operation_systems) {
                if (operation_system->getName() == name) {
                    return operation_system;
                }
            }
            return nullptr;
        }

        void registerOperationSystem(AbstractOperationSystem* operation_system) {
            operation_systems.push_back(operation_system);
        }
};

#endif //AVRDEVICECONTROLLER_OPERATIONSYSTEMSMANAGER_H
