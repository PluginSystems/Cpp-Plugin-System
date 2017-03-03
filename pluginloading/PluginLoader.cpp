//
// Created by yannick lamprecht on 24.02.17.
//


#include <iostream>
#include <fstream>
#include <dlfcn.h>
#include "PluginLoader.h"


ysl::PluginLoader::PluginLoader(std::string filePath, ysl::FileReader *reader, const std::string fileEndings[]) {
    this->filePath = filePath;
    this->reader = reader;
    this->fileEndings=fileEndings;
}

std::string ysl::PluginLoader::getFilePath() {
    return filePath;
}

std::map<std::string, std::shared_ptr<IPlugin>> ysl::PluginLoader::load() {
    std::vector<std::string> files = reader->readDir(filePath, fileEndings, FileReader::fullyQualifiedName);

    std::cout << "Files available: " << files.size() << std::endl;
    for (const std::string name : files) {
        load(name);
    }

    return pluginFiles;
}


void ysl::PluginLoader::load(std::string pluginFileName) {
    void *pHandle = dlopen(pluginFileName.c_str(), RTLD_LAZY);

    PluginHandle handle;

    handle.handle = pHandle;


    if (!pHandle) {
        std::cerr << "Cannot load library: " << dlerror() << '\n';
        return;
    }

    // reset errors
    dlerror();

    // load the symbols
    handle.create = (create_t *) dlsym(pHandle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return;
    }

    handle.destroy = (destroy_t *) dlsym(pHandle, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        return;
    }
    std::shared_ptr<IPlugin> iPlugin = std::shared_ptr<IPlugin>(handle.create());

    pluginFiles[iPlugin->getName()] = iPlugin;
    pluginHandles[iPlugin->getName()] = handle;
}

void ysl::PluginLoader::enable(std::string pluginName) {
    pluginFiles[pluginName]->onEnable();
}

void ysl::PluginLoader::disable(std::string pluginName) {
    std::shared_ptr<IPlugin> plugin = pluginFiles[pluginName];
    plugin->onDisable();
    pluginFiles.erase(pluginName);
    PluginHandle handle = pluginHandles[pluginName];
    handle.destroy(plugin.get());
    dlclose(handle.handle);
    pluginHandles.erase(pluginName);
}

void ysl::PluginLoader::enable() {
    for (auto &pl : pluginFiles) {
        pl.second->onEnable();
    }
}


ysl::PluginLoader::~PluginLoader() {
    for (const auto &pluginPair: pluginFiles) {
        disable(pluginPair.first);

        //todo write an unloadmethode in PluginLoader and move code from disable
    }
    delete (reader);
}

