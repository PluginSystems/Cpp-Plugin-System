//
// Created by Yannick on 27.02.2017.
//

#if _WIN32 || _WIN64

#include <typeinfo.h>
#else
#include <dlfcn.h>
#include <dlfcn.h>
#endif


#include "IPlugin.h"


std::ostream &operator<<(std::ostream &os, const IPlugin &s) {
    os << s.getName();
    return os;
}

IPlugin::~IPlugin(){

}


const std::string IPlugin::getName() const {

    typeid(*this).name();

    return std::string(typeid(*this).name());
}

IPlugin *IPlugin::operator()(bool shouldEnable) {
    if (shouldEnable) {
        onEnable();
    } else {
        onDisable();
    }

    return this;
}