# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/jimena/Documents/Clion/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jimena/Documents/Clion/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jimena/Documents/Proyectos/Octave

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jimena/Documents/Proyectos/Octave/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Octave.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Octave.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Octave.dir/flags.make

CMakeFiles/Octave.dir/main.cpp.o: CMakeFiles/Octave.dir/flags.make
CMakeFiles/Octave.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jimena/Documents/Proyectos/Octave/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Octave.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Octave.dir/main.cpp.o -c /home/jimena/Documents/Proyectos/Octave/main.cpp

CMakeFiles/Octave.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Octave.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jimena/Documents/Proyectos/Octave/main.cpp > CMakeFiles/Octave.dir/main.cpp.i

CMakeFiles/Octave.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Octave.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jimena/Documents/Proyectos/Octave/main.cpp -o CMakeFiles/Octave.dir/main.cpp.s

CMakeFiles/Octave.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Octave.dir/main.cpp.o.requires

CMakeFiles/Octave.dir/main.cpp.o.provides: CMakeFiles/Octave.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Octave.dir/build.make CMakeFiles/Octave.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Octave.dir/main.cpp.o.provides

CMakeFiles/Octave.dir/main.cpp.o.provides.build: CMakeFiles/Octave.dir/main.cpp.o


CMakeFiles/Octave.dir/pagedArray.cpp.o: CMakeFiles/Octave.dir/flags.make
CMakeFiles/Octave.dir/pagedArray.cpp.o: ../pagedArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jimena/Documents/Proyectos/Octave/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Octave.dir/pagedArray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Octave.dir/pagedArray.cpp.o -c /home/jimena/Documents/Proyectos/Octave/pagedArray.cpp

CMakeFiles/Octave.dir/pagedArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Octave.dir/pagedArray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jimena/Documents/Proyectos/Octave/pagedArray.cpp > CMakeFiles/Octave.dir/pagedArray.cpp.i

CMakeFiles/Octave.dir/pagedArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Octave.dir/pagedArray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jimena/Documents/Proyectos/Octave/pagedArray.cpp -o CMakeFiles/Octave.dir/pagedArray.cpp.s

CMakeFiles/Octave.dir/pagedArray.cpp.o.requires:

.PHONY : CMakeFiles/Octave.dir/pagedArray.cpp.o.requires

CMakeFiles/Octave.dir/pagedArray.cpp.o.provides: CMakeFiles/Octave.dir/pagedArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/Octave.dir/build.make CMakeFiles/Octave.dir/pagedArray.cpp.o.provides.build
.PHONY : CMakeFiles/Octave.dir/pagedArray.cpp.o.provides

CMakeFiles/Octave.dir/pagedArray.cpp.o.provides.build: CMakeFiles/Octave.dir/pagedArray.cpp.o


CMakeFiles/Octave.dir/filesConverter.cpp.o: CMakeFiles/Octave.dir/flags.make
CMakeFiles/Octave.dir/filesConverter.cpp.o: ../filesConverter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jimena/Documents/Proyectos/Octave/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Octave.dir/filesConverter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Octave.dir/filesConverter.cpp.o -c /home/jimena/Documents/Proyectos/Octave/filesConverter.cpp

CMakeFiles/Octave.dir/filesConverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Octave.dir/filesConverter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jimena/Documents/Proyectos/Octave/filesConverter.cpp > CMakeFiles/Octave.dir/filesConverter.cpp.i

CMakeFiles/Octave.dir/filesConverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Octave.dir/filesConverter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jimena/Documents/Proyectos/Octave/filesConverter.cpp -o CMakeFiles/Octave.dir/filesConverter.cpp.s

CMakeFiles/Octave.dir/filesConverter.cpp.o.requires:

.PHONY : CMakeFiles/Octave.dir/filesConverter.cpp.o.requires

CMakeFiles/Octave.dir/filesConverter.cpp.o.provides: CMakeFiles/Octave.dir/filesConverter.cpp.o.requires
	$(MAKE) -f CMakeFiles/Octave.dir/build.make CMakeFiles/Octave.dir/filesConverter.cpp.o.provides.build
.PHONY : CMakeFiles/Octave.dir/filesConverter.cpp.o.provides

CMakeFiles/Octave.dir/filesConverter.cpp.o.provides.build: CMakeFiles/Octave.dir/filesConverter.cpp.o


# Object files for target Octave
Octave_OBJECTS = \
"CMakeFiles/Octave.dir/main.cpp.o" \
"CMakeFiles/Octave.dir/pagedArray.cpp.o" \
"CMakeFiles/Octave.dir/filesConverter.cpp.o"

# External object files for target Octave
Octave_EXTERNAL_OBJECTS =

Octave: CMakeFiles/Octave.dir/main.cpp.o
Octave: CMakeFiles/Octave.dir/pagedArray.cpp.o
Octave: CMakeFiles/Octave.dir/filesConverter.cpp.o
Octave: CMakeFiles/Octave.dir/build.make
Octave: CMakeFiles/Octave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jimena/Documents/Proyectos/Octave/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Octave"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Octave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Octave.dir/build: Octave

.PHONY : CMakeFiles/Octave.dir/build

CMakeFiles/Octave.dir/requires: CMakeFiles/Octave.dir/main.cpp.o.requires
CMakeFiles/Octave.dir/requires: CMakeFiles/Octave.dir/pagedArray.cpp.o.requires
CMakeFiles/Octave.dir/requires: CMakeFiles/Octave.dir/filesConverter.cpp.o.requires

.PHONY : CMakeFiles/Octave.dir/requires

CMakeFiles/Octave.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Octave.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Octave.dir/clean

CMakeFiles/Octave.dir/depend:
	cd /home/jimena/Documents/Proyectos/Octave/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jimena/Documents/Proyectos/Octave /home/jimena/Documents/Proyectos/Octave /home/jimena/Documents/Proyectos/Octave/cmake-build-debug /home/jimena/Documents/Proyectos/Octave/cmake-build-debug /home/jimena/Documents/Proyectos/Octave/cmake-build-debug/CMakeFiles/Octave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Octave.dir/depend

