//
// Created by Yannick on 27.02.2017.
//

#ifndef CPP_PLUGINTEST_IPLUGIN_H
#define CPP_PLUGINTEST_IPLUGIN_H

#include <string>
#include <sstream>

class IPlugin {

public:

    virtual IPlugin* operator()(bool shouldEnable)=0;

    friend std::ostream& operator <<(std::ostream& os, const IPlugin& s);

    virtual const std::string getName() const final;


    // virtual void onEnable()=0;

    // virtual void onDisable()=0;

};


#endif //CPP_PLUGINTEST_IPLUGIN_H
