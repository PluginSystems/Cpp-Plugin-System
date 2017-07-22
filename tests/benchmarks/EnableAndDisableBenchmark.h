//
// Created by yannick lamprecht on 10.07.17.
//

#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"

#ifndef CPP_PLUGINTEST_ENABLEANDDISABLEBENCHMARK_H
#define CPP_PLUGINTEST_ENABLEANDDISABLEBENCHMARK_H

#endif //CPP_PLUGINTEST_ENABLEANDDISABLEBENCHMARK_H

class EnableAndDisableBenchmark : public TestCase {


public:
    EnableAndDisableBenchmark(ysl::PluginLoader& pluginLoader) : TestCase(pluginLoader) {

    }

    void setUp() override {
        loader.load();
    }

    void tearDown() override {
        loader.unload();
    }

    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }

protected:
    void runTest(unsigned long cycle) override {


        startTimer();

        loader.enable();

        loader.disable();

        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();
    }




};