//
// Created by fakys on 02.10.2026.
//

#ifndef AVR_PROTO_LINUX_MAINEXECPTION_H
#define AVR_PROTO_LINUX_MAINEXECPTION_H
#include <exception>
#include <string>

class MainException : public std::exception {
private:
    std::string message;
    public:
    MainException(std::string message): message(message) {};

    std::string getMessage() {
        return message;
    };
};

#endif //AVR_PROTO_LINUX_MAINEXECPTION_H
