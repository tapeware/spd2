cmake_minimum_required(VERSION 3.30)
project(spd2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(spd2
    algorithms.cpp
    algorithms.h
    main.cpp
    Problem.cpp
    Problem.h
    Solution.cpp
    Solution.h
    Task.cpp
    Task.h
    utils.cpp
    utils.h)
