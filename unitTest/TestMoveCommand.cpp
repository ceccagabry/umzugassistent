#include "header/MoveCommand.hpp"
#include <gtest/gtest.h>

TEST(TestMoveCommand, test_execute_true) 
{
    
    std::string fileName = "file.txt";
    std::string createFileCmd = "touch " + fileName;
    system(createFileCmd.c_str());
    system("mkdir dir2");
    std::string destDirectory = "dir2";
    MoveCommand moveCommand(fileName, destDirectory);

    ASSERT_EQ(moveCommand.Execute(), 0);
}

TEST(TestMoveCommand, test_execute_false) 
{
    std::string fileName = "file1.txt";
    std::string destDirectory = "dir2";
    MoveCommand moveCommand(fileName, destDirectory);

    ASSERT_NE(moveCommand.Execute(), 0);
}