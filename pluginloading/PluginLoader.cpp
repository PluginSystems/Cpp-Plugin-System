//
// Created by yannick lamprecht on 24.02.17.
//


#include <iostream>
#include <fstream>
#include "PluginLoader.h"
#include "plugins/TestPlugin.cpp"


ysl::PluginLoader::PluginLoader(std::string filePath, ysl::FileReader *reader) {
    this->filePath = filePath;
    this->reader = reader;
}

std::string ysl::PluginLoader::getFilePath() {
    return filePath;
}

std::map<std::string, std::shared_ptr<IPlugin>> ysl::PluginLoader::load() {
    const std::string endings[] = {"txt"};// "so","dll"
    std::vector<std::string> files = reader->readDir(filePath, endings, FileReader::fullyQualifiedName);

    std::cout << "Files available: " << files.size() << std::endl;


    for (std::string name : files) {
        std::cout << name << std::endl;
    }

    std::vector<std::fstream *> loadedFiles = reader->loadFilesFromPath(filePath, endings);

    unsigned long long int size = 20;

    //pluginFiles = new std::map<std::string,std::shared_ptr<IPlugin>>();


    for (int i = 0; i < size; ++i) {

        std::shared_ptr<IPlugin> plugin = std::shared_ptr<IPlugin>(new TestPlugin("Hey" + std::to_string(i)));

        pluginFiles[std::string(typeid(*plugin.get()).name())] = plugin;

    }

/**
 * load files and parse
 */


    return pluginFiles;
}

ysl::PluginLoader::~PluginLoader() {
    std::cout << "Deleting fileReader" << std::endl;
    delete (reader);
}

