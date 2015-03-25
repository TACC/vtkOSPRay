vtkOSPRay
======

<h2>About</h2>
The base VTK code without ParaView is contained in the VTK directory and makes up vtkOSPRay.  vtkOSPRay is a VTK module which utilizes Intel's OSPRay ray tracing framework (http://ospray.github.io) for rendering.  This offers a performant CPU rendering package with enhanced image quality and includes plugins for the commonly used visualization tools ParaView and VisIt.

<h2>Building</h2>
VTK support is built with CMake and tested with the VTK release in ParaView 4.1.0.  

pvOSPRay
======

<h2>About</h2>
pvOSPRay is a ParaView plugin which creates a custom view using vtkOSPRay for rendering. Currently tested using ParaView 4.1.0 on linux using ICC.  The code for ParaView, the plugin, and the base VTK code are all contained in the base of the vtkOSRPay repository.

<h2>Using Existing modules on Stampede and Maverick</h2>
<p>modules are provided for running on TACC's Stampede and Maverick clusters.  A system wide release is planned, but for now module files must of custom loaded with the below instructions </p>
<lu>
<li>module use /work/01336/carson/opt/modulefiles</li>
<li>module load paraview</li>
<li>module load pvospray</li>
<li>vglrun paraview</li>
<li>the plugin should automatically be loaded. Click the "x" on the top right of the window to close the rendering, and select "OSPRay" to create a pvOSPRay rendering view.</li>
</lu>

<h2>Building</h2>
build OSPRay, from directions at: http://ospray.github.io
download ParaView source, and preferably create a build directory
cd <ParaView source directory>/Plugins
git clone https://github.com/TACC/vtkOSPRay.git pvOSPRay
cd <ParaView build directory>
enable PARAVIEW_BUILD_PLUGIN_OSPRayView
you will need to set the relevant OSPRAY_DIR and OSPRAY_BUILD_DIR to the checkout of OSPRay repo and the build directory.


<h2>Running</h2>
Under Tools->"Manage Plugins" select "Load New..." and navigate to the libOSPRayView.so library. Select OSPRayView and click load selected.  Close the plugins window.
Click the "x" on the top right of the window to close the rendering, and select "OSPRay" to create a pvOSPRay rendering view.

VisItOSPRay
======
<h2>About</h2>
VisItOSPRay is available upon request currently, though it is in early development and only working to a limited degree.  A broader release is expected soon.
