cmake_minimum_required(VERSION 3.6)
project(Cpp_PluginTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pluginloading/plugins/IPlugin.h pluginloading/PluginLoader.cpp test/Test1.cpp pluginloading/plugins/TestPlugin.cpp files/FileReader.cpp files/FileReader.h pluginloading/PluginManager.cpp pluginloading/PluginManager.h pluginloading/PluginLoader.h StreamPrinter.cpp StreamPrinter.h pluginloading/plugins/IPlugin.cpp files/FileUtils.cpp files/FileUtils.h)
add_executable(Cpp_PluginTest ${SOURCE_FILES})