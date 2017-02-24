cmake_minimum_required(VERSION 3.6)
project(Cpp_PluginTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pluginloading/IPlugin.h pluginloading/MPluginLoader.cpp test/Test1.cpp TestPlugin.cpp files/WinFileReader.cpp files/UnixFileReader.cpp files/UniFileReader.h)
add_executable(Cpp_PluginTest ${SOURCE_FILES})