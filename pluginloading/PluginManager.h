//
// Created by yannick lamprecht on 27.02.17.
//

#ifndef CPP_PLUGINTEST_PLUGINMANAGER_H
#define CPP_PLUGINTEST_PLUGINMANAGER_H


#include <string>
#include <map>
#include "plugin/IPlugin.h"

class PluginManager {

protected:
    std::map<std::string,IPlugin*> plugins;

public:

    virtual void loadPlugins(std::string path)=0;

    virtual bool reloadPlugin(std::string dir, std::string fileName)=0;

    virtual void unloadPlugins()=0;

    virtual bool unloadPlugin(std::string name)=0;

    virtual bool unloadPlugin(int index)=0;

    virtual IPlugin* getPlugin(std::string name)=0;

    virtual IPlugin* getPlugin(int index)=0;

};


#endif //CPP_PLUGINTEST_PLUGINMANAGER_H
