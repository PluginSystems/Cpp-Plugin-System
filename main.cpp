#include <iostream>
#include <vector>
#include <thread>
#include "pluginloading/PluginLoader.h"
#include "tests/TestCase.h"
#include "tests/benchmarks/LoadAndUnloadBenchmark.h"
#include "tests/benchmarks/EnableAndDisableBenchmark.h"

int main() {


    std::list<std::shared_ptr<TestCase>> benchmarks;


    benchmarks.push_back(std::shared_ptr<TestCase>(new LoadAndUnloadBenchmark()));
    benchmarks.push_back(std::shared_ptr<TestCase>(new EnableAndDisableBenchmark()));


    int count = 100;

    for (std::shared_ptr<TestCase> testCase: benchmarks) {
        testCase->runTestFully(count);
        std::cout << "Test run finished" << std::endl;
    }


    std::ostream &out = std::cout;


    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {
        finishedBenchmark->printStats(out);
    }



    return 0;
}