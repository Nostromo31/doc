cmake_minimum_required(VERSION 3.5)

project(pr1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(pr1 main.cpp)
add_executable(pr1 main.cpp
    pr1.cpp
    pr1.h
    )
