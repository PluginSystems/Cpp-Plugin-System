//
// Created by yannick lamprecht on 24.02.17.
//

#include <iostream>
#include <fstream>
#include "PluginLoader.h"
#include "plugin/IPlugin.h"


ysl::PluginLoader::PluginLoader(std::string filePath, ysl::FileReader *reader) {
    this->filePath = filePath;
    this->reader = reader;

}

std::string ysl::PluginLoader::getFilePath() {
    return filePath;
}


std::vector<IPlugin*> ysl::PluginLoader::load() {
    std::vector<std::string> files = reader->readDir(filePath);

    std::cout << "Files available: " <<files.size() << std::endl;

    std::vector<std::fstream *> loadedFiles = reader->loadFiles(files);

    delete(pluginFiles);
    pluginFiles = std::vector<IPlugin*>();


   /* for (int i = 0; i < 20; ++i) {
        pluginFiles[i]= new TestPlugin("");
    }*/




/**
 * load files and parse
 */


    return pluginFiles;
}