//
// Created by Yannick on 27.02.2017.
//

#ifndef CPP_PLUGINTEST_IPLUGIN_H
#define CPP_PLUGINTEST_IPLUGIN_H

#include <string>
#include <sstream>

class IPlugin {


public:

    virtual ~IPlugin();

    virtual const std::string getName()=0;

    virtual void onEnable()=0;

    virtual void onDisable()=0;

};

typedef std::shared_ptr<IPlugin> create_t();

#endif //CPP_PLUGINTEST_IPLUGIN_H
