#include <iostream>
#include <vector>
#include <thread>
#include "pluginloading/PluginLoader.h"
#include "tests/TestCase.h"
#include "tests/benchmarks/LoadAndUnloadBenchmark.h"
#include "tests/benchmarks/EnableAndDisableBenchmark.h"

int main() {


    std::list<std::shared_ptr<TestCase>> benchmarks;


    ysl::PluginLoader loader("plugMeIn", {"dylib", "so", "dll"});


    benchmarks.push_back(std::make_shared<LoadAndUnloadBenchmark>(LoadAndUnloadBenchmark(loader)));
    benchmarks.push_back(std::make_shared<EnableAndDisableBenchmark>(EnableAndDisableBenchmark(loader)));


    unsigned long count = 1000;

        for (std::shared_ptr<TestCase> testCase: benchmarks) {
            testCase->setUp();
            testCase->runTestFully(count);
            testCase->tearDown();
            std::cout << "Test run finished" << std::endl;
        }

    std::ostream &out = std::cout;



    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {
        finishedBenchmark->printStats(out);
    }
    benchmarks.clear();


    return 0;
}