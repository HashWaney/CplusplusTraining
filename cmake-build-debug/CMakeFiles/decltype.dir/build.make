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
include CMakeFiles/decltype.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/decltype.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/decltype.dir/flags.make

CMakeFiles/decltype.dir/decltype/21_decltype.cpp.o: CMakeFiles/decltype.dir/flags.make
CMakeFiles/decltype.dir/decltype/21_decltype.cpp.o: ../decltype/21_decltype.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/decltype.dir/decltype/21_decltype.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/decltype.dir/decltype/21_decltype.cpp.o -c /Users/wangqing/Desktop/JNI/CPP/Review/decltype/21_decltype.cpp

CMakeFiles/decltype.dir/decltype/21_decltype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/decltype.dir/decltype/21_decltype.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangqing/Desktop/JNI/CPP/Review/decltype/21_decltype.cpp > CMakeFiles/decltype.dir/decltype/21_decltype.cpp.i

CMakeFiles/decltype.dir/decltype/21_decltype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/decltype.dir/decltype/21_decltype.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangqing/Desktop/JNI/CPP/Review/decltype/21_decltype.cpp -o CMakeFiles/decltype.dir/decltype/21_decltype.cpp.s

# Object files for target decltype
decltype_OBJECTS = \
"CMakeFiles/decltype.dir/decltype/21_decltype.cpp.o"

# External object files for target decltype
decltype_EXTERNAL_OBJECTS =

decltype: CMakeFiles/decltype.dir/decltype/21_decltype.cpp.o
decltype: CMakeFiles/decltype.dir/build.make
decltype: CMakeFiles/decltype.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable decltype"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decltype.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/decltype.dir/build: decltype

.PHONY : CMakeFiles/decltype.dir/build

CMakeFiles/decltype.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/decltype.dir/cmake_clean.cmake
.PHONY : CMakeFiles/decltype.dir/clean

CMakeFiles/decltype.dir/depend:
	cd /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangqing/Desktop/JNI/CPP/Review /Users/wangqing/Desktop/JNI/CPP/Review /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug /Users/wangqing/Desktop/JNI/CPP/Review/cmake-build-debug/CMakeFiles/decltype.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/decltype.dir/depend
