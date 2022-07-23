set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false header/*.h *.cpp)

set(SOURCES ${TEST_SOURCES})

#add_executable(${BINARY} ${TEST_SOURCES})
add_executable(
  ${BINARY} 
  main.cpp
  TestRuleMatcher.cpp
)

include(FetchContent)
FetchContent_Declare(googletest)

include(GoogleTest)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(
  ${BINARY}
  ${CMAKE_PROJECT_NAME}_lib
  gmock
  gtest
  gtest_main
)

enable_testing()

# add_executable(
#   hello_test
#   hello_test.cpp
#   TestRuleMatcher
#   TestRuleMatcher.cpp
# )
# target_link_libraries(
#   hello_test
#   TestRuleMatcher
#   GTest::gtest_main
# )


# gtest_discover_tests(TestRuleMatcher)