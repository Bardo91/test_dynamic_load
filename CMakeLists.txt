cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(test_dyn_load LANGUAGES CXX)

add_definitions(-std=c++17)

add_library(library SHARED library.cpp)
target_include_directories(library PUBLIC ./)


add_library(ext_lib SHARED ext_lib.cpp)
target_link_libraries(ext_lib LINK_PUBLIC library)


add_executable(dyn_load main.cpp)
target_link_libraries(dyn_load LINK_PUBLIC library)
target_link_libraries(dyn_load LINK_PUBLIC dl)