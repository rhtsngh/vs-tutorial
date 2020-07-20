

## [Example 1](ConsoleApplication1/ConsoleApplication1/ConsoleApplication1.cpp): Demonstration how to use SFML
 - Config VS project `Configurations`**:** `All Configurations` & `Platform`: `Win32`
 - `Configuration Properties -> C/C++ -> General` -> `Addinational Include Directories`**:** `D:\WORKSPACES\LIBRARIES\SFML\x86\include;%(AdditionalIncludeDirectories)`
 - `Configuration Properties -> Linker -> General` -> `Addinational Library Directories`**:** `D:\WORKSPACES\LIBRARIES\SFML\x86\lib;%(AdditionalLibraryDirectories)`
 - `Configuration Properties -> Linker -> Input` -> `Addinational Dependencies`**:** `sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-main.lib;sfml-network.lib;openal32.lib;freetype.lib;%(AdditionalDependencies)`
 - `Configuration Properties -> Build Events -> Pre-Build Event` -> `Command Line`**:** `xcopy /y /d /f "D:\WORKSPACES\LIBRARIES\SFML\x86\bin\*.dll" "$(OutDir)"`

## [Example 2](): Demonstration how to use SFML-ImGui
*Fail*

## [Example 3](ConsoleApplication3/ConsoleApplication3/ConsoleApplication3.cpp): Demonstration how to use ImGui-directX11
 - `Configuration Properties -> Linker -> Input` -> `Addinational Dependencies`**:** `d3d11.lib;d3dcompiler.lib;dxgi.lib;%(AdditionalDependencies)`
 - Copy `imconfig.h` `imgui.cpp` `imgui.h` `imgui_demo.cpp imgui_draw.cpp` `imgui_impl_dx11.cpp` `imgui_impl_dx11.h` `imgui_impl_win32.cpp` `imgui_impl_win32.h` `imgui_internal.h` `imgui_widgets.cpp` `imstb_rectpack.h` `imstb_textedit.h` `imstb_truetype.h` into a subfolder `imgui` in project
 - Add `Existing Item..`**:** all those copied files

## [Example 4](ConsoleApplication4/ConsoleApplication4/ConsoleApplication4.cpp): Demonstration how to use ImGui-OpenGL3(similar Example 3)
 - Config VS project `Configurations`**:** `All Configurations` & `Platform`: `Win32`
 - Copy `imconfig.h` `imgui.cpp` `imgui.h` `imgui_demo.cpp imgui_draw.cpp` `imgui_impl_glfw.cpp` `imgui_impl_glfw.h` `imgui_impl_opengl3.cpp` `imgui_impl_opengl3.h` `imgui_internal.h` `imgui_widgets.cpp` `imstb_rectpack.h` `imstb_textedit.h` `imstb_truetype.h` into a subfolder `imgui` in project
 - Copy `libs`(which contains `gl3w` & `glfw`) into `imgui` folder
 - Add `Existing Item..`**:** all those copied files
 - `Configuration Properties -> C/C++ -> General` -> `Addinational Include Directories`**:** `D:\WORKSPACES\VisualStudio\vs-tutorial\x07ImguiLib\ConsoleApplication4\ConsoleApplication4\imgui;D:\WORKSPACES\VisualStudio\vs-tutorial\x07ImguiLib\ConsoleApplication4\ConsoleApplication4\imgui\libs\gl3w;D:\WORKSPACES\VisualStudio\vs-tutorial\x07ImguiLib\ConsoleApplication4\ConsoleApplication4\imgui\libs\glfw\include;%(AdditionalIncludeDirectories)`
 - `Configuration Properties -> Linker -> General` -> `Addinational Library Directories`**:** `D:\WORKSPACES\VisualStudio\vs-tutorial\x07ImguiLib\ConsoleApplication4\ConsoleApplication4\imgui\libs\glfw\lib-vc2010-32;%(AdditionalLibraryDirectories)`
 - `Configuration Properties -> Linker -> Input` -> `Addinational Dependencies`**:** `opengl32.lib;glfw3.lib;%(AdditionalDependencies)`

## [Example 5](): Demonstration how to use Nukclear-ImGui???
**Source library**: https://github.com/Immediate-Mode-UI/Nuklear










