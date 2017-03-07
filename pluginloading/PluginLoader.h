//
// Created by yannick lamprecht on 27.02.17.
//

#ifndef CPP_PLUGINTEST_PLUGINLOADER_H
#define CPP_PLUGINTEST_PLUGINLOADER_H


#include <vector>
#include <string>
#include <memory>
#include <map>
#include <unordered_map>
#include "plugins/IPlugin.h"
#include "../files/FileReader.h"


namespace ysl {


    struct PluginHandle {
        void * handle;
        create_t * create;
    };


    class PluginLoader {

    protected:
        std::string filePath;
        std::unordered_map<std::string, std::shared_ptr<IPlugin>> pluginFiles;
        std::unordered_map<std::string, std::shared_ptr<PluginHandle>> pluginHandles;
        std::vector<std::string> fileEndings;

        void load(const std::string& pluginFileName);


    public:

        PluginLoader(std::string& filePath, std::vector<std::string>& fileEndings);

        void disable(const std::string& pluginName);

        void enable(const std::string& pluginName);

        void enable();

        void disable();

        void load();

        void unload();

        std::unordered_map<std::string, std::shared_ptr<IPlugin>> getLoadedPlugins();

        void unload(const std::string& pluginName);
    };


};


#endif //CPP_PLUGINTEST_PLUGINLOADER_H
