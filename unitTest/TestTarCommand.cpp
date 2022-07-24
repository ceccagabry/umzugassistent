#include "header/TarCommand.hpp"
#include <gtest/gtest.h>

TEST(TestTarCommand, test_execute_true) 
{
    std::string payload = "-zcvf ";
    std::string fileNameTar =  "file.tar.gz ";
    std::string destDirectory = " dir1";
    TarCommand tarCommand (payload, fileNameTar, destDirectory);

    ASSERT_EQ(tarCommand.Execute(), 0);
}

TEST(TestTarCommand, test_execute_false) 
{
    std::string payload = "-zcvf ";
    std::string fileNameTar =  "file.tar.gz ";
    std::string destDirectory = " dir3";
    TarCommand tarCommand (payload, fileNameTar, destDirectory);

    ASSERT_NE(tarCommand.Execute(), 0);
}