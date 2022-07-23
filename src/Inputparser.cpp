#include "header/Inputparser.hpp"
#include <regex>

InputParser::InputParser(int &argc, char **argv)
{
    cout << "You have entered " << argc
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
            cout << "The directory doesn't exist." << endl;
            return false;
        }
        else
        {
            cout << "The directory exist." << endl;
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
        cout << "Error, this argument is not present!" << endl;
        return nullptr;
    }

    return arguments.at(argNum);
}
