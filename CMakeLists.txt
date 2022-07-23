cmake_minimum_required(VERSION 3.5)

project(DataCollector)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_subdirectory(src)
add_subdirectory(unitTest)
add_subdirectory(lib/googletest)