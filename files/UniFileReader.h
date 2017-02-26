//
// Created by yannick lamprecht on 25.02.17.
//

#ifndef CPP_PLUGINTEST_UNIFILEREADER_H
#define CPP_PLUGINTEST_UNIFILEREADER_H


#include <vector>
#include <string>

class UniFileReader {

public:
    virtual std::vector<std::string> readDir(const std::string path)= 0;

    virtual std::vector<std::fstream*> loadFiles(const std::vector<std::string> files)=0;
};


#endif //CPP_PLUGINTEST_UNIFILEREADER_H
