#include <iostream>
#include <vector>
#include "pluginloading/plugin/IPlugin.h"
#include "pluginloading/PluginLoader.h"


int main() {

    ysl::PluginLoader loader(".", new ysl::FileReader());


    std::vector<IPlugin*> plugins = loader.load();

    std::cout << "Plugins loaded: " <<plugins.size() << std::endl;

    for(IPlugin *plugin : plugins){
        std::cout << "Plugin "<< plugin->getName() << std::endl;
    }


    return 0;
}