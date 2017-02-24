//
// Created by yannick lamprecht on 24.02.17.
//

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "IPlugin.h"
#include "../TestPlugin.cpp"
#include "../files/UniFileReader.h"

using namespace std;

class MPluginLoader{

private:
    string filePath;
    UniFileReader *reader;

protected:
    vector<std::shared_ptr<IPlugin>> pluginFiles;


public:
    MPluginLoader(string filePath,UniFileReader *reader) {
        this->filePath=filePath;
        this->reader = reader;
    }

    string getFilePath() {
        return filePath;
    }


    void load(std::function<void(vector<std::shared_ptr<IPlugin>>)> callback) {

        vector<string> files = vector<string>();

        reader->readDir(filePath,&files);

        std::cout << files.size() << endl;

        for(string f : files){
            cout << f << endl;
        }


        pluginFiles = vector<std::shared_ptr<IPlugin>>();

        string ms = "Hey";

        for (int i = 0; i < 30; ++i) {

            pluginFiles.push_back(std::make_shared<TestPlugin>(ms));
        }






        /**
         * load files and parse
         */


        callback(pluginFiles);
    }

};