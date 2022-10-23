cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(Set)

add_executable(src
        Set/compare.h
        Set/iterator.h
        Set/rb_tree.h
        Set/rb_tree_node.h
        Set/s21_set.h
        Set/test.cc
        tests/set_tests.cc)
