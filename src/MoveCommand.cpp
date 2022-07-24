#include "header/MoveCommand.hpp"

// #include <ctime>
// #include <sstream>

MoveCommand::MoveCommand(std::string file, std::string directory)
{
    m_file = file;
    m_directory = directory;
}

int MoveCommand::Execute() const
{  
    // vmstat -s >> file.txt
    std::string command = "mv " + m_file + " " + m_directory;
    std::cout << "[MOVE_COMMAND] command: " << command << std::endl;
    return system (command.c_str());
}