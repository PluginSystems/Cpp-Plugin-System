//
// Created by yannick lamprecht on 25.02.17.
//

#ifndef CPP_PLUGINTEST_FILES_FILEREADER_H
#define CPP_PLUGINTEST_FILES_FILEREADER_H


#include <vector>
#include <string>

namespace ysl {

    class FileReader {

    public:

        FileReader();

        ~FileReader();

        std::vector<std::string> readDir(const std::string path, const std::string *fileEnding);

        std::vector<std::fstream*> loadFilesFromPath(const std::string path, const std::string *fileEndings);

        std::vector<std::fstream *> loadFiles(const std::vector<std::string> files);
    };
};

#endif //CPP_PLUGINTEST_FILES_FILEREADER_H
