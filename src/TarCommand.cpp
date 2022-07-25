#include "header/TarCommand.hpp"

TarCommand::TarCommand(std::string payLoad, std::string fileName, std::string directory)
{
    m_payLoad = payLoad;
    m_filename = fileName;
    m_directory = directory;
}

int TarCommand::Execute() const
{  
    std::string command = "tar " + m_payLoad + " " + m_filename + " "+ m_directory;
    std::cout << "[TAR_COMMAND] command: " << command << std::endl;
    return system (command.c_str());
}