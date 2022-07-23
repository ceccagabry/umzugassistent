#include <iostream>

using namespace std;

// Define available file changes
enum ExecutableCommands {store, moveFile, enterDir};

class CommandExecuter
{
public:
    CommandExecuter ();
    bool executeCommand (string fileName, string directorySrc, string directoryDest ,ExecutableCommands command);
};