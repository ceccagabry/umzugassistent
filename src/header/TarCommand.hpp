#pragma once

#include <iostream>
#include "Command.hpp"

/**
 * The Command interface declares a method for executing a command.
 */
class TarCommand :public Command {
 public:
  explicit TarCommand(std::string payLoad, std::string filename, std::string directory); 

  int Execute() const override;
  std::string getFileNameTar();

  private:

  std::string createFileNameTar() const; 
  
  std::string m_payLoad;
  std::string m_filename;
  std::string m_directory;
};
