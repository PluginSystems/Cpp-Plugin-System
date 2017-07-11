cmake_minimum_required(VERSION 3.8.1)
project(Cpp_PluginTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES main.cpp pluginloading/plugins/IPlugin.h pluginloading/PluginLoader.cpp pluginloading/PluginLoader.h utils/StreamPrinter.cpp utils/StreamPrinter.h pluginloading/plugins/IPlugin.cpp files/FileUtils.cpp files/FileUtils.h files/FileReader.h files/FileReader.cpp tests/TestCase.h tests/BenchmarkRun.h tests/BenchmarkRun.cpp tests/util/Stopwatch.h tests/util/Stopwatch.cpp tests/benchmarks/LoadAndUnloadBenchmark.h tests/benchmarks/EnableAndDisableBenchmark.h)
add_executable(Cpp_PluginTest ${SOURCE_FILES})


set(LIBRARY_SOURCES TestPlugin.cpp pluginloading/plugins/IPlugin.cpp)

add_library(Cpp_PluginTest_lib SHARED ${LIBRARY_SOURCES})

if (CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(Cpp_PluginTest dl)
endif (CMAKE_COMPILER_IS_GNUCXX)
