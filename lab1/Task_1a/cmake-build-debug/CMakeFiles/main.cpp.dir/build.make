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
include CMakeFiles/main.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.cpp.dir/flags.make

CMakeFiles/main.cpp.dir/task1_test.cpp.obj: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/task1_test.cpp.obj: CMakeFiles/main.cpp.dir/includes_CXX.rsp
CMakeFiles/main.cpp.dir/task1_test.cpp.obj: ../task1_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.cpp.dir/task1_test.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.cpp.dir\task1_test.cpp.obj -c "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\task1_test.cpp"

CMakeFiles/main.cpp.dir/task1_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/task1_test.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\task1_test.cpp" > CMakeFiles\main.cpp.dir\task1_test.cpp.i

CMakeFiles/main.cpp.dir/task1_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/task1_test.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\task1_test.cpp" -o CMakeFiles\main.cpp.dir\task1_test.cpp.s

CMakeFiles/main.cpp.dir/task2_test.cpp.obj: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/task2_test.cpp.obj: CMakeFiles/main.cpp.dir/includes_CXX.rsp
CMakeFiles/main.cpp.dir/task2_test.cpp.obj: ../task2_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.cpp.dir/task2_test.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.cpp.dir\task2_test.cpp.obj -c "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\task2_test.cpp"

CMakeFiles/main.cpp.dir/task2_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/task2_test.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\task2_test.cpp" > CMakeFiles\main.cpp.dir\task2_test.cpp.i

CMakeFiles/main.cpp.dir/task2_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/task2_test.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\task2_test.cpp" -o CMakeFiles\main.cpp.dir\task2_test.cpp.s

# Object files for target main.cpp
main_cpp_OBJECTS = \
"CMakeFiles/main.cpp.dir/task1_test.cpp.obj" \
"CMakeFiles/main.cpp.dir/task2_test.cpp.obj"

# External object files for target main.cpp
main_cpp_EXTERNAL_OBJECTS = \
"D:/Working directory/NSU/nsu-repository/lab1/Task_1a/cmake-build-debug/CMakeFiles/corelib.dir/module1.cpp.obj" \
"D:/Working directory/NSU/nsu-repository/lab1/Task_1a/cmake-build-debug/CMakeFiles/corelib.dir/module2.cpp.obj" \
"D:/Working directory/NSU/nsu-repository/lab1/Task_1a/cmake-build-debug/CMakeFiles/corelib.dir/module3.cpp.obj"

main.cpp.exe: CMakeFiles/main.cpp.dir/task1_test.cpp.obj
main.cpp.exe: CMakeFiles/main.cpp.dir/task2_test.cpp.obj
main.cpp.exe: CMakeFiles/corelib.dir/module1.cpp.obj
main.cpp.exe: CMakeFiles/corelib.dir/module2.cpp.obj
main.cpp.exe: CMakeFiles/corelib.dir/module3.cpp.obj
main.cpp.exe: CMakeFiles/main.cpp.dir/build.make
main.cpp.exe: lib/libgtest_main.a
main.cpp.exe: lib/libgtest.a
main.cpp.exe: CMakeFiles/main.cpp.dir/linklibs.rsp
main.cpp.exe: CMakeFiles/main.cpp.dir/objects1.rsp
main.cpp.exe: CMakeFiles/main.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable main.cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.cpp.dir/build: main.cpp.exe

.PHONY : CMakeFiles/main.cpp.dir/build

CMakeFiles/main.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.cpp.dir/clean

CMakeFiles/main.cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug" "D:\Working directory\NSU\nsu-repository\lab1\Task_1a\cmake-build-debug\CMakeFiles\main.cpp.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.cpp.dir/depend

