cmake_minimum_required(VERSION 3.26)
project(chapter4)

set(CMAKE_CXX_STANDARD 17)

add_executable(chapter4 main.cpp
        strutils.h
        strutils.cpp
        color.h
        untils.h
        mathUtils.h
        mathUtils.cpp
)
