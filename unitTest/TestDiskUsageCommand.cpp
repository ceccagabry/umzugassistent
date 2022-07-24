#include "header/DiskUsageCommand.hpp"
#include <gtest/gtest.h>

TEST(TestDiskUsageCommand, test_execute_true) 
{
    std::string payload = "-h ";
    std::string fileName = "diskUsage.txt";
    DiskUsageCommand diskUsageCommand(payload, fileName);

    ASSERT_EQ(diskUsageCommand.Execute(), 0);
}

TEST(TestDiskUsageCommand, test_execute_false) 
{
    std::string payload = "-g";
    std::string fileName = "diskUsage.txt";
    DiskUsageCommand diskUsageCommand(payload, fileName);

    ASSERT_NE(diskUsageCommand.Execute(), 0);
}