//
// Created by yannick lamprecht on 24.02.17.
//

#if _WIN32

#include <windows.h>
#include <c++/cstring>

#else

#include <dirent.h>

#endif

#include <fstream>
#include <iostream>


#include "FileReader.h"
#include "FileUtils.h"

namespace ysl {

    FileReader::FileReader() {

    }

    FileReader::~FileReader() {

    }

    std::vector<std::string> FileReader::readDir(const std::string path, const std::string fileEnding[],
                                                 std::function<std::string(std::string, std::string)> naming) {

        std::vector<std::string> filenames;

#if _WIN32 || _WIN64

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

                    if(!endsWith(file_name,fileEnding))


                filenames.push_back(naming(path,file_name));

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

                if (FileUtils::isFile(dirp->d_name) == 0)continue;
                if (!FileUtils::endsWith(dirp->d_name, fileEnding))continue;

                if (FileUtils::isFile(dirp->d_name) != 0) {
                    filenames.push_back(naming(path,dirp->d_name));
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

    std::vector<std::fstream *> ysl::FileReader::loadFilesFromPath(const std::string path,
                                                                   const std::string *fileEnding) {
        return loadFiles(readDir(path, fileEnding,FileReader::fullyQualifiedName));
    }
};




