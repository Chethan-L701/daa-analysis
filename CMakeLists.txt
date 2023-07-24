cmake_minimum_required(VERSION 3.1)

project(daa LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(include)
add_executable(${PROJECT_NAME} ./src/main.cpp)
