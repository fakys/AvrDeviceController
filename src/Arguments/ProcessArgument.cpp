#include "ProcessArgument.h"

#include "Kernel.h"


void ProcessArgument::parseArguments() {
    for (int i=1; i<argc; i++) {
        std::string arg = this->argv[i];

         if (arg.length() < 2) {
             Kernel::getObject()->getCommunication()->sendOutputWarningMessage("Argument skipped, argument " + arg + " have invalid format");
             continue;
         }

         if (arg[0] != '-') {
             Kernel::getObject()->getCommunication()->sendOutputWarningMessage("Argument skipped, argument " + arg + " have invalid format for key");
             continue;
         }

         bool abbreviation = true;
         if (arg[1] == '-') {
             arg.erase(0, 2); //Обрезаем --
             abbreviation = false;
         } else {
             arg.erase(0, 1); //Обрезаем -
         }

         bool hasValue = false;
         //Логика в том что у ключей без значения value = null если аргумент не был использован и value = 1 если был
         std::string value = "1";
         if (arg.find('=') != std::string::npos) {
             hasValue = true;
             value = arg;
             //Тут получается что если значение есть то мы в value его сохроняем а в arg убираем
             //value - значение
             //arg - аргумент
             value.erase(0, value.find('=')+1);

             arg.erase(arg.find('='));
         }

         for (AbstractArgType* type : this->argTypes) {
             if (hasValue && type->argumentHasValue() && value != "1" || !hasValue && !type->argumentHasValue() && value == "1") {

                 if (abbreviation && type->getAbbreviation() == arg || !abbreviation && type->getArgName() == arg) {
                     type->setValue(value);
                     break;
                 }
             }
         }
        Kernel::getObject()->getCommunication()->sendOutputWarningMessage("Argument skipped, argument " + arg + " not found");
    }
}

ProcessArgument::ProcessArgument(int argc, char** argv)  {
    this->argv = argv;
    this->argc = argc;

    this->configPathArg = new ConfigPathArg();
    this->argTypes.push_back(this->configPathArg);
    this->demon = new DemonArg();
    this->argTypes.push_back(this->demon);

    this->parseArguments();
}

ProcessArgument::~ProcessArgument() {
    delete this->configPathArg;
}