//
// Created by fakys on 01.10.2026.
//

#ifndef AVR_PROTO_LINUX_KERNEL_H
#define AVR_PROTO_LINUX_KERNEL_H

class Kernel {
    public:
    Kernel();
    virtual void getAllPlugins();
    virtual void getPluginByName(std::string name);
};

#endif //AVR_PROTO_LINUX_KERNEL_H
