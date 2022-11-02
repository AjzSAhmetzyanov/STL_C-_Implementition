cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(List)

add_executable(src
            Map/iterator.h
            Map/red_black_tree.h
            Map/s21_map.h
            Map/test.cc
        )
