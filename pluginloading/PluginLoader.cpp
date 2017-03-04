//
// Created by yannick lamprecht on 24.02.17.
//


#include <iostream>
#include <fstream>
#if _WIN32 || _WIN64
#include <fibersapi.h>
#endif

#include "PluginLoader.h"

#if _WIN32 || _WIN64

#include <rpc.h>

#else
#include <dlfcn.h>
#endif


ysl::PluginLoader::PluginLoader(std::string filePath, ysl::FileReader *reader, const std::string fileEndings[]) {
    this->filePath = filePath;
    this->reader = reader;
    this->fileEndings = fileEndings;
}

void ysl::PluginLoader::load() {
    std::vector<std::string> files = reader->readDir(filePath, fileEndings, FileReader::fullyQualifiedName);
    std::cout << "Files available: " << files.size() << std::endl;
    for (const std::string name : files) {
        load(name);
    }
}

std::map<std::string, std::shared_ptr<IPlugin>> ysl::PluginLoader::getLoadedPlugins() {
    return pluginFiles;
}


void ysl::PluginLoader::load(std::string pluginFileName) {

    PluginHandle handle;

#if _WIN32 || _WIN64

    HINSTANCE hGetProcIDDLL = LoadLibrary(pluginFileName.c_str());

    if (!hGetProcIDDLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return;
    }

    handle.handle = hGetProcIDDLL;

    handle.create = (create_t *) GetProcAddress(hGetProcIDDLL, "create");
    if (!handle.create) {
        std::cout << "could not locate the function" << std::endl;
        return;
    }

    handle.destroy = (destroy_t *) GetProcAddress(hGetProcIDDLL, "destroy");
    if (!handle.create) {
        std::cout << "could not locate the function" << std::endl;
        return;
    }

#else

    void *pHandle = dlopen(pluginFileName.c_str(), RTLD_LAZY);
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

#endif

    std::shared_ptr<IPlugin> iPlugin = std::shared_ptr<IPlugin>(handle.create());

    pluginFiles[iPlugin->getName()] = iPlugin;
    pluginHandles[iPlugin->getName()] = handle;
}

void ysl::PluginLoader::unload(std::string pluginName) {
    std::shared_ptr<IPlugin> plugin = pluginFiles[pluginName];
    plugin->onDisable();
    pluginFiles.erase(pluginName);
    PluginHandle handle = pluginHandles[pluginName];
    handle.destroy(plugin.get());

#if _WIN32 || _WIN64
    FreeLibrary((HMODULE) handle.handle);
#else
    dlclose(handle.handle);
#endif
    pluginHandles.erase(pluginName);
}

void ysl::PluginLoader::unload() {
    for (const auto &pluginPair: pluginFiles) {
        unload(pluginPair.first);
    }
}

void ysl::PluginLoader::enable(const std::string pluginName) {
    pluginFiles[pluginName]->onEnable();
}

void ysl::PluginLoader::disable(const std::string pluginName) {
    pluginFiles[pluginName]->onDisable();
}

void ysl::PluginLoader::disable() {
    for (const auto &pluginPair: pluginFiles) {
        disable(pluginPair.first);
    }
}


void ysl::PluginLoader::enable() {
    for (const auto &pluginPair: pluginFiles) {
        enable(pluginPair.first);
    }
}


ysl::PluginLoader::~PluginLoader() {
    unload();
    delete (reader);
}

