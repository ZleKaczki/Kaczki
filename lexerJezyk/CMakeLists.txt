cmake_minimum_required(VERSION 3.23)
project(lexerJezyk)

set(CMAKE_CXX_STANDARD 14)

add_executable(lexerJezyk main.cpp lexer.cpp parser.cpp)