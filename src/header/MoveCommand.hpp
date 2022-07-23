#pragma once

#include <iostream>
#include "Command.hpp"

/**
 * The Command interface declares a method for executing a command.
 */
class MoveCommand :public Command {
 public:
  explicit MoveCommand(std::string file, std::string directory); 

  int Execute() const override;

  private:
  std::string m_file;
  std::string m_directory;
};