//
// Created by yannick lamprecht on 27.02.17.
//

#ifndef CPP_PLUGINTEST_PLUGINLOADER_H
#define CPP_PLUGINTEST_PLUGINLOADER_H


#include <vector>
#include <string>
#include <memory>
#include <map>
#include "plugins/IPlugin.h"
#include "../files/FileReader.h"


namespace ysl {


    struct PluginHandle{
        void *handle;
        create_t* create;
        destroy_t* destroy;
    };



    class PluginLoader {

    protected:
        std::string filePath;
        ysl::FileReader *reader;
        std::map<std::string,std::shared_ptr<IPlugin>> pluginFiles;
        std::map<std::string,PluginHandle> pluginHandles;
        const std::string *fileEndings;

        void load(std::string pluginFileName);


    public:

        PluginLoader(std::string filePath, ysl::FileReader *reader,const std::string fileEndings[]);

        ~PluginLoader();

        void disable(const std::string pluginName);

        void enable(const std::string pluginName);

        void enable();

        void disable();

        void load();

        void unload();

        std::map<std::string,std::shared_ptr<IPlugin>> getLoadedPlugins();

        void unload(std::string pluginName);
    };


};


#endif //CPP_PLUGINTEST_PLUGINLOADER_H
