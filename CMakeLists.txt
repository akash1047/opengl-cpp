cmake_minimum_required(VERSION 3.20)

project(OpenglCpp)

add_library(${PROJECT_NAME} src/lib.cpp src/gl.c)

target_include_directories(${PROJECT_NAME} PUBLIC "include")
