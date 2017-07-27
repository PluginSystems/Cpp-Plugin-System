//
// Created by yannick lamprecht on 10.07.17.
//


#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"

class LoadAndUnloadBenchmark : public TestCase {



public:
    LoadAndUnloadBenchmark(ysl::PluginLoader&pluginLoader) : TestCase(pluginLoader) {}


    const std::string getName() override {
        return "LoadAndUnloadBenchmark";
    }

protected:
    void runTest(unsigned long cycle) override {


            startTimer();
            loader.load();

            loader.unload();
            stopTimer();

            defineBenchmarkPoint(cycle,getName()+"_"+std::to_string(cycle+1));
            resetTimer();

    }




};
