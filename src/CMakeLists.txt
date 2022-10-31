cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(List)

add_executable(src
           List/s21_list.h
           List/test.cc
        )
