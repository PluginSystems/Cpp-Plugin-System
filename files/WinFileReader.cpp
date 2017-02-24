//
// Created by yannick lamprecht on 24.02.17.
//


#include <iostream>
#include <vector>
#include "UniFileReader.h"


class WinFileReader : public UniFileReader{

public:
    WinFileReader():UniFileReader(){

    }

    int readDir(const std::string path, std::vector<std::string> *filenames) {
        std::cout << "not implemented" << std::endl;
        return 0;
    }

};

