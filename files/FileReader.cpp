//
// Created by yannick lamprecht on 24.02.17.
//

#ifdef _WIN32

#include <windows.h>

#else
#include <dirent.h>
#endif

#include <fstream>
#include <iostream>
#include <c++/cstring>
#include <sys/stat.h>
#include "FileReader.h"

namespace ysl {

    FileReader::FileReader() {

    }

    FileReader::~FileReader() {

    }

    int isFile(const char *path) {
        struct stat path_stat;
        stat(path, &path_stat);
        return S_ISREG(path_stat.st_mode);
    }

    std::vector<std::string> FileReader::readDir(const std::string path) {

        std::vector<std::string> filenames;

#ifdef _WIN32

        HANDLE dir;
        WIN32_FIND_DATA file_data;

        if ((dir = FindFirstFile((path + "/*").c_str(), &file_data)) != INVALID_HANDLE_VALUE) {

            do {
                const std::string file_name = file_data.cFileName;
                const std::string full_file_name = path + "/" + file_name;
                const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

                if (file_name[0] == '.')
                    continue;

                if (is_directory)
                    continue;

                filenames.push_back(full_file_name);
            } while (FindNextFile(dir, &file_data));

            FindClose(dir);
        }

#else

        DIR *dp;
        struct dirent *dirp;
        if ((dp = opendir(path.c_str())) == NULL) {
            std::cout << "Error(" << errno << ") opening " << path << std::endl;
        } else {

            while ((dirp = readdir(dp)) != NULL) {

                if (isFile(dirp->d_name) != 0) {
                    filenames.push_back(std::string(dirp->d_name));
                }
            }
            closedir(dp);

        }
#endif
        return filenames;
    }


    std::vector<std::fstream *> FileReader::loadFiles(const std::vector<std::string> files) {
        std::vector<std::fstream *> fileStreams;
        for (std::string file : files) {
            std::fstream *fileD = new std::fstream(file);
            fileStreams.push_back(fileD);
        }
        return fileStreams;
    }


};




