// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <thread>

#include <Open3D/Open3D.h>

using namespace open3d;

int main(int argc, char *argv[])
{
    std::cout << "Hello World!\n";

	utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);
	if (argc < 3) {
		utility::LogInfo("Open3D {}\n", OPEN3D_VERSION);
		utility::LogInfo("\n");
		utility::LogInfo("Usage:\n");
		utility::LogInfo("    > TestVisualizer [mesh|pointcloud] [filename]\n");
		// CI will execute this file without input files, return 0 to pass
		return 0;
	}

	std::string option(argv[1]);
	if (option == "mesh") {
		auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
		if (io::ReadTriangleMesh(argv[2], *mesh_ptr)) {
			utility::LogInfo("Successfully read {}\n", argv[2]);
		}
		else {
			utility::LogWarning("Failed to read {}\n\n", argv[2]);
			return 1;
		}
		mesh_ptr->ComputeVertexNormals();
		visualization::DrawGeometries({ mesh_ptr }, "Mesh", 1600, 900);
	}
	else if (option == "pointcloud") {
		auto cloud_ptr = std::make_shared<geometry::PointCloud>();
		if (io::ReadPointCloud(argv[2], *cloud_ptr)) {
			utility::LogInfo("Successfully read {}\n", argv[2]);
		}
		else {
			utility::LogWarning("Failed to read {}\n\n", argv[2]);
			return 1;
		}
		cloud_ptr->NormalizeNormals();
		visualization::DrawGeometries({ cloud_ptr }, "PointCloud", 1600, 900);
	}
	else {
		utility::LogWarning("Unrecognized option: {}\n", option);
		return 1;
	}
	utility::LogInfo("End of the test.\n");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
