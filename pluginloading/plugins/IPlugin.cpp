//
// Created by Yannick on 27.02.2017.
//

#include "IPlugin.h"


std::ostream &operator<<(std::ostream &os, const IPlugin &s) {
    os << s.getName();
    return os;
}

const std::string IPlugin::getName() const {
    return std::string(typeid(*this).name());
}