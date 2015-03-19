vtkOSPRay
======

<h2>About</h2>
vtkOSPRay is a VTK module which utilizes Intel's OSPRay ray tracing framework (http://ospray.github.io) for rendering.  This offers a performant CPU rendering package with enhanced image quality and includes plugins for the commonly used visualization tools ParaView and VisIt.

<h2>Building</h2>
VTK support is built with CMake and tested with the VTK release in ParaView 4.1.0.

pvOSPRay
======

<h2>About</h2>
pvOSPRay is a ParaView plugin which creates a custom view using vtkOSPRay for rendering. Currently tested using ParaView 4.1.0 on linux using ICC.

<h2>Using Existing modules on Stampede and Maverick</h2>
<p>modules are provided for running on TACC's Stampede and Maverick clusters.  A system wide release is planned, but for now module files must of custom loaded with the below instructions </p>
module use /work/01336/carson/opt/modulefiles
module load paraview
module load pvospray
vglrun paraview
the plugin should automatically be loaded. Click the "x" on the top right of the window to close the rendering, and select "OSPRay" to create a pvOSPRay rendering view.

<h2>Building</h2>
build OSPRay, from directions at: http://ospray.github.io
download ParaView source, and preferably create a build directory
git clone https://github.com/TACC/vtkOSPRay.git vtkOSPRayGH
cd <ParaView source directory>/Plugins
cp <path to vtkOSPRayGH>/pvOSPRay pvOSPRay
cd <ParaView build directory>
enable PARAVIEW_BUILD_PLUGIN_OSPRayView
you will need to set the directories of your ospray build


<h2>Running</h2>
Under Tools->"Manage Plugins" select "Load New..." and navigate to the libOSPRayView.so library. Select OSPRayView and click load selected.  Close the plugins window.
Click the "x" on the top right of the window to close the rendering, and select "OSPRay" to create a pvOSPRay rendering view.

VisItOSPRay
======
<h2>About</h2>
VisItOSPRay is available upon request currently, though it is in early development and only working to a limited degree.  A broader release is expected soon.
