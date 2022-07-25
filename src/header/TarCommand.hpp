#pragma once

#include <iostream>
#include "Command.hpp"

/**
 * @brief Class that implements the Tar command
 * 
 */
class TarCommand :public Command {
 public:

 /**
  * @brief Construct a new Tar Command object
  * 
  * @param payLoad - options of the tar command
  * @param filename - name of the tar file
  * @param directory - directory to check to do the tar command
  */
  explicit TarCommand(std::string payLoad, std::string filename, std::string directory); 

  /**
   * @brief method that execute the tar command
   * 
   * @return int - return 0 success, otherwise insuccesss
   */
  int Execute() const override;

  private:

  std::string m_payLoad;
  std::string m_filename;
  std::string m_directory;
};
