#pragma once

#include <iostream>
#include "Command.hpp"

/**
 * Class that execute the Disk Usage command.
 */
class DiskUsageCommand :public Command {
 public:

 /**
  * @brief Construct a new Disk Usage Command object
  * 
  * @param payLoad - options of the command
  * @param file - where to write the output of the Disk Usage command
  */
  explicit DiskUsageCommand(std::string payLoad, std::string file); 

  /**
   * @brief method that execute the disk usage command
   * 
   * @return int - return 0 success, otherwise insuccesss
   */
  int Execute() const override;

  private:
  std::string m_payLoad;
  std::string m_file;
};



// vmstat -s >> file.txt