#include "header/CommandExecuter.hpp"
#include <bits/stdc++.h> 


CommandExecuter::CommandExecuter ()
{}

bool CommandExecuter::executeCommand (string fileName, string directorySrc, string directoryDest ,ExecutableCommands command)
{
    string cmd = "";
    int retval = 0;
    switch (command)
    {
    
    case store:
        cmd = "tar -zcvf file.tar.gz " + directorySrc + " " + fileName;
        retval = system (cmd.c_str());
        break;

    case moveFile: 
        cmd = "mv" + directorySrc + "/file.tar.gz" + " " + directoryDest + "/file.tar.gz";
        retval = system (cmd.c_str());
        break;
    
    case enterDir:
        cmd = "cd " + directoryDest;
        retval = system (cmd.c_str());
        break;

    default:
        break;
    }
    
    if (retval > 0) {
        return true;
    } else {
        return false;
    }
}
