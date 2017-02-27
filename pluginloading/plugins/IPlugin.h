//
// Created by Yannick on 27.02.2017.
//

#ifndef CPP_PLUGINTEST_IPLUGIN_H
#define CPP_PLUGINTEST_IPLUGIN_H

#include <string>

class IPlugin {

protected:
    std::string name;

public:

    virtual void onEnable()=0;

    virtual void onDisable()=0;

    std::string getName(){
        return this->name;
    }

    IPlugin(const std::string name){
        this->name=name;
    }

};


#endif //CPP_PLUGINTEST_IPLUGIN_H
