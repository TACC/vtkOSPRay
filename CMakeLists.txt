#/***********************************************************************************************************
#Copyright (c) 2015, Carson Brownlee, Texas Advanced Computing Center, Universtiy of Texas at Austin
#All rights reserved.
#
#Redistribution and use in source and binary forms, with or without modification, are permitted provided 
#that the following conditions are met:
#
#1. Redistributions of source code must retain the above copyright notice, this list of conditions and the
# following disclaimer.
#
#2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and 
#the following disclaimer in the documentation and/or other materials provided with the distribution.
#
#3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
# promote products derived from this software without specific prior written permission.
#
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
#WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
#PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
#FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
#INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
#OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN 
#IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#***********************************************************************************************************/
#vtkOSPRay is an interface from VTK's rendering classes to Manta,
#a "real time" Ray Tracer.

#It creates a library that includes Manta specific subclasses
#of VTK's rendering classes, Renderer, Camera, etc.
#These can be instantiated by name, or by using object factory overloading
#at post compile time (ie, set VTK_AUTOLOAD_PATH to vtkOSPRay's build
#directory and run a normal vtk app)

project(vtkOSPRay)


#Configure vtkOSPRay source proper ############################################

# Define a flag
if (BUILD_AGAINST_PARAVIEW)
  add_definitions(-DVTKOSPRAY_FOR_PARAVIEW)
endif()




# setup include paths
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})
message("cmake_current_binary_dir: " ${CMAKE_CURRENT_BINARY_DIR})
message("project source dir: " ${PROJECT_SOURCE_DIR})
message("project binary dir: " ${PROJECT_BINARY_DIR})



# Set vtkOSPRay source files.
SET ( MANTA_CLASSES
  vtkOSPRayActor.cxx
  vtkOSPRayCamera.cxx
  vtkOSPRayLight.cxx
  vtkOSPRayManager.cxx
  vtkOSPRayPolyDataMapper.cxx
  vtkOSPRayProperty.cxx
  vtkOSPRayRenderer.cxx
  vtkOSPRayTestSource.cxx
  vtkOSPRayTexture.cxx
  vtkOSPRayVolumeMapper.cxx
  )

IF (BUILD_AGAINST_PARAVIEW)
  # paraview uses its own LOD actor, put it in here
  SET ( MANTA_CLASSES ${MANTA_CLASSES}
    vtkOSPRayLODActor.cxx
    vtkPVOSPRayRepresentation.cxx
    vtkOSPRayCompositeMapper.cxx)
ENDIF (BUILD_AGAINST_PARAVIEW)

SET ( MANTA_SRCS
  ${MANTA_CLASSES}
  vtkOSPRayObjectFactory.cxx
  )

set (${vtk-module}_NO_HeaderTest 1)

vtk_module_library(${vtk-module} ${MANTA_SRCS})
find_package(OSPRay)
MESSAGE("ospray libs:" + ${OSPRAY_LIBRARIES})
MESSAGE("vtk-module: " + ${vtk-module})
TARGET_LINK_LIBRARIES (${vtk-module} LINK_PRIVATE ${OSPRAY_LIBRARIES})

# Manta_Core uses MMTime which is in it's own special library.
if(WIN32)
  TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PRIVATE Winmm)
endif()

#Examples ####################################################################
IF ( BUILD_EXAMPLES )
  ADD_SUBDIRECTORY(Examples)
ENDIF ( BUILD_EXAMPLES )
