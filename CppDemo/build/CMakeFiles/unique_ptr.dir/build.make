# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /root/CMU_C++_BOOTCAMP/CppDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CMU_C++_BOOTCAMP/CppDemo/build

# Include any dependencies generated for this target.
include CMakeFiles/unique_ptr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unique_ptr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unique_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unique_ptr.dir/flags.make

CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o: CMakeFiles/unique_ptr.dir/flags.make
CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o: /root/CMU_C++_BOOTCAMP/CppDemo/src/unique_ptr.cpp
CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o: CMakeFiles/unique_ptr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/CMU_C++_BOOTCAMP/CppDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o -MF CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o.d -o CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o -c /root/CMU_C++_BOOTCAMP/CppDemo/src/unique_ptr.cpp

CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CMU_C++_BOOTCAMP/CppDemo/src/unique_ptr.cpp > CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.i

CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CMU_C++_BOOTCAMP/CppDemo/src/unique_ptr.cpp -o CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.s

# Object files for target unique_ptr
unique_ptr_OBJECTS = \
"CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o"

# External object files for target unique_ptr
unique_ptr_EXTERNAL_OBJECTS =

/root/CMU_C++_BOOTCAMP/CppDemo/bin/unique_ptr: CMakeFiles/unique_ptr.dir/src/unique_ptr.cpp.o
/root/CMU_C++_BOOTCAMP/CppDemo/bin/unique_ptr: CMakeFiles/unique_ptr.dir/build.make
/root/CMU_C++_BOOTCAMP/CppDemo/bin/unique_ptr: CMakeFiles/unique_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/CMU_C++_BOOTCAMP/CppDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /root/CMU_C++_BOOTCAMP/CppDemo/bin/unique_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unique_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unique_ptr.dir/build: /root/CMU_C++_BOOTCAMP/CppDemo/bin/unique_ptr
.PHONY : CMakeFiles/unique_ptr.dir/build

CMakeFiles/unique_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unique_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unique_ptr.dir/clean

CMakeFiles/unique_ptr.dir/depend:
	cd /root/CMU_C++_BOOTCAMP/CppDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CMU_C++_BOOTCAMP/CppDemo /root/CMU_C++_BOOTCAMP/CppDemo /root/CMU_C++_BOOTCAMP/CppDemo/build /root/CMU_C++_BOOTCAMP/CppDemo/build /root/CMU_C++_BOOTCAMP/CppDemo/build/CMakeFiles/unique_ptr.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/unique_ptr.dir/depend

