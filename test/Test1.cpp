//
// Created by yannick lamprecht on 24.02.17.
//


#include <functional>
#include <iostream>

using namespace std;

class Test1{

public:

    void hey(function<void(string)> callbackMe){

        cout << "Hey du" << endl;

        callbackMe("Hey");
    }


};
