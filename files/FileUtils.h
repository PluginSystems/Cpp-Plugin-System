//
// Created by yannick lamprecht on 01.03.17.
//

#ifndef CPP_PLUGINTEST_FILEUTILS_H
#define CPP_PLUGINTEST_FILEUTILS_H

#include <sys/stat.h>
#include <string>

class FileUtils {

public:
    static int isFile(const char *path);
    static bool endsWith(const std::string &str, const std::string suffix[]);
};


#endif //CPP_PLUGINTEST_FILEUTILS_H
