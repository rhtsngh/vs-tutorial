> How to use PCL library in VC+ project

## Installation
 - Go to [PCL released versions](https://github.com/PointCloudLibrary/pcl/releases) to download suitable version(ex: version [PCL-1.9.1-AllInOne-msvc2017-win32.exe](https://github.com/PointCloudLibrary/pcl/releases/download/pcl-1.9.1/PCL-1.9.1-AllInOne-msvc2017-win32.exe)
 for MSVC2017, x86 project)
 - Add paths to environments:
   - `C:\Program Files (x86)\PCL 1.9.1\bin`
   - `%OPENNI2_REDIST%`

## Usage
 - Config project properties:
   - `C/C++`->`Additional Include Directories`: `C:\Program Files (x86)\PCL 1.9.1\include\pcl-1.9;C:\Program Files (x86)\PCL 1.9.1\3rdParty\Boost\include\boost-1_68;C:\Program Files (x86)\PCL 1.9.1\3rdParty\Eigen\eigen3;C:\Program Files (x86)\PCL 1.9.1\3rdParty\FLANN\include;C:\Program Files (x86)\PCL 1.9.1\3rdParty\Qhull\include;C:\Program Files (x86)\PCL 1.9.1\3rdParty\VTK\include\vtk-8.1;C:\Program Files (x86)\OpenNI2\Include;%(AdditionalIncludeDirectories)`
   - `Linker`->`General`->`Additional Library Directories`: `C:\Program Files (x86)\PCL 1.9.1\lib;C:\Program Files (x86)\PCL 1.9.1\3rdParty\Boost\lib;C:\Program Files (x86)\PCL 1.9.1\3rdParty\FLANN\lib;C:\Program Files (x86)\PCL 1.9.1\3rdParty\Qhull\lib;C:\Program Files (x86)\PCL 1.9.1\3rdParty\VTK\lib;C:\Program Files (x86)\OpenNI2\lib;%(AdditionalLibraryDirectories)`
   - `Linker`->`Input`->`Additional Dependencies`: `pcl_common_debug.lib;pcl_features_debug.lib;pcl_filters_debug.lib;pcl_io_debug.lib;pcl_io_ply_debug.lib;pcl_kdtree_debug.lib;pcl_keypoints_debug.lib;pcl_ml_debug.lib;pcl_octree_debug.lib;pcl_outofcore_debug.lib;pcl_people_debug.lib;pcl_recognition_debug.lib;pcl_registration_debug.lib;pcl_sample_consensus_debug.lib;pcl_search_debug.lib;pcl_segmentation_debug.lib;pcl_stereo_debug.lib;pcl_surface_debug.lib;pcl_tracking_debug.lib;pcl_visualization_debug.lib;libboost_atomic-vc141-mt-gd-x32-1_68.lib;libboost_bzip2-vc141-mt-gd-x32-1_68.lib;libboost_chrono-vc141-mt-gd-x32-1_68.lib;libboost_container-vc141-mt-gd-x32-1_68.lib;libboost_context-vc141-mt-gd-x32-1_68.lib;libboost_contract-vc141-mt-gd-x32-1_68.lib;libboost_coroutine-vc141-mt-gd-x32-1_68.lib;libboost_date_time-vc141-mt-gd-x32-1_68.lib;libboost_exception-vc141-mt-gd-x32-1_68.lib;libboost_fiber-vc141-mt-gd-x32-1_68.lib;libboost_filesystem-vc141-mt-gd-x32-1_68.lib;libboost_graph-vc141-mt-gd-x32-1_68.lib;libboost_graph_parallel-vc141-mt-gd-x32-1_68.lib;libboost_iostreams-vc141-mt-gd-x32-1_68.lib;libboost_locale-vc141-mt-gd-x32-1_68.lib;libboost_log-vc141-mt-gd-x32-1_68.lib;libboost_log_setup-vc141-mt-gd-x32-1_68.lib;libboost_math_c99-vc141-mt-gd-x32-1_68.lib;libboost_math_c99f-vc141-mt-gd-x32-1_68.lib;libboost_math_c99l-vc141-mt-gd-x32-1_68.lib;libboost_math_tr1-vc141-mt-gd-x32-1_68.lib;libboost_math_tr1f-vc141-mt-gd-x32-1_68.lib;libboost_math_tr1l-vc141-mt-gd-x32-1_68.lib;libboost_mpi-vc141-mt-gd-x32-1_68.lib;libboost_numpy27-vc141-mt-gd-x32-1_68.lib;libboost_numpy37-vc141-mt-gd-x32-1_68.lib;libboost_prg_exec_monitor-vc141-mt-gd-x32-1_68.lib;libboost_program_options-vc141-mt-gd-x32-1_68.lib;libboost_python27-vc141-mt-gd-x32-1_68.lib;libboost_python37-vc141-mt-gd-x32-1_68.lib;libboost_random-vc141-mt-gd-x32-1_68.lib;libboost_regex-vc141-mt-gd-x32-1_68.lib;libboost_serialization-vc141-mt-gd-x32-1_68.lib;libboost_signals-vc141-mt-gd-x32-1_68.lib;libboost_stacktrace_noop-vc141-mt-gd-x32-1_68.lib;libboost_stacktrace_windbg-vc141-mt-gd-x32-1_68.lib;libboost_stacktrace_windbg_cached-vc141-mt-gd-x32-1_68.lib;libboost_system-vc141-mt-gd-x32-1_68.lib;libboost_test_exec_monitor-vc141-mt-gd-x32-1_68.lib;libboost_thread-vc141-mt-gd-x32-1_68.lib;libboost_timer-vc141-mt-gd-x32-1_68.lib;libboost_type_erasure-vc141-mt-gd-x32-1_68.lib;libboost_unit_test_framework-vc141-mt-gd-x32-1_68.lib;libboost_wave-vc141-mt-gd-x32-1_68.lib;libboost_wserialization-vc141-mt-gd-x32-1_68.lib;libboost_zlib-vc141-mt-gd-x32-1_68.lib;vtkalglib-8.1-gd.lib;vtkChartsCore-8.1-gd.lib;vtkCommonColor-8.1-gd.lib;vtkCommonComputationalGeometry-8.1-gd.lib;vtkCommonCore-8.1-gd.lib;vtkCommonDataModel-8.1-gd.lib;vtkCommonExecutionModel-8.1-gd.lib;vtkCommonMath-8.1-gd.lib;vtkCommonMisc-8.1-gd.lib;vtkCommonSystem-8.1-gd.lib;vtkCommonTransforms-8.1-gd.lib;vtkDICOMParser-8.1-gd.lib;vtkDomainsChemistry-8.1-gd.lib;vtkexoIIc-8.1-gd.lib;vtkexpat-8.1-gd.lib;vtkFiltersAMR-8.1-gd.lib;vtkFiltersCore-8.1-gd.lib;vtkFiltersExtraction-8.1-gd.lib;vtkFiltersFlowPaths-8.1-gd.lib;vtkFiltersGeneral-8.1-gd.lib;vtkFiltersGeneric-8.1-gd.lib;vtkFiltersGeometry-8.1-gd.lib;vtkFiltersHybrid-8.1-gd.lib;vtkFiltersHyperTree-8.1-gd.lib;vtkFiltersImaging-8.1-gd.lib;vtkFiltersModeling-8.1-gd.lib;vtkFiltersParallel-8.1-gd.lib;vtkFiltersParallelImaging-8.1-gd.lib;vtkFiltersPoints-8.1-gd.lib;vtkFiltersProgrammable-8.1-gd.lib;vtkFiltersSelection-8.1-gd.lib;vtkFiltersSMP-8.1-gd.lib;vtkFiltersSources-8.1-gd.lib;vtkFiltersStatistics-8.1-gd.lib;vtkFiltersTexture-8.1-gd.lib;vtkFiltersTopology-8.1-gd.lib;vtkFiltersVerdict-8.1-gd.lib;vtkfreetype-8.1-gd.lib;vtkGeovisCore-8.1-gd.lib;vtkgl2ps-8.1-gd.lib;vtkhdf5-8.1-gd.lib;vtkhdf5_hl-8.1-gd.lib;vtkImagingColor-8.1-gd.lib;vtkImagingCore-8.1-gd.lib;vtkImagingFourier-8.1-gd.lib;vtkImagingGeneral-8.1-gd.lib;vtkImagingHybrid-8.1-gd.lib;vtkImagingMath-8.1-gd.lib;vtkImagingMorphological-8.1-gd.lib;vtkImagingSources-8.1-gd.lib;vtkImagingStatistics-8.1-gd.lib;vtkImagingStencil-8.1-gd.lib;vtkInfovisCore-8.1-gd.lib;vtkInfovisLayout-8.1-gd.lib;vtkInteractionImage-8.1-gd.lib;vtkInteractionStyle-8.1-gd.lib;vtkInteractionWidgets-8.1-gd.lib;vtkIOAMR-8.1-gd.lib;vtkIOCore-8.1-gd.lib;vtkIOEnSight-8.1-gd.lib;vtkIOExodus-8.1-gd.lib;vtkIOExport-8.1-gd.lib;vtkIOExportOpenGL-8.1-gd.lib;vtkIOGeometry-8.1-gd.lib;vtkIOImage-8.1-gd.lib;vtkIOImport-8.1-gd.lib;vtkIOInfovis-8.1-gd.lib;vtkIOLegacy-8.1-gd.lib;vtkIOLSDyna-8.1-gd.lib;vtkIOMINC-8.1-gd.lib;vtkIOMovie-8.1-gd.lib;vtkIONetCDF-8.1-gd.lib;vtkIOParallel-8.1-gd.lib;vtkIOParallelXML-8.1-gd.lib;vtkIOPLY-8.1-gd.lib;vtkIOSQL-8.1-gd.lib;vtkIOTecplotTable-8.1-gd.lib;vtkIOVideo-8.1-gd.lib;vtkIOXML-8.1-gd.lib;vtkIOXMLParser-8.1-gd.lib;vtkjpeg-8.1-gd.lib;vtkjsoncpp-8.1-gd.lib;vtklibharu-8.1-gd.lib;vtklibxml2-8.1-gd.lib;vtklz4-8.1-gd.lib;vtkmetaio-8.1-gd.lib;vtkNetCDF-8.1-gd.lib;vtknetcdfcpp-8.1-gd.lib;vtkoggtheora-8.1-gd.lib;vtkParallelCore-8.1-gd.lib;vtkpng-8.1-gd.lib;vtkproj4-8.1-gd.lib;vtkRenderingAnnotation-8.1-gd.lib;vtkRenderingContext2D-8.1-gd.lib;vtkRenderingContextOpenGL-8.1-gd.lib;vtkRenderingCore-8.1-gd.lib;vtkRenderingFreeType-8.1-gd.lib;vtkRenderingGL2PS-8.1-gd.lib;vtkRenderingImage-8.1-gd.lib;vtkRenderingLabel-8.1-gd.lib;vtkRenderingLIC-8.1-gd.lib;vtkRenderingLOD-8.1-gd.lib;vtkRenderingOpenGL-8.1-gd.lib;vtkRenderingVolume-8.1-gd.lib;vtkRenderingVolumeOpenGL-8.1-gd.lib;vtksqlite-8.1-gd.lib;vtksys-8.1-gd.lib;vtktiff-8.1-gd.lib;vtkverdict-8.1-gd.lib;vtkViewsContext2D-8.1-gd.lib;vtkViewsCore-8.1-gd.lib;vtkViewsInfovis-8.1-gd.lib;vtkzlib-8.1-gd.lib;OpenNI2.lib;OpenGL32.Lib;%(AdditionalDependencies)`
 - 1 boost library is **deprecated** which cause broken. Therefore it has to config `C/C++`->`Preprocessor`->`Preprocessor Definitions`: `_CRT_SECURE_NO_WARNINGS;_SILENCE_FPOS_SEEKPOS_DEPRECATION_WARNING; VTK_LEGACY_SILENT`
 - Include & Run

## Notice:
 - if it appears error: `'pop_t': identifier not found` in file `dist.h`, please move the line `typedef unsigned long long pop_t;` out of `#if ... #else`(such as to line 475). This is error of FLANN library.

## Appendix

**Python code to get lib-file names from directories:**
```Python
import glob

all_lib_files = []

DIR = "C:/Program Files (x86)/PCL 1.9.1/lib"
lib_files = glob.glob(DIR + "/*debug.lib")
for file in lib_files: all_lib_files.append(os.path.split(file)[1])

DIR = "C:/Program Files (x86)/PCL 1.9.1/3rdParty/Boost/lib"
lib_files = glob.glob(DIR + "/*gd-x32*.lib")
for file in lib_files: all_lib_files.append(os.path.split(file)[1])

DIR = "C:/Program Files (x86)/PCL 1.9.1/3rdParty/VTK/lib"
lib_files = glob.glob(DIR + "/*-gd.lib")
for file in lib_files: all_lib_files.append(os.path.split(file)[1])

all_lib_files.append("OpenNI2.lib")
all_lib_files.append("OpenGL32.Lib")

with open("lib_files.txt", 'w') as file_handler:
    for item in all_lib_files:
        file_handler.write("{}\n".format(item))
```