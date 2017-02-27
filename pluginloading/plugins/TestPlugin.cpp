//
// Created by yannick lamprecht on 24.02.17.
//

#include <iostream>
#include "IPlugin.h"

class TestPlugin : public virtual IPlugin {
public:
    TestPlugin(const std::string name) : IPlugin(name) {
    }

    void onEnable() override {
        std::cout << "onEnable " << getName() << std::endl;
    }

    void onDisable() override {
        std::cout << "onDisable " << getName() << std::endl;
    }
};
