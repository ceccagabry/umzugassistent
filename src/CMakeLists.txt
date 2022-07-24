set(BINARY ${CMAKE_PROJECT_NAME})

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
)

add_executable(${CMAKE_PROJECT_NAME} ../main.cpp)

set(SOURCES ${SOURCES})

find_package(Threads)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  ${CMAKE_PROJECT_NAME}_lib
  ${CMAKE_SOURCE_DIR}/lib/libinotify-cpp.a
  ${CMAKE_THREAD_LIBS_INIT}
)

#add_executable(${BINARY}_run ${SOURCES})

#add_library(${BINARY}_lib STATIC ${SOURCES})