//
// Created by yannick lamprecht on 25.02.17.
//

#ifndef CPP_PLUGINTEST_FILES_FILEREADER_H
#define CPP_PLUGINTEST_FILES_FILEREADER_H


#include <vector>
#include <string>
#if _WIN32 || _WIN64
#include <c++/functional>
#endif

namespace ysl {

    class FileReader {

    public:

        FileReader();

        ~FileReader();

        int makedir(const std::string path);

        std::vector<std::string> readDir(const std::string path, const std::vector<std::string> fileEnding,
                                         std::function<std::string(std::string, std::string)> naming);

        std::vector<std::fstream *> loadFilesFromPath(const std::string path, std::vector<std::string> fileEndings);

        std::vector<std::fstream *> loadFiles(const std::vector<std::string> files);

        static std::string fullyQualifiedName(const std::string path,const std::string fileName){
            return path+fileName;
        }

        static std::string nameOnly(const std::string path, const std::string fileName){
            return fileName;
        }
    };
};

#endif //CPP_PLUGINTEST_FILES_FILEREADER_H
