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
        std::cout << "onEnable " << this->getName() << " Be ready to rumble"<< std::endl;
    }

    void onDisable() override {
        std::cout << "onDisable " << this->getName() << " Be ready to rumble" << std::endl;
    }

    void printMessage(std::string message) override {
        std::cout << getName() << " saying " << message << std::endl;
    }

    std::string modifyMessage(std::string message) override {
        return getName() + " returning "+ message;
    }

};

extern "C" {

std::shared_ptr<IPlugin> create() {
    return std::make_shared<SecondPlugin>(SecondPlugin());
}

}