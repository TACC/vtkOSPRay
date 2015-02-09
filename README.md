vtkOSPRay
======

<h2>NOTICE</h2>
<p>Currently vtkOSPRay is awaiting approval for release.  Here are the current source checkout and build instructions for those with priviledges on TACC's stampede system and group access to the private repository.  These instructions will be updated upon release.
</p>

<h2>About</h2>
vtkOSPRay is a VTK module which utilizes Intel's OSPRay ray tracing framework (http://ospray.github.io) for rendering.  This offers a performant CPU rendering package with enhanced image quality.  

<h2>Building</h2>
Please see pvOSPRay section for building in ParaView.  VTK support is built with CMake and tested with the VTK release in ParaView 4.1.0.


pvOSPRay
======

<h2>About</h2>
pvOSPRay is a ParaView plugin which creates a custom view using vtkOSPRay for rendering. Currently tested using ParaView 4.1.0 on linux using ICC.

<h2>Using Existing modules on Stampede and Maverick</h2>
module use /work/01336/carson/opt/modulefiles
module load paraview
module load pvospray
vglrun paraview
the plugin should automatically be loaded. Click the "x" on the top right of the window to close the rendering, and select "OSPRay" to create a pvOSPRay rendering view.

<h2>Building</h2>
build OSPRay, from directions at: http://ospray.github.io
download ParaView source, and preferably create a build directory
cd <ParaView source directory>/Plugins
git clone wald@stampede.tacc.utexas.edu:pvOSPRay pvOSPRay
cd pvOSPRay
git clone wald@stampede.tacc.utexas.edu:vtkOSPRay VTK
cd <ParaView build directory>
enable PARAVIEW_BUILD_PLUGIN_OSPRayView


<h2>Running</h2>
Under Tools->"Manage Plugins" select "Load New..." and navigate to the libOSPRayView.so library. Select OSPRayView and click load selected.  Close the plugins window.
Click the "x" on the top right of the window to close the rendering, and select "OSPRay" to create a pvOSPRay rendering view.
