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


    benchmarks.push_back(std::shared_ptr<TestCase>(new LoadAndUnloadBenchmark(loader)));
    benchmarks.push_back(std::shared_ptr<TestCase>(new EnableAndDisableBenchmark(loader)));


    unsigned long count = 20;

    for (std::shared_ptr<TestCase> testCase: benchmarks) {
        testCase->setUp();
        testCase->runTestFully(count);
        testCase->tearDown();
        std::cout << "Test run finished" << std::endl;
        sleep(10);
    }


    std::ostream &out = std::cout;


    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {
        finishedBenchmark->printStats(out);
    }

    benchmarks.clear();


    return 0;
}