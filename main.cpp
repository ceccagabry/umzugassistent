#include <iostream>
#include <filesystem>
#include <thread>
#include <ctime>
#include <sstream>

#include <unistd.h>
#include <cstdlib>
#include <signal.h>

#include "../lib/libinotify-cpp/include/NotifierBuilder.h"
#include "src/header/FileWatcher.hpp"
#include "src/header/InputParser.hpp"
#include "src/header/RuleMatcher.hpp"
#include "src/header/TarCommand.hpp"
#include "src/header/DiskUsageCommand.hpp"
#include "src/header/MoveCommand.hpp"

using namespace std;
using namespace inotify;

int main(int argc, char** argv)
{
    cout << "[MAIN] Enter the folder: " << argc << " arguments:" << "\n";
       
    //parse the argument and check if the folder is existing
    InputParser input(argc, argv);
    bool retVal = input.checkArguments();
    if (!retVal) {
        cout << "Passed wrong Argument, the folder doesn't exist." << endl 
            << "Please insert a valid folder." << endl;
        return false;
    }

    std::filesystem::path path(argv[1]);

    auto rm = BuildRuleMatcher().beginWith("core.").endWith("lz4").separator(".").regExp("[0-9a-fA-F.]+");
    
    /*FileWatcher fw{"./", std::chrono::milliseconds(5000)};

    // Start monitoring a folder for changes and (in case of changes)
    // run a user provided lambda function
      fw.start([] (std::string path_to_watch, FileStatus status) -> void {
        // Process only regular files, all other file types are ignored
        if(!std::filesystem::is_regular_file(std::filesystem::path(path_to_watch)) && status != FileStatus::erased) {
            return;
        }

        switch(status) {
            case FileStatus::created:
                std::cout << "File created: " << path_to_watch << '\n';
                break;
            case FileStatus::modified:
                std::cout << "File modified: " << path_to_watch << '\n';
                break;
            case FileStatus::erased:
                std::cout << "File erased: " << path_to_watch << '\n';
                break;
            default:
                std::cout << "Error! Unknown file status.\n";
        }
    });*/

  // Set the event handler which will be used to process particular events
  auto handleNotification = [&](Notification notification) {
      std::cout << "[MAIN] Event " << notification.event << " on " << notification.path << " at "
                << notification.time.time_since_epoch().count() << " was triggered." << std::endl;
    
    if(rm.checkRule(notification.path.c_str())) {
        cout << "[MAIN] Rules checked! OK!"<< endl;   

        string payload =  " -h ";
        string fileName = input.getArgument(argumentsNumbers::watchDir) +"/" + "diskUsage.txt";
        string destDirectory = "";
        DiskUsageCommand diskUsageCommand(payload, fileName);
        if(diskUsageCommand.Execute() != 0){
            cout << "[MAIN] diskUsage error" << endl;
            return false;
        }

        payload = "-zcvf ";
        time_t now = time(0);
        std::tm *ltm = localtime(&now);
        std::stringstream fileNameTar;
        fileNameTar << 1900 + ltm->tm_year << 1 + ltm->tm_mon 
                                << ltm->tm_mday 
                                << 5+ltm->tm_hour 
                                << 30+ltm->tm_min 
                                << ltm->tm_sec 
                                << ".tar.gz ";
        
        std::cout << "[MAIN] fileNameTar: " << fileNameTar.str() << std::endl;
        destDirectory = input.getArgument(argumentsNumbers::watchDir);
        TarCommand tarCommand (payload, fileNameTar.str() , destDirectory);
        auto retval = tarCommand.Execute();

        if(tarCommand.Execute() != 0){
            cout << "[MAIN] Tar error" << endl;
            return false;
        }

        destDirectory = input.getArgument(argumentsNumbers::destinationDir);
        MoveCommand moveCommand(fileNameTar.str(), destDirectory);

        if(moveCommand.Execute() != 0) {
            cout << "[MAIN] Move error" << endl;
            return false;
        }

    } else {
        cout << "[MAIN] Rules checked! NOT OK! file discarded"<< endl; 
        return false;
    }
    return true;
  };

  // Set the a separate unexpected event handler for all other events. An exception is thrown by
  // default.
  auto handleUnexpectedNotification = [](Notification notification) {
      std::cout << "[MAIN] Event " << notification.event << " on " << notification.path << " at "
                << notification.time.time_since_epoch().count()
                << " was triggered, but was not expected" << std::endl;
  };

  // Set the events to be notified for
  auto events = { Event::create,
                  Event::move };

  // The notifier is configured to watch the parsed path for the defined events. Particular files
  // or paths can be ignored(once).
  auto notifier = BuildNotifier()
                      .watchPathRecursively(path)
                      .ignoreFileOnce("fileIgnoredOnce")
                      .ignoreFile("fileIgnored")
                      .onEvents(events, handleNotification)
                      .onUnexpectedEvent(handleUnexpectedNotification);

  // The event loop is started in a separate thread context.
  std::thread thread([&](){ notifier.run(); });

  thread.join();

  return 0;
}

