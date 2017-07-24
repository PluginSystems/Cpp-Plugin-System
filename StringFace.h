//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef CPP_PLUGINTEST_STRINGFACE_H
#define CPP_PLUGINTEST_STRINGFACE_H


#include <string>

class StringFace {

public:

    virtual void printMessage(std::string message)=0;

    virtual std::string modifyMessage(std::string message)=0;


};


#endif //CPP_PLUGINTEST_STRINGFACE_H
