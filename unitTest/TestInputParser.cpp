#include "header/InputParser.hpp"
#include <gtest/gtest.h>

TEST(TestInputParser, test_checkArguments_true) {
    system("mkdir dir1");
    int numParams = 2;
    int &argc = numParams; 
    char *argv[] = {(char*)"", (char*)"dir1"};
    InputParser input(argc, argv);
    ASSERT_EQ(input.checkArguments(), true);
}

TEST(TestInputParser, test_checkArguments_false) {
    int numParams = 2;
    int &argc = numParams; 
    char *argv[] = {(char*)"", (char*)"dir3"};
    InputParser input1(argc, argv);
    ASSERT_EQ(input1.checkArguments(), false);
}

TEST(TestInputParser, test_getArgument_true) {
    int numParams = 2;
    int &argc = numParams; 
    char *argv[] = {(char*)"", (char*)"dir1"};
    InputParser input(argc, argv);
    std::string tmpArgument = "dir1"; 
    ASSERT_EQ(input.getArgument(argumentsNumbers::watchDir), tmpArgument);
}

TEST(TestInputParser, test_getArgument_false) {
    int numParams = 2;
    int &argc = numParams; 
    char *argv[] = {(char*)"", (char*)"dir1"};
    InputParser input(argc, argv);
    std::string tmpArgument = ""; 
    ASSERT_EQ(input.getArgument(3), tmpArgument);
}