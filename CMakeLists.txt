cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "cpp_engine/src/*.cpp")

add_executable(snake ${SOURCES})


target_include_directories(snake PRIVATE "cpp_engine/include")


target_link_options(snake PRIVATE -mconsole)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets" 
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")