# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Working directory\NSU\nsu-repository\lab1\Task_1a"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task1.dir/flags.make

CMakeFiles/Task1.dir/main.cpp.obj: CMakeFiles/Task1.dir/flags.make
CMakeFiles/Task1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task1.dir\main.cpp.obj -c "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\main.cpp"

CMakeFiles/Task1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\main.cpp" > CMakeFiles\Task1.dir\main.cpp.i

CMakeFiles/Task1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\main.cpp" -o CMakeFiles\Task1.dir\main.cpp.s

# Object files for target Task1
Task1_OBJECTS = \
"CMakeFiles/Task1.dir/main.cpp.obj"

# External object files for target Task1
Task1_EXTERNAL_OBJECTS = \
"D:/Working directory/NSU/nsu-repository/lab1/Task_1a/cmake-build-debug/CMakeFiles/corelib.dir/module1.cpp.obj" \
"D:/Working directory/NSU/nsu-repository/lab1/Task_1a/cmake-build-debug/CMakeFiles/corelib.dir/module2.cpp.obj" \
"D:/Working directory/NSU/nsu-repository/lab1/Task_1a/cmake-build-debug/CMakeFiles/corelib.dir/module3.cpp.obj"

Task1.exe: CMakeFiles/Task1.dir/main.cpp.obj
Task1.exe: CMakeFiles/corelib.dir/module1.cpp.obj
Task1.exe: CMakeFiles/corelib.dir/module2.cpp.obj
Task1.exe: CMakeFiles/corelib.dir/module3.cpp.obj
Task1.exe: CMakeFiles/Task1.dir/build.make
Task1.exe: CMakeFiles/Task1.dir/linklibs.rsp
Task1.exe: CMakeFiles/Task1.dir/objects1.rsp
Task1.exe: CMakeFiles/Task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task1.dir/build: Task1.exe

.PHONY : CMakeFiles/Task1.dir/build

CMakeFiles/Task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task1.dir/clean

CMakeFiles/Task1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles\Task1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task1.dir/depend

