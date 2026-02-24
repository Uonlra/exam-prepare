cmake_minimum_required(VERSION 4.1)
project(codespce)

set(CMAKE_CXX_STANDARD 14)

add_executable(codespce
        main.cpp
        exercise.cpp)

add_executable(codespce_test
        test_runner.cpp
        exercise.cpp)
