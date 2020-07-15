// x02LoadPlyFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <pcl/io/ply_io.h>

int main()
{
    std::cout << "Hello World!\n";

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	if (pcl::io::loadPLYFile<pcl::PointXYZRGB>("shoe-pointcloud-00.ply", *cloud) == -1) {
		PCL_ERROR("Couldn't read file.\n");
		return EXIT_FAILURE;
	}

	std::cout << "Loaded "
		<< cloud->width * cloud->height
		<< " data points from loaded file with following fields: "
		<< std::endl;

	int i = 0;
	for (const auto& point : *cloud) {
		std::cout << "	" << point.x
		<< " " << point.y
		<< " " << point.z
		<< " " << point.r
		<< " " << point.g
		<< " " << point.b << std::endl;
		
		if (++i == 10) break;
	}

	return EXIT_SUCCESS;
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
