#include <iostream>
#include <vector>
#include "pluginloading/PluginLoader.h"


int main() {

    ysl::PluginLoader loader(".", new ysl::FileReader());


    std::map<std::string,std::shared_ptr<IPlugin>> plugins = loader.load();

    std::cout << "Plugins loaded: " << plugins.size() << std::endl;


    for (const auto& pluginPair : plugins) {
        pluginPair.second->onEnable();
        std::cout << pluginPair.second.use_count() << std::endl;
        pluginPair.second->onDisable();

        std::cout << " type "<<
                  pluginPair.first << " name " << pluginPair.second->getName() << std::endl;
    }

    return 0;
}