#include <iostream>
#include <vector>
#include "pluginloading/PluginLoader.h"


#define DEBUG "mode"

int main() {

    ysl::PluginLoader loader(".", new ysl::FileReader());


    std::map<std::string, std::shared_ptr<IPlugin>> plugins = loader.load();

    std::cout << "Plugins loaded: " << plugins.size() << std::endl;


    for (const auto &pluginPair : plugins) {

        IPlugin &pl = *pluginPair.second.get();

        pl(true);

        std::cout << pluginPair.second.use_count() << std::endl;
        //pluginPair.second->onDisable();

        pl(false);

#ifdef DEBUG
        std::cout << "name: " << *pluginPair.second.get() << std::endl;
#endif
    }

    return 0;
}