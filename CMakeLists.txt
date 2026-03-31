cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(cpp_engine/include)

file(GLOB SOURCES
    cpp_engine/src/*.cpp
)

add_executable(snake ${SOURCES})
target_link_options(snake PRIVATE -mconsole)
