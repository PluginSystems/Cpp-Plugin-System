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

    public:
        PluginLoader(std::string filePath, ysl::FileReader *reader,const std::string fileEndings[]);

        ~PluginLoader();

        std::map<std::string,std::shared_ptr<IPlugin>> load();

        void load(std::string pluginFileName);

        std::string getFilePath();

        void enable(std::string pluginName);
        void disable(std::string pluginName);

        void enable();

    };


};


#endif //CPP_PLUGINTEST_PLUGINLOADER_H
