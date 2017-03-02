//
// Created by yannick lamprecht on 24.02.17.
//

#include <iostream>
#include "IPlugin.h"

class TestPlugin : public virtual IPlugin {
public:
    TestPlugin() : IPlugin() {
    }

    void onEnable() {
        std::cout << "onEnable " << *this << std::endl;
    }

    void onDisable() {
        std::cout << "onDisable " << *this << std::endl;
    }


    IPlugin *operator()(bool enable) override {
        if (enable) {
            onEnable();
        } else {
            onDisable();
        }
        return this;
    }
};
