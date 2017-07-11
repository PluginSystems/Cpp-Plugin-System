//
// Created by yannick lamprecht on 27.02.17.
//

#ifndef CPP_PLUGINTEST_STREAMPRINTER_H
#define CPP_PLUGINTEST_STREAMPRINTER_H


#include "../files/FileReader.h"

class StreamPrinter {

protected:
    std::vector<std::fstream *> files;

public:

    StreamPrinter(std::vector<std::fstream *> files);

    ~StreamPrinter();

    void printFiles();


};


#endif //CPP_PLUGINTEST_STREAMPRINTER_H
