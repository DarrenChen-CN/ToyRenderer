# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = E:\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\code\VSCode Projects\C++\ToyRenderer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\code\VSCode Projects\C++\ToyRenderer\build"

# Include any dependencies generated for this target.
include core/CMakeFiles/Core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include core/CMakeFiles/Core.dir/compiler_depend.make

# Include the progress variables for this target.
include core/CMakeFiles/Core.dir/progress.make

# Include the compile flags for this target's objects.
include core/CMakeFiles/Core.dir/flags.make

core/CMakeFiles/Core.dir/camera.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/camera.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/camera.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/camera.cpp
core/CMakeFiles/Core.dir/camera.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object core/CMakeFiles/Core.dir/camera.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/camera.cpp.obj -MF CMakeFiles\Core.dir\camera.cpp.obj.d -o CMakeFiles\Core.dir\camera.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\camera.cpp"

core/CMakeFiles/Core.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/camera.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\camera.cpp" > CMakeFiles\Core.dir\camera.cpp.i

core/CMakeFiles/Core.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/camera.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\camera.cpp" -o CMakeFiles\Core.dir\camera.cpp.s

core/CMakeFiles/Core.dir/light.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/light.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/light.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/light.cpp
core/CMakeFiles/Core.dir/light.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object core/CMakeFiles/Core.dir/light.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/light.cpp.obj -MF CMakeFiles\Core.dir\light.cpp.obj.d -o CMakeFiles\Core.dir\light.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\light.cpp"

core/CMakeFiles/Core.dir/light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/light.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\light.cpp" > CMakeFiles\Core.dir\light.cpp.i

core/CMakeFiles/Core.dir/light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/light.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\light.cpp" -o CMakeFiles\Core.dir\light.cpp.s

core/CMakeFiles/Core.dir/model.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/model.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/model.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/model.cpp
core/CMakeFiles/Core.dir/model.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object core/CMakeFiles/Core.dir/model.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/model.cpp.obj -MF CMakeFiles\Core.dir\model.cpp.obj.d -o CMakeFiles\Core.dir\model.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\model.cpp"

core/CMakeFiles/Core.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/model.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\model.cpp" > CMakeFiles\Core.dir\model.cpp.i

core/CMakeFiles/Core.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/model.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\model.cpp" -o CMakeFiles\Core.dir\model.cpp.s

core/CMakeFiles/Core.dir/rasterizer.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/rasterizer.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/rasterizer.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/rasterizer.cpp
core/CMakeFiles/Core.dir/rasterizer.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object core/CMakeFiles/Core.dir/rasterizer.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/rasterizer.cpp.obj -MF CMakeFiles\Core.dir\rasterizer.cpp.obj.d -o CMakeFiles\Core.dir\rasterizer.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\rasterizer.cpp"

core/CMakeFiles/Core.dir/rasterizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/rasterizer.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\rasterizer.cpp" > CMakeFiles\Core.dir\rasterizer.cpp.i

core/CMakeFiles/Core.dir/rasterizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/rasterizer.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\rasterizer.cpp" -o CMakeFiles\Core.dir\rasterizer.cpp.s

core/CMakeFiles/Core.dir/renderbuffer.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/renderbuffer.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/renderbuffer.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/renderbuffer.cpp
core/CMakeFiles/Core.dir/renderbuffer.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object core/CMakeFiles/Core.dir/renderbuffer.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/renderbuffer.cpp.obj -MF CMakeFiles\Core.dir\renderbuffer.cpp.obj.d -o CMakeFiles\Core.dir\renderbuffer.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\renderbuffer.cpp"

core/CMakeFiles/Core.dir/renderbuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/renderbuffer.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\renderbuffer.cpp" > CMakeFiles\Core.dir\renderbuffer.cpp.i

core/CMakeFiles/Core.dir/renderbuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/renderbuffer.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\renderbuffer.cpp" -o CMakeFiles\Core.dir\renderbuffer.cpp.s

core/CMakeFiles/Core.dir/sceen.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/sceen.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/sceen.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/sceen.cpp
core/CMakeFiles/Core.dir/sceen.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object core/CMakeFiles/Core.dir/sceen.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/sceen.cpp.obj -MF CMakeFiles\Core.dir\sceen.cpp.obj.d -o CMakeFiles\Core.dir\sceen.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\sceen.cpp"

core/CMakeFiles/Core.dir/sceen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/sceen.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\sceen.cpp" > CMakeFiles\Core.dir\sceen.cpp.i

core/CMakeFiles/Core.dir/sceen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/sceen.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\sceen.cpp" -o CMakeFiles\Core.dir\sceen.cpp.s

core/CMakeFiles/Core.dir/shadowmap.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/shadowmap.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/shadowmap.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/shadowmap.cpp
core/CMakeFiles/Core.dir/shadowmap.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object core/CMakeFiles/Core.dir/shadowmap.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/shadowmap.cpp.obj -MF CMakeFiles\Core.dir\shadowmap.cpp.obj.d -o CMakeFiles\Core.dir\shadowmap.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\shadowmap.cpp"

core/CMakeFiles/Core.dir/shadowmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/shadowmap.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\shadowmap.cpp" > CMakeFiles\Core.dir\shadowmap.cpp.i

core/CMakeFiles/Core.dir/shadowmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/shadowmap.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\shadowmap.cpp" -o CMakeFiles\Core.dir\shadowmap.cpp.s

core/CMakeFiles/Core.dir/texture.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/texture.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/texture.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/texture.cpp
core/CMakeFiles/Core.dir/texture.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object core/CMakeFiles/Core.dir/texture.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/texture.cpp.obj -MF CMakeFiles\Core.dir\texture.cpp.obj.d -o CMakeFiles\Core.dir\texture.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\texture.cpp"

core/CMakeFiles/Core.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/texture.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\texture.cpp" > CMakeFiles\Core.dir\texture.cpp.i

core/CMakeFiles/Core.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/texture.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\texture.cpp" -o CMakeFiles\Core.dir\texture.cpp.s

core/CMakeFiles/Core.dir/triangle.cpp.obj: core/CMakeFiles/Core.dir/flags.make
core/CMakeFiles/Core.dir/triangle.cpp.obj: core/CMakeFiles/Core.dir/includes_CXX.rsp
core/CMakeFiles/Core.dir/triangle.cpp.obj: E:/code/VSCode\ Projects/C++/ToyRenderer/core/triangle.cpp
core/CMakeFiles/Core.dir/triangle.cpp.obj: core/CMakeFiles/Core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object core/CMakeFiles/Core.dir/triangle.cpp.obj"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT core/CMakeFiles/Core.dir/triangle.cpp.obj -MF CMakeFiles\Core.dir\triangle.cpp.obj.d -o CMakeFiles\Core.dir\triangle.cpp.obj -c "E:\code\VSCode Projects\C++\ToyRenderer\core\triangle.cpp"

core/CMakeFiles/Core.dir/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Core.dir/triangle.cpp.i"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\code\VSCode Projects\C++\ToyRenderer\core\triangle.cpp" > CMakeFiles\Core.dir\triangle.cpp.i

core/CMakeFiles/Core.dir/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Core.dir/triangle.cpp.s"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && E:\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\code\VSCode Projects\C++\ToyRenderer\core\triangle.cpp" -o CMakeFiles\Core.dir\triangle.cpp.s

# Object files for target Core
Core_OBJECTS = \
"CMakeFiles/Core.dir/camera.cpp.obj" \
"CMakeFiles/Core.dir/light.cpp.obj" \
"CMakeFiles/Core.dir/model.cpp.obj" \
"CMakeFiles/Core.dir/rasterizer.cpp.obj" \
"CMakeFiles/Core.dir/renderbuffer.cpp.obj" \
"CMakeFiles/Core.dir/sceen.cpp.obj" \
"CMakeFiles/Core.dir/shadowmap.cpp.obj" \
"CMakeFiles/Core.dir/texture.cpp.obj" \
"CMakeFiles/Core.dir/triangle.cpp.obj"

# External object files for target Core
Core_EXTERNAL_OBJECTS =

core/libCore.a: core/CMakeFiles/Core.dir/camera.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/light.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/model.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/rasterizer.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/renderbuffer.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/sceen.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/shadowmap.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/texture.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/triangle.cpp.obj
core/libCore.a: core/CMakeFiles/Core.dir/build.make
core/libCore.a: core/CMakeFiles/Core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\code\VSCode Projects\C++\ToyRenderer\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libCore.a"
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && $(CMAKE_COMMAND) -P CMakeFiles\Core.dir\cmake_clean_target.cmake
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Core.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/CMakeFiles/Core.dir/build: core/libCore.a
.PHONY : core/CMakeFiles/Core.dir/build

core/CMakeFiles/Core.dir/clean:
	cd /d "E:\code\VSCode Projects\C++\ToyRenderer\build\core" && $(CMAKE_COMMAND) -P CMakeFiles\Core.dir\cmake_clean.cmake
.PHONY : core/CMakeFiles/Core.dir/clean

core/CMakeFiles/Core.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\code\VSCode Projects\C++\ToyRenderer" "E:\code\VSCode Projects\C++\ToyRenderer\core" "E:\code\VSCode Projects\C++\ToyRenderer\build" "E:\code\VSCode Projects\C++\ToyRenderer\build\core" "E:\code\VSCode Projects\C++\ToyRenderer\build\core\CMakeFiles\Core.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : core/CMakeFiles/Core.dir/depend
