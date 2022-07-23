#include "header/TarCommand.hpp"

#include <ctime>
#include <sstream>

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

// std::string TarCommand::createFileNameTar() const
// {
//     time_t now = time(0);
//     std::tm *ltm = localtime(&now);

//     std::cout << "[TAR_COMMAND] Year:" << 1900 + ltm->tm_year<<std::endl;
//     std::cout << "[TAR_COMMAND] Month: "<< 1 + ltm->tm_mon<< std::endl;
//     std::cout << "[TAR_COMMAND] Day: "<< ltm->tm_mday << std::endl;
//     std::cout << "[TAR_COMMAND] Time: "<< 5+ltm->tm_hour << ":";
//     std::cout << 30+ltm->tm_min << ":";
//     std::cout << ltm->tm_sec << std::endl;

//     std::stringstream fileNameTar;
//     fileNameTar << 1900 + ltm->tm_year << 1 + ltm->tm_mon 
//                             << ltm->tm_mday 
//                             << 5+ltm->tm_hour 
//                             << 30+ltm->tm_min 
//                             << ltm->tm_sec 
//                             << ".tar.gz ";
    
//     std::cout << "[TAR_COMMAND] fileNameTar: " << fileNameTar.str() << std::endl;
//     return fileNameTar.str();
// }