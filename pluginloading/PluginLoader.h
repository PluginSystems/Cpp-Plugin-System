//
// Created by yannick lamprecht on 27.02.17.
//

#ifndef CPP_PLUGINTEST_PLUGINLOADER_H
#define CPP_PLUGINTEST_PLUGINLOADER_H


#include <vector>
#include <string>
#include "plugins/IPlugin.h"
#include "../files/FileReader.h"


namespace ysl {

    class PluginLoader {

    protected:
        std::string filePath;
        ysl::FileReader *reader;
        std::vector<IPlugin *> *pluginFiles;


    public:
        PluginLoader(std::string filePath, ysl::FileReader *reader);

        std::vector<IPlugin *>* load();

        std::string getFilePath();
    };


};


#endif //CPP_PLUGINTEST_PLUGINLOADER_H
