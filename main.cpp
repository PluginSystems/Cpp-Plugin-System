#include <iostream>
#include <vector>
#include "pluginloading/IPlugin.h"
#include "pluginloading/MPluginLoader.cpp"
#include "files/UnixFileReader.cpp"


void callback(std::vector<std::shared_ptr<IPlugin>> plugins){

    cout << plugins.size() << endl;

    for(shared_ptr<IPlugin> plugin : plugins){
        cout << "Plugin "<< plugin->getName() << endl;
    }
}


void callMeBack(std::string message){
    cout << "the message is: "<< message << endl;
}

int main() {

    MPluginLoader loader(".", new UnixFileReader());


    loader.load(callback);


    return 0;
}