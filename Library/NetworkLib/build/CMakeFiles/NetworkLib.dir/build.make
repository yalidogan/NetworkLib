# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/admin/CLionProjects/test/Library/NetworkLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/admin/CLionProjects/test/Library/NetworkLib/build

# Include any dependencies generated for this target.
include CMakeFiles/NetworkLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/NetworkLib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NetworkLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NetworkLib.dir/flags.make

CMakeFiles/NetworkLib.dir/src/Server.cpp.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/src/Server.cpp.o: ../src/Server.cpp
CMakeFiles/NetworkLib.dir/src/Server.cpp.o: CMakeFiles/NetworkLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/admin/CLionProjects/test/Library/NetworkLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NetworkLib.dir/src/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NetworkLib.dir/src/Server.cpp.o -MF CMakeFiles/NetworkLib.dir/src/Server.cpp.o.d -o CMakeFiles/NetworkLib.dir/src/Server.cpp.o -c /home/admin/CLionProjects/test/Library/NetworkLib/src/Server.cpp

CMakeFiles/NetworkLib.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/src/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/admin/CLionProjects/test/Library/NetworkLib/src/Server.cpp > CMakeFiles/NetworkLib.dir/src/Server.cpp.i

CMakeFiles/NetworkLib.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/src/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/admin/CLionProjects/test/Library/NetworkLib/src/Server.cpp -o CMakeFiles/NetworkLib.dir/src/Server.cpp.s

CMakeFiles/NetworkLib.dir/src/client.cpp.o: CMakeFiles/NetworkLib.dir/flags.make
CMakeFiles/NetworkLib.dir/src/client.cpp.o: ../src/client.cpp
CMakeFiles/NetworkLib.dir/src/client.cpp.o: CMakeFiles/NetworkLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/admin/CLionProjects/test/Library/NetworkLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NetworkLib.dir/src/client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NetworkLib.dir/src/client.cpp.o -MF CMakeFiles/NetworkLib.dir/src/client.cpp.o.d -o CMakeFiles/NetworkLib.dir/src/client.cpp.o -c /home/admin/CLionProjects/test/Library/NetworkLib/src/client.cpp

CMakeFiles/NetworkLib.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/src/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/admin/CLionProjects/test/Library/NetworkLib/src/client.cpp > CMakeFiles/NetworkLib.dir/src/client.cpp.i

CMakeFiles/NetworkLib.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/src/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/admin/CLionProjects/test/Library/NetworkLib/src/client.cpp -o CMakeFiles/NetworkLib.dir/src/client.cpp.s

# Object files for target NetworkLib
NetworkLib_OBJECTS = \
"CMakeFiles/NetworkLib.dir/src/Server.cpp.o" \
"CMakeFiles/NetworkLib.dir/src/client.cpp.o"

# External object files for target NetworkLib
NetworkLib_EXTERNAL_OBJECTS =

libNetworkLib.a: CMakeFiles/NetworkLib.dir/src/Server.cpp.o
libNetworkLib.a: CMakeFiles/NetworkLib.dir/src/client.cpp.o
libNetworkLib.a: CMakeFiles/NetworkLib.dir/build.make
libNetworkLib.a: CMakeFiles/NetworkLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/admin/CLionProjects/test/Library/NetworkLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libNetworkLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/NetworkLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NetworkLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NetworkLib.dir/build: libNetworkLib.a
.PHONY : CMakeFiles/NetworkLib.dir/build

CMakeFiles/NetworkLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NetworkLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NetworkLib.dir/clean

CMakeFiles/NetworkLib.dir/depend:
	cd /home/admin/CLionProjects/test/Library/NetworkLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/CLionProjects/test/Library/NetworkLib /home/admin/CLionProjects/test/Library/NetworkLib /home/admin/CLionProjects/test/Library/NetworkLib/build /home/admin/CLionProjects/test/Library/NetworkLib/build /home/admin/CLionProjects/test/Library/NetworkLib/build/CMakeFiles/NetworkLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NetworkLib.dir/depend

