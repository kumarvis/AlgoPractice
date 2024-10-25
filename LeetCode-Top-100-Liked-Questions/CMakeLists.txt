cmake_minimum_required(VERSION 3.13)  # CMake version check
project(leet_code_practice)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(leet_code_practice ${SOURCE_FILES})