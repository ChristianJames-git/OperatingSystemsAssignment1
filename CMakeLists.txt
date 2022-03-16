cmake_minimum_required(VERSION 3.20)
project(IntroProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(IntroProject main.cpp dictionary.cpp dictionary.h dictNode.cpp dictNode.h)
