cmake_minimum_required(VERSION 3.20.0)
project(math)

set(CMAKE_C_STANDARD 11)

add_subdirectory(include)
include_directories(${CMAKE_SOURCE_DIR}/include/) 

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} include)