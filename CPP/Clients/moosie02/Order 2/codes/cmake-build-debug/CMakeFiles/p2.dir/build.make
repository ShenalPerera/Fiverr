# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /cygdrive/c/Users/shena/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/shena/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/p2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/p2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p2.dir/flags.make

CMakeFiles/p2.dir/P2/main.cpp.o: CMakeFiles/p2.dir/flags.make
CMakeFiles/p2.dir/P2/main.cpp.o: ../P2/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p2.dir/P2/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p2.dir/P2/main.cpp.o -c "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/P2/main.cpp"

CMakeFiles/p2.dir/P2/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p2.dir/P2/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/P2/main.cpp" > CMakeFiles/p2.dir/P2/main.cpp.i

CMakeFiles/p2.dir/P2/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p2.dir/P2/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/P2/main.cpp" -o CMakeFiles/p2.dir/P2/main.cpp.s

CMakeFiles/p2.dir/P2/menu.cpp.o: CMakeFiles/p2.dir/flags.make
CMakeFiles/p2.dir/P2/menu.cpp.o: ../P2/menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p2.dir/P2/menu.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p2.dir/P2/menu.cpp.o -c "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/P2/menu.cpp"

CMakeFiles/p2.dir/P2/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p2.dir/P2/menu.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/P2/menu.cpp" > CMakeFiles/p2.dir/P2/menu.cpp.i

CMakeFiles/p2.dir/P2/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p2.dir/P2/menu.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/P2/menu.cpp" -o CMakeFiles/p2.dir/P2/menu.cpp.s

# Object files for target p2
p2_OBJECTS = \
"CMakeFiles/p2.dir/P2/main.cpp.o" \
"CMakeFiles/p2.dir/P2/menu.cpp.o"

# External object files for target p2
p2_EXTERNAL_OBJECTS =

p2.exe: CMakeFiles/p2.dir/P2/main.cpp.o
p2.exe: CMakeFiles/p2.dir/P2/menu.cpp.o
p2.exe: CMakeFiles/p2.dir/build.make
p2.exe: CMakeFiles/p2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable p2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p2.dir/build: p2.exe
.PHONY : CMakeFiles/p2.dir/build

CMakeFiles/p2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p2.dir/clean

CMakeFiles/p2.dir/depend:
	cd "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/moosie02/Order 2/codes/cmake-build-debug/CMakeFiles/p2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/p2.dir/depend
