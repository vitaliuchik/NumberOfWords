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
CMAKE_COMMAND = C:\Users\danyl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6911.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\danyl\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6911.21\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CountWords.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CountWords.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CountWords.dir/flags.make

CMakeFiles/CountWords.dir/main.cpp.obj: CMakeFiles/CountWords.dir/flags.make
CMakeFiles/CountWords.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CountWords.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CountWords.dir\main.cpp.obj -c C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\main.cpp

CMakeFiles/CountWords.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CountWords.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\main.cpp > CMakeFiles\CountWords.dir\main.cpp.i

CMakeFiles/CountWords.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CountWords.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\main.cpp -o CMakeFiles\CountWords.dir\main.cpp.s

CMakeFiles/CountWords.dir/multithread.cpp.obj: CMakeFiles/CountWords.dir/flags.make
CMakeFiles/CountWords.dir/multithread.cpp.obj: ../multithread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CountWords.dir/multithread.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CountWords.dir\multithread.cpp.obj -c C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\multithread.cpp

CMakeFiles/CountWords.dir/multithread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CountWords.dir/multithread.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\multithread.cpp > CMakeFiles\CountWords.dir\multithread.cpp.i

CMakeFiles/CountWords.dir/multithread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CountWords.dir/multithread.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\multithread.cpp -o CMakeFiles\CountWords.dir\multithread.cpp.s

CMakeFiles/CountWords.dir/file_to_vector.cpp.obj: CMakeFiles/CountWords.dir/flags.make
CMakeFiles/CountWords.dir/file_to_vector.cpp.obj: ../file_to_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CountWords.dir/file_to_vector.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CountWords.dir\file_to_vector.cpp.obj -c C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\file_to_vector.cpp

CMakeFiles/CountWords.dir/file_to_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CountWords.dir/file_to_vector.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\file_to_vector.cpp > CMakeFiles\CountWords.dir\file_to_vector.cpp.i

CMakeFiles/CountWords.dir/file_to_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CountWords.dir/file_to_vector.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\file_to_vector.cpp -o CMakeFiles\CountWords.dir\file_to_vector.cpp.s

# Object files for target CountWords
CountWords_OBJECTS = \
"CMakeFiles/CountWords.dir/main.cpp.obj" \
"CMakeFiles/CountWords.dir/multithread.cpp.obj" \
"CMakeFiles/CountWords.dir/file_to_vector.cpp.obj"

# External object files for target CountWords
CountWords_EXTERNAL_OBJECTS =

CountWords.exe: CMakeFiles/CountWords.dir/main.cpp.obj
CountWords.exe: CMakeFiles/CountWords.dir/multithread.cpp.obj
CountWords.exe: CMakeFiles/CountWords.dir/file_to_vector.cpp.obj
CountWords.exe: CMakeFiles/CountWords.dir/build.make
CountWords.exe: C:/msys64/mingw64/lib/libboost_filesystem-mt.dll.a
CountWords.exe: C:/msys64/mingw64/lib/libboost_program_options-mt.dll.a
CountWords.exe: C:/msys64/mingw64/lib/libboost_system-mt.dll.a
CountWords.exe: C:/msys64/mingw64/lib/libboost_locale-mt.dll.a
CountWords.exe: C:/msys64/mingw64/lib/libarchive.dll.a
CountWords.exe: CMakeFiles/CountWords.dir/linklibs.rsp
CountWords.exe: CMakeFiles/CountWords.dir/objects1.rsp
CountWords.exe: CMakeFiles/CountWords.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CountWords.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CountWords.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CountWords.dir/build: CountWords.exe

.PHONY : CMakeFiles/CountWords.dir/build

CMakeFiles/CountWords.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CountWords.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CountWords.dir/clean

CMakeFiles/CountWords.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug C:\sotnyk\UCU\II_year\ACS\Labs\lab4_words_countung\count_words\count_words\cmake-build-debug\CMakeFiles\CountWords.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CountWords.dir/depend

