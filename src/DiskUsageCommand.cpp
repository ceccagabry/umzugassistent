#include "header/DiskUsageCommand.hpp"

// #include <ctime>
// #include <sstream>

DiskUsageCommand::DiskUsageCommand(std::string payLoad, std::string file)
{
    m_payLoad = payLoad;
    m_file = file;
}

int DiskUsageCommand::Execute() const
{  
    // vmstat -s >> file.txt
    std::string command = "> "  + m_file + " | " + "df " + m_payLoad + " >> " + m_file;
    std::cout << "[DISK_USAGE_COMMAND] command: " << command << std::endl;
    return system (command.c_str());
}