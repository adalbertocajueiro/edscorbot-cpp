# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1277/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1277/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adalberto/Downloads/tmp/edscorbot-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adalberto/Downloads/tmp/edscorbot-cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/tests_json.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests_json.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests_json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests_json.dir/flags.make

CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o: CMakeFiles/tests_json.dir/flags.make
CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o: /home/adalberto/Downloads/tmp/edscorbot-cpp/src/tests/test_json.cpp
CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o: CMakeFiles/tests_json.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adalberto/Downloads/tmp/edscorbot-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o -MF CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o.d -o CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o -c /home/adalberto/Downloads/tmp/edscorbot-cpp/src/tests/test_json.cpp

CMakeFiles/tests_json.dir/src/tests/test_json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests_json.dir/src/tests/test_json.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adalberto/Downloads/tmp/edscorbot-cpp/src/tests/test_json.cpp > CMakeFiles/tests_json.dir/src/tests/test_json.cpp.i

CMakeFiles/tests_json.dir/src/tests/test_json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests_json.dir/src/tests/test_json.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adalberto/Downloads/tmp/edscorbot-cpp/src/tests/test_json.cpp -o CMakeFiles/tests_json.dir/src/tests/test_json.cpp.s

# Object files for target tests_json
tests_json_OBJECTS = \
"CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o"

# External object files for target tests_json
tests_json_EXTERNAL_OBJECTS =

tests_json: CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o
tests_json: CMakeFiles/tests_json.dir/build.make
tests_json: CMakeFiles/tests_json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adalberto/Downloads/tmp/edscorbot-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests_json"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests_json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests_json.dir/build: tests_json
.PHONY : CMakeFiles/tests_json.dir/build

CMakeFiles/tests_json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests_json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests_json.dir/clean

CMakeFiles/tests_json.dir/depend:
	cd /home/adalberto/Downloads/tmp/edscorbot-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adalberto/Downloads/tmp/edscorbot-cpp /home/adalberto/Downloads/tmp/edscorbot-cpp /home/adalberto/Downloads/tmp/edscorbot-cpp/build /home/adalberto/Downloads/tmp/edscorbot-cpp/build /home/adalberto/Downloads/tmp/edscorbot-cpp/build/CMakeFiles/tests_json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests_json.dir/depend

