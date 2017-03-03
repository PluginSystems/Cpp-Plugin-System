//
// Created by Yannick on 27.02.2017.
//

#include <dlfcn.h>
#include "IPlugin.h"
#include <dlfcn.h>


std::ostream &operator<<(std::ostream &os, const IPlugin &s) {
    os << s.getName();
    return os;
}

IPlugin::~IPlugin(){}


const std::string IPlugin::getName() const {
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