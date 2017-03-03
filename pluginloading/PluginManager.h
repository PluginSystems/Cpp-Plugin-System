//
// Created by yannick lamprecht on 27.02.17.
//

#ifndef CPP_PLUGINTEST_PLUGINMANAGER_H
#define CPP_PLUGINTEST_PLUGINMANAGER_H


#include <string>
#include <map>
#include "plugins/IPlugin.h"
#include "PluginLoader.h"

class PluginManager {

protected:
    ysl::PluginLoader pluginLoader;


public:

    virtual void loadPlugins(std::string path, std::string *fileEndings);

    virtual bool reloadPlugin(std::string dir, std::string fileName);

    virtual bool enablePlugins();

    virtual bool disablePlugins();

    virtual bool disablePlugin(std::string pluginName);

    virtual bool enablePlugin(std::string pluginName);

    virtual void unloadPlugins();

    virtual bool unloadPlugin(std::string name);

    virtual IPlugin *getPlugin(std::string name);


};


#endif //CPP_PLUGINTEST_PLUGINMANAGER_H
