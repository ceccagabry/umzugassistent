#pragma once

#include <iostream>
#include "Command.hpp"

/**
 * The Command interface declares a method for executing a command.
 */
class DiskUsageCommand :public Command {
 public:
  explicit DiskUsageCommand(std::string payLoad, std::string file); 

  int Execute() const override;

  private:
  std::string m_payLoad;
  std::string m_file;
};



// vmstat -s >> file.txt