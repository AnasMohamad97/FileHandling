# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anasmohamadsobhi/CLionProjects/File_Research

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/File_Research.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/File_Research.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/File_Research.dir/flags.make

CMakeFiles/File_Research.dir/main.cpp.o: CMakeFiles/File_Research.dir/flags.make
CMakeFiles/File_Research.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/File_Research.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/File_Research.dir/main.cpp.o -c /Users/anasmohamadsobhi/CLionProjects/File_Research/main.cpp

CMakeFiles/File_Research.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/File_Research.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anasmohamadsobhi/CLionProjects/File_Research/main.cpp > CMakeFiles/File_Research.dir/main.cpp.i

CMakeFiles/File_Research.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/File_Research.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anasmohamadsobhi/CLionProjects/File_Research/main.cpp -o CMakeFiles/File_Research.dir/main.cpp.s

CMakeFiles/File_Research.dir/Department.cpp.o: CMakeFiles/File_Research.dir/flags.make
CMakeFiles/File_Research.dir/Department.cpp.o: ../Department.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/File_Research.dir/Department.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/File_Research.dir/Department.cpp.o -c /Users/anasmohamadsobhi/CLionProjects/File_Research/Department.cpp

CMakeFiles/File_Research.dir/Department.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/File_Research.dir/Department.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anasmohamadsobhi/CLionProjects/File_Research/Department.cpp > CMakeFiles/File_Research.dir/Department.cpp.i

CMakeFiles/File_Research.dir/Department.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/File_Research.dir/Department.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anasmohamadsobhi/CLionProjects/File_Research/Department.cpp -o CMakeFiles/File_Research.dir/Department.cpp.s

# Object files for target File_Research
File_Research_OBJECTS = \
"CMakeFiles/File_Research.dir/main.cpp.o" \
"CMakeFiles/File_Research.dir/Department.cpp.o"

# External object files for target File_Research
File_Research_EXTERNAL_OBJECTS =

File_Research: CMakeFiles/File_Research.dir/main.cpp.o
File_Research: CMakeFiles/File_Research.dir/Department.cpp.o
File_Research: CMakeFiles/File_Research.dir/build.make
File_Research: CMakeFiles/File_Research.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable File_Research"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/File_Research.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/File_Research.dir/build: File_Research

.PHONY : CMakeFiles/File_Research.dir/build

CMakeFiles/File_Research.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/File_Research.dir/cmake_clean.cmake
.PHONY : CMakeFiles/File_Research.dir/clean

CMakeFiles/File_Research.dir/depend:
	cd /Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anasmohamadsobhi/CLionProjects/File_Research /Users/anasmohamadsobhi/CLionProjects/File_Research /Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug /Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug /Users/anasmohamadsobhi/CLionProjects/File_Research/cmake-build-debug/CMakeFiles/File_Research.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/File_Research.dir/depend

