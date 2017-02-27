#include <iostream>
#include <vector>
#include "pluginloading/PluginLoader.h"


int main() {

    ysl::PluginLoader loader(".", new ysl::FileReader());


    std::vector<IPlugin*> plugins = *loader.load();

    std::cout << "Plugins loaded: " << plugins.size() << std::endl;

    for(IPlugin *plugin:plugins){

        plugin->onEnable();
        plugin->onDisable();

    }

    return 0;
}