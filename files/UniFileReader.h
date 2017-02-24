//
// Created by yannick lamprecht on 25.02.17.
//

#ifndef CPP_PLUGINTEST_UNIFILEREADER_H
#define CPP_PLUGINTEST_UNIFILEREADER_H


#include <vector>
#include <string>

class UniFileReader {

public:
    virtual int readDir(const std::string path, std::vector<std::string> *files)= 0;
};


#endif //CPP_PLUGINTEST_UNIFILEREADER_H
