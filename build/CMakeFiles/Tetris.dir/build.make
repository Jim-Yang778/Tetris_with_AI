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
CMAKE_SOURCE_DIR = /home/jinyu/Tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jinyu/Tetris/build

# Include any dependencies generated for this target.
include CMakeFiles/Tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tetris.dir/flags.make

CMakeFiles/Tetris.dir/src/main.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jinyu/Tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tetris.dir/src/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/src/main.cpp.o -c /home/jinyu/Tetris/src/main.cpp

CMakeFiles/Tetris.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/src/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jinyu/Tetris/src/main.cpp > CMakeFiles/Tetris.dir/src/main.cpp.i

CMakeFiles/Tetris.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/src/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jinyu/Tetris/src/main.cpp -o CMakeFiles/Tetris.dir/src/main.cpp.s

CMakeFiles/Tetris.dir/src/game.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jinyu/Tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tetris.dir/src/game.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/src/game.cpp.o -c /home/jinyu/Tetris/src/game.cpp

CMakeFiles/Tetris.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/src/game.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jinyu/Tetris/src/game.cpp > CMakeFiles/Tetris.dir/src/game.cpp.i

CMakeFiles/Tetris.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/src/game.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jinyu/Tetris/src/game.cpp -o CMakeFiles/Tetris.dir/src/game.cpp.s

CMakeFiles/Tetris.dir/src/controller.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jinyu/Tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tetris.dir/src/controller.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/src/controller.cpp.o -c /home/jinyu/Tetris/src/controller.cpp

CMakeFiles/Tetris.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/src/controller.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jinyu/Tetris/src/controller.cpp > CMakeFiles/Tetris.dir/src/controller.cpp.i

CMakeFiles/Tetris.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/src/controller.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jinyu/Tetris/src/controller.cpp -o CMakeFiles/Tetris.dir/src/controller.cpp.s

CMakeFiles/Tetris.dir/src/renderer.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jinyu/Tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tetris.dir/src/renderer.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/src/renderer.cpp.o -c /home/jinyu/Tetris/src/renderer.cpp

CMakeFiles/Tetris.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/src/renderer.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jinyu/Tetris/src/renderer.cpp > CMakeFiles/Tetris.dir/src/renderer.cpp.i

CMakeFiles/Tetris.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/src/renderer.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jinyu/Tetris/src/renderer.cpp -o CMakeFiles/Tetris.dir/src/renderer.cpp.s

CMakeFiles/Tetris.dir/src/tetris.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/src/tetris.cpp.o: ../src/tetris.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jinyu/Tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tetris.dir/src/tetris.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/src/tetris.cpp.o -c /home/jinyu/Tetris/src/tetris.cpp

CMakeFiles/Tetris.dir/src/tetris.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/src/tetris.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jinyu/Tetris/src/tetris.cpp > CMakeFiles/Tetris.dir/src/tetris.cpp.i

CMakeFiles/Tetris.dir/src/tetris.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/src/tetris.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jinyu/Tetris/src/tetris.cpp -o CMakeFiles/Tetris.dir/src/tetris.cpp.s

# Object files for target Tetris
Tetris_OBJECTS = \
"CMakeFiles/Tetris.dir/src/main.cpp.o" \
"CMakeFiles/Tetris.dir/src/game.cpp.o" \
"CMakeFiles/Tetris.dir/src/controller.cpp.o" \
"CMakeFiles/Tetris.dir/src/renderer.cpp.o" \
"CMakeFiles/Tetris.dir/src/tetris.cpp.o"

# External object files for target Tetris
Tetris_EXTERNAL_OBJECTS =

Tetris: CMakeFiles/Tetris.dir/src/main.cpp.o
Tetris: CMakeFiles/Tetris.dir/src/game.cpp.o
Tetris: CMakeFiles/Tetris.dir/src/controller.cpp.o
Tetris: CMakeFiles/Tetris.dir/src/renderer.cpp.o
Tetris: CMakeFiles/Tetris.dir/src/tetris.cpp.o
Tetris: CMakeFiles/Tetris.dir/build.make
Tetris: CMakeFiles/Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jinyu/Tetris/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tetris.dir/build: Tetris

.PHONY : CMakeFiles/Tetris.dir/build

CMakeFiles/Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tetris.dir/clean

CMakeFiles/Tetris.dir/depend:
	cd /home/jinyu/Tetris/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jinyu/Tetris /home/jinyu/Tetris /home/jinyu/Tetris/build /home/jinyu/Tetris/build /home/jinyu/Tetris/build/CMakeFiles/Tetris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tetris.dir/depend

