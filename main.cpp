#include <iostream>
#include <vector>
#include "pluginloading/PluginLoader.h"


int main() {

    ysl::PluginLoader loader(".", new ysl::FileReader());


    std::vector<std::shared_ptr<IPlugin>> plugins = loader.load();

    std::cout << "Plugins loaded: " << plugins.size() << std::endl;

    for(std::shared_ptr<IPlugin> & plugin : plugins){

        plugin->onEnable();
        std::cout << plugin.use_count() << std::endl;
        plugin->onDisable();

    }

    return 0;
}