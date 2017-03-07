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

ysl::FileReader::FileReader() {

}

ysl::FileReader::~FileReader() {

}

int ysl::FileReader::makedir(const std::string path) {


#if _WIN32 || WIN64
    return _mkdir(path.c_str())
#else
    return mkdir(path.c_str(), 0777);
#endif


}


std::vector<std::string> ysl::FileReader::readDir(const std::string &path, const std::vector<std::string> &fileEnding) {

    std::vector<std::string> filenames;

    if (!makedir(path)) {
        std::cerr << "File Error: " << std::strerror(errno) << std::endl;

    }
    std::cout << "file endings length: " << fileEnding.size() << std::endl;


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

            if (!FileUtils::endsWith(full_file_name, fileEnding))continue;


                filenames.push_back(naming(path, file_name));

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

            std::string fullName = path + "/" + dirp->d_name;


            if (FileUtils::isFile(fullName.c_str()) == 0)continue;

            if (!FileUtils::endsWith(fullName, fileEnding))continue;

            if (FileUtils::isFile(fullName.c_str()) != 0) {
                filenames.push_back(fullName);
            }
        }
        closedir(dp);

    }
#endif
    return filenames;
}


std::vector<std::fstream *> ysl::FileReader::loadFiles(const std::vector<std::string> files) {
    std::vector<std::fstream *> fileStreams;
    for (std::string file : files) {
        std::fstream *fileD = new std::fstream(file);
        fileStreams.push_back(fileD);
    }
    return fileStreams;
}

std::vector<std::fstream *> ysl::FileReader::loadFilesFromPath(const std::string& path,
                                                               std::vector<std::string> fileEnding) {
    return loadFiles(readDir(path, fileEnding));
}




