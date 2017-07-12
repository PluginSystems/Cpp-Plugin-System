//
// Created by yannick lamprecht on 24.02.17.
//

#include <iostream>
#include "pluginloading/plugins/IPlugin.h"

class TestPlugin : public virtual IPlugin {
public:
    TestPlugin() : IPlugin() {

    }

    ~TestPlugin(){
    }

    const std::string getName() override {
        return "ysl:TestPlugin";
    }


    void onEnable() override {
        std::cout << "onEnable " << this->getName() << " Be ready to rumble"<< std::endl;
    }

    void onDisable() override {
        std::cout << "onDisable " << this->getName() << " Be ready to rumble" << std::endl;
    }
};

extern "C" {

std::shared_ptr<IPlugin> create() {
    return std::make_shared<TestPlugin>(TestPlugin());
}

}
