cmake_minimum_required(VERSION 3.31.0)

project(AOC2024
        LANGUAGES CXX
)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(${PROJECT_NAME} main.cpp)

