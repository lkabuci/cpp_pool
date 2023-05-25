cmake_minimum_required(VERSION 3.26.3)
project(learnCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(lCpp
        learnCpp/main.cpp learnCpp/utils.cpp)

target_compile_options(lCpp PRIVATE -Wall -Wextra -std=c++98)

