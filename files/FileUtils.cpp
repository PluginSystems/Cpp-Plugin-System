//
// Created by yannick lamprecht on 01.03.17.
//

#include "FileUtils.h"


int FileUtils::isFile(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

bool FileUtils::endsWith(const std::string str, const std::vector<std::string> suffix) {
    if (suffix.size() == 0)return true;

    for (std::string sf: suffix) {
        if (str.size() >= sf.size() &&
            str.compare(str.size() - sf.size(), sf.size(), sf) == 0) {
            return true;
        }
    }
    return false;
}