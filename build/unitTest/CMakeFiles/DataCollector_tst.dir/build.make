# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gabriella/MyProject/umzugassistent

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabriella/MyProject/umzugassistent/build

# Include any dependencies generated for this target.
include unitTest/CMakeFiles/DataCollector_tst.dir/depend.make

# Include the progress variables for this target.
include unitTest/CMakeFiles/DataCollector_tst.dir/progress.make

# Include the compile flags for this target's objects.
include unitTest/CMakeFiles/DataCollector_tst.dir/flags.make

unitTest/CMakeFiles/DataCollector_tst.dir/main.cpp.o: unitTest/CMakeFiles/DataCollector_tst.dir/flags.make
unitTest/CMakeFiles/DataCollector_tst.dir/main.cpp.o: ../unitTest/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriella/MyProject/umzugassistent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unitTest/CMakeFiles/DataCollector_tst.dir/main.cpp.o"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataCollector_tst.dir/main.cpp.o -c /home/gabriella/MyProject/umzugassistent/unitTest/main.cpp

unitTest/CMakeFiles/DataCollector_tst.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataCollector_tst.dir/main.cpp.i"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriella/MyProject/umzugassistent/unitTest/main.cpp > CMakeFiles/DataCollector_tst.dir/main.cpp.i

unitTest/CMakeFiles/DataCollector_tst.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataCollector_tst.dir/main.cpp.s"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriella/MyProject/umzugassistent/unitTest/main.cpp -o CMakeFiles/DataCollector_tst.dir/main.cpp.s

unitTest/CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.o: unitTest/CMakeFiles/DataCollector_tst.dir/flags.make
unitTest/CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.o: ../unitTest/TestRuleMatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gabriella/MyProject/umzugassistent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object unitTest/CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.o"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.o -c /home/gabriella/MyProject/umzugassistent/unitTest/TestRuleMatcher.cpp

unitTest/CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.i"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabriella/MyProject/umzugassistent/unitTest/TestRuleMatcher.cpp > CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.i

unitTest/CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.s"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabriella/MyProject/umzugassistent/unitTest/TestRuleMatcher.cpp -o CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.s

# Object files for target DataCollector_tst
DataCollector_tst_OBJECTS = \
"CMakeFiles/DataCollector_tst.dir/main.cpp.o" \
"CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.o"

# External object files for target DataCollector_tst
DataCollector_tst_EXTERNAL_OBJECTS =

unitTest/DataCollector_tst: unitTest/CMakeFiles/DataCollector_tst.dir/main.cpp.o
unitTest/DataCollector_tst: unitTest/CMakeFiles/DataCollector_tst.dir/TestRuleMatcher.cpp.o
unitTest/DataCollector_tst: unitTest/CMakeFiles/DataCollector_tst.dir/build.make
unitTest/DataCollector_tst: src/libDataCollector_lib.a
unitTest/DataCollector_tst: lib/libgmock.a
unitTest/DataCollector_tst: lib/libgtest.a
unitTest/DataCollector_tst: lib/libgtest_main.a
unitTest/DataCollector_tst: lib/libgtest.a
unitTest/DataCollector_tst: unitTest/CMakeFiles/DataCollector_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gabriella/MyProject/umzugassistent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DataCollector_tst"
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataCollector_tst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unitTest/CMakeFiles/DataCollector_tst.dir/build: unitTest/DataCollector_tst

.PHONY : unitTest/CMakeFiles/DataCollector_tst.dir/build

unitTest/CMakeFiles/DataCollector_tst.dir/clean:
	cd /home/gabriella/MyProject/umzugassistent/build/unitTest && $(CMAKE_COMMAND) -P CMakeFiles/DataCollector_tst.dir/cmake_clean.cmake
.PHONY : unitTest/CMakeFiles/DataCollector_tst.dir/clean

unitTest/CMakeFiles/DataCollector_tst.dir/depend:
	cd /home/gabriella/MyProject/umzugassistent/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabriella/MyProject/umzugassistent /home/gabriella/MyProject/umzugassistent/unitTest /home/gabriella/MyProject/umzugassistent/build /home/gabriella/MyProject/umzugassistent/build/unitTest /home/gabriella/MyProject/umzugassistent/build/unitTest/CMakeFiles/DataCollector_tst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unitTest/CMakeFiles/DataCollector_tst.dir/depend

