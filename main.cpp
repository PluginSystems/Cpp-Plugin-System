#include <iostream>
#include <vector>
#include <thread>
#include "pluginloading/PluginLoader.h"


int main() {


    std::vector<std::string> endings = {"dylib","so","dll"};

    std::string pluginDir = "plugMeIn";



    ysl::PluginLoader loader(pluginDir, endings);


    loader.load();



    loader.enable();

    loader.disable();

    loader.unload();

    return 0;
}