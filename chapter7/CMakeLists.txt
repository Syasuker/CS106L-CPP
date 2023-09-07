cmake_minimum_required(VERSION 3.26)
project(chapter7)

set(CMAKE_CXX_STANDARD 17)

add_executable(chapter7 main.cpp
        main1_average.cpp
        main2_sort.cpp
        main3_remove.cpp
        strutils.h
        main4_palindrome.cpp)
