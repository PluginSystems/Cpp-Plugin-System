//
// Created by yannick lamprecht on 24.02.17.
//


#include <dirent.h>
#include <iostream>
#include "UniFileReader.h"


class UnixFileReader : public UniFileReader{

public:
    UnixFileReader(): UniFileReader(){

    }

    int readDir(const std::string path, std::vector<std::string> *filenames) {
        DIR *dp;
        struct dirent *dirp;
        if((dp  = opendir(path.c_str())) == NULL) {
            std::cout << "Error(" << errno << ") opening " << path << std::endl;
            return errno;
        }

        while ((dirp = readdir(dp)) != NULL) {
            filenames->push_back(std::string(dirp->d_name));
        }
        closedir(dp);
        return 0;
    }

};




