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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangqing/Desktop/JNI/CPP/Review

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/this.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/this.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/this.dir/flags.make

CMakeFiles/this.dir/this/03_this.cpp.o: CMakeFiles/this.dir/flags.make
CMakeFiles/this.dir/this/03_this.cpp.o: ../this/03_this.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/this.dir/this/03_this.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/this.dir/this/03_this.cpp.o -c /Users/wangqing/Desktop/JNI/CPP/Review/this/03_this.cpp

CMakeFiles/this.dir/this/03_this.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/this.dir/this/03_this.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/Review/this/03_this.cpp > CMakeFiles/this.dir/this/03_this.cpp.i

CMakeFiles/this.dir/this/03_this.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/this.dir/this/03_this.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/Review/this/03_this.cpp -o CMakeFiles/this.dir/this/03_this.cpp.s

# Object files for target this
this_OBJECTS = \
"CMakeFiles/this.dir/this/03_this.cpp.o"

# External object files for target this
this_EXTERNAL_OBJECTS =

this: CMakeFiles/this.dir/this/03_this.cpp.o
this: CMakeFiles/this.dir/build.make
this: CMakeFiles/this.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable this"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/this.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/this.dir/build: this

.PHONY : CMakeFiles/this.dir/build

CMakeFiles/this.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/this.dir/cmake_clean.cmake
.PHONY : CMakeFiles/this.dir/clean

CMakeFiles/this.dir/depend:
	cd /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqing/Desktop/JNI/CPP/Review /Users/wangqing/Desktop/JNI/CPP/Review /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug/CMakeFiles/this.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/this.dir/depend

