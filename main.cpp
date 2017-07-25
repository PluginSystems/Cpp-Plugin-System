#include <iostream>
#include <vector>
#include <thread>
#include <fstream>
#include "pluginloading/PluginLoader.h"
#include "tests/TestCase.h"
#include "tests/benchmarks/LoadAndUnloadBenchmark.h"
#include "tests/benchmarks/EnableAndDisableBenchmark.h"
#include "tests/benchmarks/ContextSwitchBenchmark.h"
#include "tests/benchmarks/ContextSwitchReturnTypeBenchmark.h"

int main() {


    std::list<std::shared_ptr<TestCase>> benchmarks;


    ysl::PluginLoader loader("plugMeIn", {"dylib", "so", "dll"});


    benchmarks.push_back(std::make_shared<LoadAndUnloadBenchmark>(LoadAndUnloadBenchmark(loader)));
    benchmarks.push_back(std::make_shared<EnableAndDisableBenchmark>(EnableAndDisableBenchmark(loader)));
    benchmarks.push_back(std::make_shared<ContextSwitchBenchmark>(ContextSwitchBenchmark(loader)));
    benchmarks.push_back(std::make_shared<ContextSwitchReturnTypeBenchmark>(ContextSwitchReturnTypeBenchmark(loader)));


    std::list<unsigned long> rounds = {10, 50, 70, 100, 250};

    long time = std::chrono::system_clock::now().time_since_epoch().count();

    for (auto count : rounds) {

        for (std::shared_ptr<TestCase> testCase: benchmarks) {
            testCase->setUp();
            testCase->runTestFully(count);
            testCase->tearDown();
            std::cout << "Test run finished" << std::endl;
        }


        for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {

            std::ofstream resultFileStream;

            std::stringstream fileName;


            fileName << "results_" << finishedBenchmark->getName() << "_nanoseconds_" << count << "_"
                     << time << ".csv";


            resultFileStream.open(fileName.str());

            finishedBenchmark->printStats(resultFileStream);

            resultFileStream.close();
        }
    }
    benchmarks.clear();


    return 0;
}