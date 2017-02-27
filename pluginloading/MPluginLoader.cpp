//
// Created by yannick lamprecht on 24.02.17.
//

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <fstream>
#include "IPlugin.h"
#include "../files/FileReader.h"

using namespace std;

class MPluginLoader{

private:
    string filePath;
    ysl::FileReader* reader;

protected:
    vector<std::shared_ptr<IPlugin>> pluginFiles;


public:
    MPluginLoader(string filePath,ysl::FileReader *reader) {
        this->filePath=filePath;
        this->reader = reader;
    }

    string getFilePath() {
        return filePath;
    }


    void load(std::function<void(vector<std::shared_ptr<IPlugin>>)> callback) {

        vector<string> files = reader->readDir(filePath);

        std::cout << files.size() << endl;



        vector<fstream*> loadedFiles = reader->loadFiles(files);


        for(fstream* stream : loadedFiles){

            string line;

            if(stream->is_open()){

               while (!stream->eof()){
                   *stream >> line;
                   cout << line << endl;

               }

            }
        }

        pluginFiles = vector<std::shared_ptr<IPlugin>>();

        string ms = "Hey";

        /*for (int i = 0; i < 30; ++i) {
            pluginFiles.push_back(std::make_shared<TestPlugin>(ms));
        }
         */






        /**
         * load files and parse
         */


        callback(pluginFiles);
    }

};