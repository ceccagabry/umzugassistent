#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>
#include "../lib/libinotify-cpp/include/FileSystemAdapter.h"

using namespace std;
namespace fs = std::filesystem;

enum argumentsNumbers {watchDir, destinationDir};

/**
 * @brief class that check the input 
 * 
 */
class InputParser
{
public:
    /**
     * @brief Construct a new Input Parser object
     * 
     * @param argc - numbers of arguments passed
     * @param argv - argument passed
     */
    InputParser (int &argc, char **argv);

    /**
     * @brief Check if the arguments passed are well formed
     * 
     * @return true - arguments well formed
     * @return false - argument not well formed
     */
    bool checkArguments();

    /**
     * @brief Get the Argument object
     * 
     * @param argNum - this is the index of the argument 
     * @return string - the argument at the passed index if exists
     */
    string getArgument (int argNum);
private:

    /**
     * @brief Check if the passed parameter is an existing folder
     * 
     * @param p - the path/to/dir
     * @return true - if the path exists in the file system
     * @return false - if the path doen't exists in the file system
     */
    bool checkFolder (const fs::path& p);

    vector <string> arguments; //rename in parameters
};

#endif // INPUTPARSER_H
