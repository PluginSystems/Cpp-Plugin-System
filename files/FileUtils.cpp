//
// Created by yannick lamprecht on 01.03.17.
//

#include "FileUtils.h"


int FileUtils::isFile(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

bool FileUtils::endsWith(const std::string &str, const std::string *suffix) {
    if (suffix->length() == 0)return true;

    for (int i = 0; i < suffix->length(); ++i) {
        if (str.size() >= suffix->size() &&
            str.compare(str.size() - suffix->size(), suffix->size(), *suffix) == 0) {
            return true;
        }
    }
    return false;
}