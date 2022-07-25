#pragma once

/**
 * @brief The Command interface declares a method for executing a command.
 * 
 */
class Command {
 public:

 /**
  * @brief Destroy the Command object
  * 
  */
  virtual ~Command() {
  }

  /**
   * @brief Function that implements the execution of a command
   * 
   * @return int - result of the operation done
   */
  virtual int Execute() const = 0;
};