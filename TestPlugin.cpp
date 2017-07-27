//
// Created by yannick lamprecht on 24.02.17.
//

#include <iostream>
#include "pluginloading/plugins/IPlugin.h"
#include "StringFace.h"

class TestPlugin : public virtual IPlugin {
public:
    TestPlugin() : IPlugin() {

    }

    ~TestPlugin(){
    }

    const std::string getName() override {
        return "TestPlugin";
    }


    void onEnable() override {
    }

    void onDisable() override {
    }

};

extern "C" {

std::shared_ptr<IPlugin> create() {
    return std::make_shared<TestPlugin>(TestPlugin());
}

}
