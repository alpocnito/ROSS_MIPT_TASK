# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/profkom/ROSS/ROSS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/profkom/ROSS/ROSS

# Include any dependencies generated for this target.
include models/template-model/CMakeFiles/model.dir/depend.make

# Include the progress variables for this target.
include models/template-model/CMakeFiles/model.dir/progress.make

# Include the compile flags for this target's objects.
include models/template-model/CMakeFiles/model.dir/flags.make

models/template-model/CMakeFiles/model.dir/model_main.c.o: models/template-model/CMakeFiles/model.dir/flags.make
models/template-model/CMakeFiles/model.dir/model_main.c.o: models/template-model/model_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/profkom/ROSS/ROSS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object models/template-model/CMakeFiles/model.dir/model_main.c.o"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/model.dir/model_main.c.o   -c /home/user/profkom/ROSS/ROSS/models/template-model/model_main.c

models/template-model/CMakeFiles/model.dir/model_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/model_main.c.i"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/profkom/ROSS/ROSS/models/template-model/model_main.c > CMakeFiles/model.dir/model_main.c.i

models/template-model/CMakeFiles/model.dir/model_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/model_main.c.s"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/profkom/ROSS/ROSS/models/template-model/model_main.c -o CMakeFiles/model.dir/model_main.c.s

models/template-model/CMakeFiles/model.dir/model_driver.c.o: models/template-model/CMakeFiles/model.dir/flags.make
models/template-model/CMakeFiles/model.dir/model_driver.c.o: models/template-model/model_driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/profkom/ROSS/ROSS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object models/template-model/CMakeFiles/model.dir/model_driver.c.o"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/model.dir/model_driver.c.o   -c /home/user/profkom/ROSS/ROSS/models/template-model/model_driver.c

models/template-model/CMakeFiles/model.dir/model_driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/model_driver.c.i"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/profkom/ROSS/ROSS/models/template-model/model_driver.c > CMakeFiles/model.dir/model_driver.c.i

models/template-model/CMakeFiles/model.dir/model_driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/model_driver.c.s"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/profkom/ROSS/ROSS/models/template-model/model_driver.c -o CMakeFiles/model.dir/model_driver.c.s

models/template-model/CMakeFiles/model.dir/model_map.c.o: models/template-model/CMakeFiles/model.dir/flags.make
models/template-model/CMakeFiles/model.dir/model_map.c.o: models/template-model/model_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/profkom/ROSS/ROSS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object models/template-model/CMakeFiles/model.dir/model_map.c.o"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/model.dir/model_map.c.o   -c /home/user/profkom/ROSS/ROSS/models/template-model/model_map.c

models/template-model/CMakeFiles/model.dir/model_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/model_map.c.i"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/profkom/ROSS/ROSS/models/template-model/model_map.c > CMakeFiles/model.dir/model_map.c.i

models/template-model/CMakeFiles/model.dir/model_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/model_map.c.s"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/profkom/ROSS/ROSS/models/template-model/model_map.c -o CMakeFiles/model.dir/model_map.c.s

# Object files for target model
model_OBJECTS = \
"CMakeFiles/model.dir/model_main.c.o" \
"CMakeFiles/model.dir/model_driver.c.o" \
"CMakeFiles/model.dir/model_map.c.o"

# External object files for target model
model_EXTERNAL_OBJECTS =

models/template-model/model: models/template-model/CMakeFiles/model.dir/model_main.c.o
models/template-model/model: models/template-model/CMakeFiles/model.dir/model_driver.c.o
models/template-model/model: models/template-model/CMakeFiles/model.dir/model_map.c.o
models/template-model/model: models/template-model/CMakeFiles/model.dir/build.make
models/template-model/model: core/libROSS.a
models/template-model/model: /shr/lib/mpich/lib/libmpi.so
models/template-model/model: models/template-model/CMakeFiles/model.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/profkom/ROSS/ROSS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable model"
	cd /home/user/profkom/ROSS/ROSS/models/template-model && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/model.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
models/template-model/CMakeFiles/model.dir/build: models/template-model/model

.PHONY : models/template-model/CMakeFiles/model.dir/build

models/template-model/CMakeFiles/model.dir/clean:
	cd /home/user/profkom/ROSS/ROSS/models/template-model && $(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean.cmake
.PHONY : models/template-model/CMakeFiles/model.dir/clean

models/template-model/CMakeFiles/model.dir/depend:
	cd /home/user/profkom/ROSS/ROSS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/profkom/ROSS/ROSS /home/user/profkom/ROSS/ROSS/models/template-model /home/user/profkom/ROSS/ROSS /home/user/profkom/ROSS/ROSS/models/template-model /home/user/profkom/ROSS/ROSS/models/template-model/CMakeFiles/model.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : models/template-model/CMakeFiles/model.dir/depend

