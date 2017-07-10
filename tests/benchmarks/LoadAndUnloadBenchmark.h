//
// Created by yannick lamprecht on 10.07.17.
//


#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"

class LoadAndUnloadBenchmark : public TestCase {


protected:

    void runTest(unsigned long cycle) override {

        std::vector<std::string> endings = {"dylib","so","dll"};

        std::string pluginDir = "plugMeIn";

        ysl::PluginLoader loader(pluginDir, endings);


        startTimer();
        loader.load();

        loader.unload();
        stopTimer();

        defineBenchmarkPoint(cycle,getName());
        resetTimer();
    }

    std::string getName() override {
        return "LoadAndUnloadBenchmark";
    }


};
