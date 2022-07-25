#include "header/InputParser.hpp"
#include <regex>

InputParser::InputParser(int &argc, char **argv)
{
    cout << "[INPUT_PARSER] You have entered " << argc
         << " arguments:" << "\n";

    for (int i=1; i < argc; ++i)
    {
        cout << argv[i] << "\n";
        this->arguments.push_back(std::string(argv[i]));
    }
}

bool InputParser::checkArguments()
{
    for (int i= 0; i < arguments.size(); i++)
    {
        const fs::path directoryPath {arguments.at(i)};
        bool isFolderExisting = checkFolder(directoryPath);
        if(!isFolderExisting)
        {
            cout << "[INPUT_PARSER] The directory doesn't exist." << endl;
            return false;
        }
        else
        {
            cout << "[INPUT_PARSER] The directory exist." << endl;
        }
    }
    return true;
}

bool InputParser::checkFolder (const fs::path& path)
{    
    if(fs::exists(path))
        return true;
    else
        return false;
    
}

string InputParser::getArgument (int argNum)
{
    if (argNum > arguments.size()) {
        cout << "[INPUT_PARSER] Error, this argument is not present!" << endl;
        return "";
    }

    return arguments.at(argNum);
}
