add_library(${CMAKE_PROJECT_NAME}_lib 
InputParser.cpp 
header/InputParser.hpp 
RuleMatcher.cpp 
header/RuleMatcher.hpp
header/Command.hpp
TarCommand.cpp
header/TarCommand.hpp
DiskUsageCommand.cpp
header/DiskUsageCommand.hpp
MoveCommand.cpp
header/MoveCommand.hpp
../lib/libinotify-cpp/include
)

target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC ${CMAKE_SOURCE_DIR}/lib/libinotify-cpp)

add_executable(${CMAKE_PROJECT_NAME} ../main.cpp)

set(SOURCES ${SOURCES})

find_package(Threads)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  ${CMAKE_PROJECT_NAME}_lib
  ${CMAKE_SOURCE_DIR}/lib/libinotify-cpp/libinotify-cpp.a
  ${CMAKE_THREAD_LIBS_INIT}
)