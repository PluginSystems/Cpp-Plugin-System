//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef CPP_PLUGINTEST_CONTEXTSWITCHBENCHMARK_H
#define CPP_PLUGINTEST_CONTEXTSWITCHBENCHMARK_H


#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"
#include "../../StringFace.h"

class ContextSwitchBenchmark : public TestCase {
public:
    ContextSwitchBenchmark(ysl::PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

    void setUp() override {
        loader.load();
        loader.enable();
    }

    void tearDown() override {
        loader.disable();
        loader.unload();
    }

    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }

protected:
    void runTest(unsigned long cycle) override {


        startTimer();

        std::shared_ptr<IPlugin> plugin = loader.getPlugin("TestPlugin");

        if(StringFace * face = dynamic_cast<StringFace*>(plugin.get())){
            face->printMessage(getName());
        }

        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();
    }

};

#endif //CPP_PLUGINTEST_CONTEXTSWITCHBENCHMARK_H