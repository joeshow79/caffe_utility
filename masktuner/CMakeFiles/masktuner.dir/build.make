# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jasonjmac/src/caffe_utility/masktuner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jasonjmac/src/caffe_utility/masktuner

# Include any dependencies generated for this target.
include CMakeFiles/masktuner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/masktuner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/masktuner.dir/flags.make

CMakeFiles/masktuner.dir/masktuner.cpp.o: CMakeFiles/masktuner.dir/flags.make
CMakeFiles/masktuner.dir/masktuner.cpp.o: masktuner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jasonjmac/src/caffe_utility/masktuner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/masktuner.dir/masktuner.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/masktuner.dir/masktuner.cpp.o -c /Users/jasonjmac/src/caffe_utility/masktuner/masktuner.cpp

CMakeFiles/masktuner.dir/masktuner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/masktuner.dir/masktuner.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jasonjmac/src/caffe_utility/masktuner/masktuner.cpp > CMakeFiles/masktuner.dir/masktuner.cpp.i

CMakeFiles/masktuner.dir/masktuner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/masktuner.dir/masktuner.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jasonjmac/src/caffe_utility/masktuner/masktuner.cpp -o CMakeFiles/masktuner.dir/masktuner.cpp.s

CMakeFiles/masktuner.dir/masktuner.cpp.o.requires:

.PHONY : CMakeFiles/masktuner.dir/masktuner.cpp.o.requires

CMakeFiles/masktuner.dir/masktuner.cpp.o.provides: CMakeFiles/masktuner.dir/masktuner.cpp.o.requires
	$(MAKE) -f CMakeFiles/masktuner.dir/build.make CMakeFiles/masktuner.dir/masktuner.cpp.o.provides.build
.PHONY : CMakeFiles/masktuner.dir/masktuner.cpp.o.provides

CMakeFiles/masktuner.dir/masktuner.cpp.o.provides.build: CMakeFiles/masktuner.dir/masktuner.cpp.o


# Object files for target masktuner
masktuner_OBJECTS = \
"CMakeFiles/masktuner.dir/masktuner.cpp.o"

# External object files for target masktuner
masktuner_EXTERNAL_OBJECTS =

masktuner: CMakeFiles/masktuner.dir/masktuner.cpp.o
masktuner: CMakeFiles/masktuner.dir/build.make
masktuner: /usr/local/lib/libopencv_stitching.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_superres.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_videostab.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_aruco.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_bgsegm.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_bioinspired.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_ccalib.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_dpm.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_face.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_fuzzy.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_img_hash.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_line_descriptor.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_optflow.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_reg.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_rgbd.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_saliency.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_stereo.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_structured_light.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_surface_matching.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_tracking.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_xfeatures2d.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_ximgproc.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_xobjdetect.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_xphoto.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_shape.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_photo.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_calib3d.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_phase_unwrapping.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_dnn.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_video.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_datasets.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_plot.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_text.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_features2d.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_flann.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_highgui.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_ml.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_videoio.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_imgcodecs.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_objdetect.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_imgproc.3.3.0.dylib
masktuner: /usr/local/lib/libopencv_core.3.3.0.dylib
masktuner: CMakeFiles/masktuner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jasonjmac/src/caffe_utility/masktuner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable masktuner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/masktuner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/masktuner.dir/build: masktuner

.PHONY : CMakeFiles/masktuner.dir/build

CMakeFiles/masktuner.dir/requires: CMakeFiles/masktuner.dir/masktuner.cpp.o.requires

.PHONY : CMakeFiles/masktuner.dir/requires

CMakeFiles/masktuner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/masktuner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/masktuner.dir/clean

CMakeFiles/masktuner.dir/depend:
	cd /Users/jasonjmac/src/caffe_utility/masktuner && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jasonjmac/src/caffe_utility/masktuner /Users/jasonjmac/src/caffe_utility/masktuner /Users/jasonjmac/src/caffe_utility/masktuner /Users/jasonjmac/src/caffe_utility/masktuner /Users/jasonjmac/src/caffe_utility/masktuner/CMakeFiles/masktuner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/masktuner.dir/depend

