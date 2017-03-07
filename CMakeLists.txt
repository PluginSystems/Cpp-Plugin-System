cmake_minimum_required(VERSION 3.6)
project(Cpp_PluginTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pluginloading/plugins/IPlugin.h pluginloading/PluginLoader.cpp pluginloading/PluginLoader.h StreamPrinter.cpp StreamPrinter.h pluginloading/plugins/IPlugin.cpp files/FileUtils.cpp files/FileUtils.h files/FileReader.h files/FileReader.cpp)
add_executable(Cpp_PluginTest ${SOURCE_FILES})


set(LIBRARY_SOURCES TestPlugin.cpp pluginloading/plugins/IPlugin.cpp)

add_library(Cpp_PluginTest_lib SHARED ${LIBRARY_SOURCES})

if (CMAKE_COMPILER_IS_GNUCXXX)
    target_link_libraries(Cpp_PluginTest dl)
endif (CMAKE_COMPILER_IS_GNUCXXX)
