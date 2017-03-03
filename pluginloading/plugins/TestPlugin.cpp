//
// Created by yannick lamprecht on 24.02.17.
//

#include <iostream>
#include "IPlugin.h"

class TestPlugin : public virtual IPlugin {
public:
    TestPlugin() : IPlugin() {


    }

    ~TestPlugin(){

    }

    void onEnable() {
        std::cout << "onEnable " << *this << std::endl;
    }

    void onDisable() {
        std::cout << "onDisable " << *this << std::endl;
    }
};

extern "C" {

IPlugin *create() {
    return new TestPlugin;
}

void destroy(IPlugin *p) {
    delete p;
}

}
