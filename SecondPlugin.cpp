//
// Created by yannick lamprecht on 22.07.17.
//

#include <iostream>
#include "pluginloading/plugins/IPlugin.h"
#include "StringFace.h"

class SecondPlugin : public virtual IPlugin, public StringFace {
public:
    SecondPlugin() : IPlugin() {

    }

    ~SecondPlugin(){
    }

    const std::string getName() override {
        return "SecondPlugin";
    }


    void onEnable() override {
    }

    void onDisable() override {
    }


    void test() override {

    }

};

extern "C" {

std::shared_ptr<IPlugin> create() {
    return std::make_shared<SecondPlugin>(SecondPlugin());
}

}