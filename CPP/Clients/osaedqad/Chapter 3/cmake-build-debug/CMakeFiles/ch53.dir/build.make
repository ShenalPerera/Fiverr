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
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ch53.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ch53.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch53.dir/flags.make

CMakeFiles/ch53.dir/pythagorean.cpp.o: CMakeFiles/ch53.dir/flags.make
CMakeFiles/ch53.dir/pythagorean.cpp.o: ../pythagorean.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ch53.dir/pythagorean.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch53.dir/pythagorean.cpp.o -c "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/pythagorean.cpp"

CMakeFiles/ch53.dir/pythagorean.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch53.dir/pythagorean.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/pythagorean.cpp" > CMakeFiles/ch53.dir/pythagorean.cpp.i

CMakeFiles/ch53.dir/pythagorean.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch53.dir/pythagorean.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/pythagorean.cpp" -o CMakeFiles/ch53.dir/pythagorean.cpp.s

# Object files for target ch53
ch53_OBJECTS = \
"CMakeFiles/ch53.dir/pythagorean.cpp.o"

# External object files for target ch53
ch53_EXTERNAL_OBJECTS =

ch53.exe: CMakeFiles/ch53.dir/pythagorean.cpp.o
ch53.exe: CMakeFiles/ch53.dir/build.make
ch53.exe: CMakeFiles/ch53.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ch53.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch53.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch53.dir/build: ch53.exe
.PHONY : CMakeFiles/ch53.dir/build

CMakeFiles/ch53.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch53.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch53.dir/clean

CMakeFiles/ch53.dir/depend:
	cd "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug" "/cygdrive/c/Users/shena/Desktop/Fiverr/original repo/Fiverr/CPP/Clients/osaedqad/Chapter 3/cmake-build-debug/CMakeFiles/ch53.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ch53.dir/depend
