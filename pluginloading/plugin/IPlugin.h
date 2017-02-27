//
// Created by yannick lamprecht on 24.02.17.
//

#ifndef CPP_PLUGINTEST_IPLUGIN_H
#define CPP_PLUGINTEST_IPLUGIN_H


#include "string"

class IPlugin {

private:
    std::string name;

public:
    std::string getName() {
        return name;
    }

    virtual void onEnable() = 0;

    virtual void onDisable() = 0;

    IPlugin(const std::string name) {
        this->name=name;
    }
};


#endif //CPP_PLUGINTEST_IPLUGIN_H
