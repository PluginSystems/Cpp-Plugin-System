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

    class PluginLoader {

    protected:
        std::string filePath;
        ysl::FileReader *reader;
        std::map<std::string,std::shared_ptr<IPlugin>> pluginFiles;


    public:
        PluginLoader(std::string filePath, ysl::FileReader *reader);

        ~PluginLoader();

        std::map<std::string,std::shared_ptr<IPlugin>> load();

        std::string getFilePath();
    };


};


#endif //CPP_PLUGINTEST_PLUGINLOADER_H
