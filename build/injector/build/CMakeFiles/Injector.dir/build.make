# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/dwir/work/embed/soil/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dwir/work/embed/soil/build

# Include any dependencies generated for this target.
include injector/build/CMakeFiles/Injector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include injector/build/CMakeFiles/Injector.dir/compiler_depend.make

# Include the progress variables for this target.
include injector/build/CMakeFiles/Injector.dir/progress.make

# Include the compile flags for this target's objects.
include injector/build/CMakeFiles/Injector.dir/flags.make

injector/build/CMakeFiles/Injector.dir/injector.c.o: injector/build/CMakeFiles/Injector.dir/flags.make
injector/build/CMakeFiles/Injector.dir/injector.c.o: /home/dwir/work/embed/soil/code/injector/injector.c
injector/build/CMakeFiles/Injector.dir/injector.c.o: injector/build/CMakeFiles/Injector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dwir/work/embed/soil/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object injector/build/CMakeFiles/Injector.dir/injector.c.o"
	cd /home/dwir/work/embed/soil/build/injector/build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT injector/build/CMakeFiles/Injector.dir/injector.c.o -MF CMakeFiles/Injector.dir/injector.c.o.d -o CMakeFiles/Injector.dir/injector.c.o -c /home/dwir/work/embed/soil/code/injector/injector.c

injector/build/CMakeFiles/Injector.dir/injector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Injector.dir/injector.c.i"
	cd /home/dwir/work/embed/soil/build/injector/build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dwir/work/embed/soil/code/injector/injector.c > CMakeFiles/Injector.dir/injector.c.i

injector/build/CMakeFiles/Injector.dir/injector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Injector.dir/injector.c.s"
	cd /home/dwir/work/embed/soil/build/injector/build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dwir/work/embed/soil/code/injector/injector.c -o CMakeFiles/Injector.dir/injector.c.s

# Object files for target Injector
Injector_OBJECTS = \
"CMakeFiles/Injector.dir/injector.c.o"

# External object files for target Injector
Injector_EXTERNAL_OBJECTS =

injector/build/libInjector.a: injector/build/CMakeFiles/Injector.dir/injector.c.o
injector/build/libInjector.a: injector/build/CMakeFiles/Injector.dir/build.make
injector/build/libInjector.a: injector/build/CMakeFiles/Injector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dwir/work/embed/soil/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libInjector.a"
	cd /home/dwir/work/embed/soil/build/injector/build && $(CMAKE_COMMAND) -P CMakeFiles/Injector.dir/cmake_clean_target.cmake
	cd /home/dwir/work/embed/soil/build/injector/build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Injector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
injector/build/CMakeFiles/Injector.dir/build: injector/build/libInjector.a
.PHONY : injector/build/CMakeFiles/Injector.dir/build

injector/build/CMakeFiles/Injector.dir/clean:
	cd /home/dwir/work/embed/soil/build/injector/build && $(CMAKE_COMMAND) -P CMakeFiles/Injector.dir/cmake_clean.cmake
.PHONY : injector/build/CMakeFiles/Injector.dir/clean

injector/build/CMakeFiles/Injector.dir/depend:
	cd /home/dwir/work/embed/soil/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dwir/work/embed/soil/code /home/dwir/work/embed/soil/code/injector /home/dwir/work/embed/soil/build /home/dwir/work/embed/soil/build/injector/build /home/dwir/work/embed/soil/build/injector/build/CMakeFiles/Injector.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : injector/build/CMakeFiles/Injector.dir/depend

