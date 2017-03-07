#include <iostream>
#include <vector>
#include <thread>
#include "pluginloading/PluginLoader.h"


int main() {


    std::vector<std::string> endings = {"dylib","so","dll"};




    ysl::PluginLoader loader("plugMeIn/", new ysl::FileReader(), endings);


    loader.load();



    loader.enable();

    loader.disable();

    loader.unload();

    return 0;
}