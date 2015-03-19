cmake_minimum_required(VERSION 2.8.8)
project(OSPRayView)

# FIXME: this is ABSURD!!! Needs to be removed. I don't have time right now.
set (BUILD_AGAINST_PARAVIEW 1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
  "${CMAKE_SOURCE_DIR}/Plugins/pvOSPRay/CMake/")
MESSAGE("pvOSPRay CMAKE_MODULE_PATH" ${CMAKE_MODULE_PATH})


#
# ospray
# 
find_package(OSPRay)
INCLUDE_DIRECTORIES(${OSPRAY_INCLUDE_DIRS})
#
#
# 


# -----------------------------------------------------------------------------
# Process all vtk-modules defined in this plugin. This generates the necessary
# wrappings for all these modules as well.
# -----------------------------------------------------------------------------
pv_process_modules()

# -----------------------------------------------------------------------------
# Build the Paraview plugins
# -----------------------------------------------------------------------------
add_subdirectory(ParaView)
