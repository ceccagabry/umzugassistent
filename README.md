[![CircleCI](https://circleci.com/gh/ceccagabry/umzugassistent/tree/main.svg?style=shield)](https://app.circleci.com/pipelines/github/ceccagabry/umzugassistent?branch=main)

# Umzugassistent - Data collector

## Task
Implement a service that collects system information upon reception of a trigger event.
The trigger event is raised when existence of a file with a certain name in a specified directory is detected.

The following features must be implemented:
* Trigger detection
  * Detect creation of a file in a somehow specified directory
  * Make the directory configurable via commandline parameter
  * Only trigger on files with names following this format:
    * Starts with `core`
    * Ends with `lz4`
    * Contains one or more hexadecimal id separated by dots
    * Example: `core.ServiceName.3057.57dd721409bc4ab4b38a3c33a36a608a.3717.1647975805000000.lz4`
* Collected data shall be:
  * Individual files, as well as whole directories and their contents, recursively, configured via command line parameter
  * Disk usage information in human-readable format of your choice, written to a file that is collected as if it would be in the list specified above
* Store the collected data in a configurable directory, create a `tar`-archive of the aforementioned contents
  * Give the resulting file a unique name.
* Add tests to make sure your application is working,
  * Use gtest for unit tests.
  * Component tests can be written in a language and framework of your choice
    * A component test should check at least if the collection is working and the `tar` file contains the expected data.

## Things to keep in mind
* Implement your collection in a way such that it can be extended to collect other data of various forms later.
* Use modern C++!
* Use the platform of your choice (Linux, BSD, MacOS, Windows, etc.)
  * We use Linux but everything else is cool, too.


## Build Example

     mkdir build && cd build
     cmake ..
     make all

## Dependencies

    lib
        boost 1.54.0
        c++17
        linux 2.6.13
    build
        cmake 3.8

## ToDos

1. Implement a better handling of the input parameters. Idea: Boost.Program_options as the project already depends on Boost
2. Implement an interface (Facade pattern?) to leverage the FileWatcher and INotify mechanisms to check for file creation
3. Refactor the Command approach to task execution. Introduce an Executor which handles an ordered list of commands
