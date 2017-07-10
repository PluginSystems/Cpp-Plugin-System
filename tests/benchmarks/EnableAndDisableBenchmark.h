//
// Created by yannick lamprecht on 10.07.17.
//

#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"

#ifndef CPP_PLUGINTEST_ENABLEANDDISABLEBENCHMARK_H
#define CPP_PLUGINTEST_ENABLEANDDISABLEBENCHMARK_H

#endif //CPP_PLUGINTEST_ENABLEANDDISABLEBENCHMARK_H

class EnableAndDisableBenchmark : public TestCase {


protected:

    void runTest(unsigned long cycle) override {

        std::vector<std::string> endings = {"dylib", "so", "dll"};

        std::string pluginDir = "plugMeIn";

        ysl::PluginLoader loader(pluginDir, endings);


        loader.load();

        startTimer();

        loader.enable();

        loader.disable();

        stopTimer();
        defineBenchmarkPoint(cycle, getName());
        resetTimer();

        loader.unload();


    }

    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }

};