//
// Created by yannick lamprecht on 24.02.17.
//


#include <dirent.h>
#include <fstream>
#include <iostream>
#include "UniFileReader.h"


class UnixFileReader : public UniFileReader {

public:
    UnixFileReader() : UniFileReader() {

    }

    std::vector<std::string> readDir(const std::string path) override {
        std::vector<std::string> filenames;
        DIR *dp;
        struct dirent *dirp;
        if ((dp = opendir(path.c_str())) == NULL) {
            std::cout << "Error(" << errno << ") opening " << path << std::endl;
        }

        while ((dirp = readdir(dp)) != NULL) {
            filenames.push_back(std::string(dirp->d_name));
        }
        closedir(dp);
        return filenames;
    }

    std::vector<std::fstream*> loadFiles(const std::vector<std::string> files) override {
        std::vector<std::fstream*> fileStreams;
        for (std::string file : files) {
            std::fstream *fileD = new std::fstream(file);
            fileStreams.push_back(fileD);
        }
        return fileStreams;
    }


};




