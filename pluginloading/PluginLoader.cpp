//
// Created by yannick lamprecht on 24.02.17.
//


#include <iostream>
#include <fstream>
#include "PluginLoader.h"
#include "plugins/TestPlugin.cpp"
#include "../StreamPrinter.h"


ysl::PluginLoader::PluginLoader(std::string filePath, ysl::FileReader *reader) {
    this->filePath = filePath;
    this->reader = reader;
}

std::string ysl::PluginLoader::getFilePath() {
    return filePath;
}


std::vector<std::shared_ptr<IPlugin>> ysl::PluginLoader::load() {
    const std::string endings[] = {"txt"};// "so","dll"
    std::vector<std::string> files = reader->readDir(filePath,endings);

    std::cout << "Files available: " << files.size() << std::endl;

    for (std::string name : files) {
        std::cout << name << std::endl;
    }

    std::vector<std::fstream *> loadedFiles = reader->loadFilesFromPath(filePath,endings);

    StreamPrinter printer = StreamPrinter(loadedFiles);
    printer.printFiles();

    unsigned long long int size = 20;

    pluginFiles = new std::vector<std::shared_ptr<IPlugin>>();


    for (int i = 0; i < size; ++i) {
    //    pluginFiles->insert(pluginFiles->begin()+i,std::shared_ptr<IPlugin>(new TestPlugin("Hey" + std::to_string(i))));
    }

/**
 * load files and parse
 */


    return *pluginFiles;
}