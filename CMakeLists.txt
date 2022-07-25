cmake_minimum_required(VERSION 3.5)

project(DataCollector)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
include_directories(lib/libinotify-cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.8.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(unitTest)