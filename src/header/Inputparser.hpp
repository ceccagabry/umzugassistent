#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>
#include <vector>
#include <inotify-cpp/FileSystemAdapter.h>

using namespace std;
namespace fs = std::filesystem;

enum argumentsNumbers {watchDir, destinationDir};

class InputParser
{
public:
    InputParser (int &argc, char **argv);
    bool checkArguments();
    bool checkFolder (const fs::path& p);
    string getArgument (int argNum);
private:
    vector <string> arguments; //rename in parameters
};

#endif // INPUTPARSER_H
