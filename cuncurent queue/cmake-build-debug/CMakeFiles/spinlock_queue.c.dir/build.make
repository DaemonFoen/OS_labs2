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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/spinlock_queue.c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spinlock_queue.c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spinlock_queue.c.dir/flags.make

CMakeFiles/spinlock_queue.c.dir/queue.c.o: CMakeFiles/spinlock_queue.c.dir/flags.make
CMakeFiles/spinlock_queue.c.dir/queue.c.o: ../queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spinlock_queue.c.dir/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spinlock_queue.c.dir/queue.c.o   -c "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/queue.c"

CMakeFiles/spinlock_queue.c.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spinlock_queue.c.dir/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/queue.c" > CMakeFiles/spinlock_queue.c.dir/queue.c.i

CMakeFiles/spinlock_queue.c.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spinlock_queue.c.dir/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/queue.c" -o CMakeFiles/spinlock_queue.c.dir/queue.c.s

CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.o: CMakeFiles/spinlock_queue.c.dir/flags.make
CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.o: ../spinlock_queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.o   -c "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/spinlock_queue.c"

CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/spinlock_queue.c" > CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.i

CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/spinlock_queue.c" -o CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.s

# Object files for target spinlock_queue.c
spinlock_queue_c_OBJECTS = \
"CMakeFiles/spinlock_queue.c.dir/queue.c.o" \
"CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.o"

# External object files for target spinlock_queue.c
spinlock_queue_c_EXTERNAL_OBJECTS =

spinlock_queue.c: CMakeFiles/spinlock_queue.c.dir/queue.c.o
spinlock_queue.c: CMakeFiles/spinlock_queue.c.dir/spinlock_queue.c.o
spinlock_queue.c: CMakeFiles/spinlock_queue.c.dir/build.make
spinlock_queue.c: CMakeFiles/spinlock_queue.c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable spinlock_queue.c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spinlock_queue.c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spinlock_queue.c.dir/build: spinlock_queue.c

.PHONY : CMakeFiles/spinlock_queue.c.dir/build

CMakeFiles/spinlock_queue.c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spinlock_queue.c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spinlock_queue.c.dir/clean

CMakeFiles/spinlock_queue.c.dir/depend:
	cd "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue" "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue" "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug" "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug" "/mnt/e/Users/Dmitriy/CLionProjects/queue/cuncurent queue/cmake-build-debug/CMakeFiles/spinlock_queue.c.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/spinlock_queue.c.dir/depend

