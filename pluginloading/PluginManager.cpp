//
// Created by yannick lamprecht on 27.02.17.
//

#include "PluginManager.h"


void PluginManager::loadPlugins(std::string path, std::string * fileEndings) {
    pluginLoader = ysl::PluginLoader(path, new ysl::FileReader(),fileEndings);
    pluginLoader.load();
}

bool PluginManager::disablePlugins() {
    //todo implement
}

bool PluginManager::disablePlugin(std::string pluginName) {
    pluginLoader.disable(pluginName);
}

bool PluginManager::enablePlugin(std::string pluginName) {
    pluginLoader.enable(pluginName);
}

bool PluginManager::enablePlugins() {
//todo implement
}

IPlugin *PluginManager::getPlugin(std::string name) {
//todo implement
}

bool PluginManager::reloadPlugin(std::string dir, std::string fileName) {
//todo implement
}

bool PluginManager::unloadPlugin(std::string name) {
//todo implement
}

void PluginManager::unloadPlugins() {
//todo implement
}



