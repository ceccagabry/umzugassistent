#pragma once

#include <iostream>
#include "Command.hpp"

/**
 * Class that implements the move command.
 */
class MoveCommand :public Command {
 public:

 /**
  * @brief Construct a new Move Command object
  * 
  * @param file - file to move
  * @param directory - directory where to move the file 
  */
  explicit MoveCommand(std::string file, std::string directory); 

  /**
   * @brief method that execute the move command
   * 
   * @return int - return 0 success, otherwise insuccesss
   */
  int Execute() const override;

  private:
  std::string m_file;
  std::string m_directory;
};