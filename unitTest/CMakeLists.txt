set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false header/*.h *.cpp)

set(SOURCES ${TEST_SOURCES})

#add_executable(${BINARY} ${TEST_SOURCES})
add_executable(
  ${BINARY} 
  main.cpp
  TestRuleMatcher.cpp
  TestInputParser.cpp
  TestDiskUsageCommand.cpp
  TestMoveCommand.cpp
  TestTarCommand.cpp
)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(main main.cpp)
target_link_libraries(main gtest_main)
add_test(NAME main_test COMMAND main)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(
  ${BINARY}
  ${CMAKE_PROJECT_NAME}_lib
  gmock
  gtest
  gtest_main
)

enable_testing()