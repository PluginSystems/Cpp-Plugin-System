//
// Created by yannick lamprecht on 10.07.17.
//


#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"

class LoadAndUnloadBenchmark : public TestCase {



public:
    LoadAndUnloadBenchmark(ysl::PluginLoader&pluginLoader) : TestCase(pluginLoader) {}

protected:
    void runTest(unsigned long cycle) override {


        startTimer();
        loader.load();

        loader.unload();
        stopTimer();

        defineBenchmarkPoint(cycle,getName());
        resetTimer();

        sleep(1);
    }

    std::string getName() override {
        return "LoadAndUnloadBenchmark";
    }


};
