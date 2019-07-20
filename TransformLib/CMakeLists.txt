cmake_minimum_required(VERSION 2.8)

project(TransformLib)

include_directories("headers")

add_executable(${PROJECT_NAME} main.cpp
    src/matrix.cpp
    src/utilities.cpp

    headers/matrix.h
    headers/utilities.h

)
