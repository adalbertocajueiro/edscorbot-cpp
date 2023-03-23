# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /snap/cmake/1271/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1271/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adalberto/Downloads/tmp/edscorbot-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adalberto/Downloads/tmp/edscorbot-cpp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/snap/cmake/1271/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/snap/cmake/1271/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/adalberto/Downloads/tmp/edscorbot-cpp/CMakeFiles /home/adalberto/Downloads/tmp/edscorbot-cpp//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/adalberto/Downloads/tmp/edscorbot-cpp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named mocked_server

# Build rule for target.
mocked_server: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mocked_server
.PHONY : mocked_server

# fast build rule for target.
mocked_server/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mocked_server.dir/build.make CMakeFiles/mocked_server.dir/build
.PHONY : mocked_server/fast

#=============================================================================
# Target rules for targets named tests_json

# Build rule for target.
tests_json: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tests_json
.PHONY : tests_json

# fast build rule for target.
tests_json/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tests_json.dir/build.make CMakeFiles/tests_json.dir/build
.PHONY : tests_json/fast

src/mqtt-server/mocked_server.o: src/mqtt-server/mocked_server.cpp.o
.PHONY : src/mqtt-server/mocked_server.o

# target to build an object file
src/mqtt-server/mocked_server.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mocked_server.dir/build.make CMakeFiles/mocked_server.dir/src/mqtt-server/mocked_server.cpp.o
.PHONY : src/mqtt-server/mocked_server.cpp.o

src/mqtt-server/mocked_server.i: src/mqtt-server/mocked_server.cpp.i
.PHONY : src/mqtt-server/mocked_server.i

# target to preprocess a source file
src/mqtt-server/mocked_server.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mocked_server.dir/build.make CMakeFiles/mocked_server.dir/src/mqtt-server/mocked_server.cpp.i
.PHONY : src/mqtt-server/mocked_server.cpp.i

src/mqtt-server/mocked_server.s: src/mqtt-server/mocked_server.cpp.s
.PHONY : src/mqtt-server/mocked_server.s

# target to generate assembly for a file
src/mqtt-server/mocked_server.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mocked_server.dir/build.make CMakeFiles/mocked_server.dir/src/mqtt-server/mocked_server.cpp.s
.PHONY : src/mqtt-server/mocked_server.cpp.s

src/tests/test_json.o: src/tests/test_json.cpp.o
.PHONY : src/tests/test_json.o

# target to build an object file
src/tests/test_json.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tests_json.dir/build.make CMakeFiles/tests_json.dir/src/tests/test_json.cpp.o
.PHONY : src/tests/test_json.cpp.o

src/tests/test_json.i: src/tests/test_json.cpp.i
.PHONY : src/tests/test_json.i

# target to preprocess a source file
src/tests/test_json.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tests_json.dir/build.make CMakeFiles/tests_json.dir/src/tests/test_json.cpp.i
.PHONY : src/tests/test_json.cpp.i

src/tests/test_json.s: src/tests/test_json.cpp.s
.PHONY : src/tests/test_json.s

# target to generate assembly for a file
src/tests/test_json.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tests_json.dir/build.make CMakeFiles/tests_json.dir/src/tests/test_json.cpp.s
.PHONY : src/tests/test_json.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... mocked_server"
	@echo "... tests_json"
	@echo "... src/mqtt-server/mocked_server.o"
	@echo "... src/mqtt-server/mocked_server.i"
	@echo "... src/mqtt-server/mocked_server.s"
	@echo "... src/tests/test_json.o"
	@echo "... src/tests/test_json.i"
	@echo "... src/tests/test_json.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
