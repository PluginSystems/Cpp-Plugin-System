//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef CPP_PLUGINTEST_CONTEXTSWITCHBENCHMARK_H
#define CPP_PLUGINTEST_CONTEXTSWITCHBENCHMARK_H


#include "../TestCase.h"
#include "../../pluginloading/PluginLoader.h"
#include "../../StringFace.h"

class ContextSwitchBenchmark : public TestCase {


private:
    std::shared_ptr<StringFace> _face;

public:
    ContextSwitchBenchmark(ysl::PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

    void setUp() override {
        loader.load();
        loader.enable();
        std::shared_ptr<IPlugin> plugin = loader.getPlugin("TestPlugin");
        _face= std::dynamic_pointer_cast<StringFace>(plugin);


    }

    void tearDown() override {
        loader.disable();
        loader.unload();
    }

    const std::string getName() override {
        return "ContextSwitchBenchmark";
    }

protected:
    void runTest(unsigned long cycle) override {




            startTimer();

            if(_face){
                _face->test();
            }

            stopTimer();
            defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
            resetTimer();
    }

};

#endif //CPP_PLUGINTEST_CONTEXTSWITCHBENCHMARK_H
