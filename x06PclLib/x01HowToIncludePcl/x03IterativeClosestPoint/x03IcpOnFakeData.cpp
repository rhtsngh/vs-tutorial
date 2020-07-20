// x03IterativeClosestPoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <pcl/io/pcd_io.h> // ?
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <iostream>


int main(int argc, char** argv)
{
	std::cout << "Hello World! This is ICP test program.\n";

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZ>(5, 1)); // diff Ptr & ConstPtr?
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>);

	// Initialize fake data for cloud_in
	for (auto& point : *cloud_in) {
		point.x = 1024 * rand() / (RAND_MAX + 1.0f);
		point.y = 1024 * rand() / (RAND_MAX + 1.0f);
		point.z = 1024 * rand() / (RAND_MAX + 1.0f);
	}

	*cloud_out = *cloud_in; // cloud_out has same values from cloud_in
	for (auto& point : *cloud_out) { // modify cloud_out a little
		point.x += 0.7f;
	}

	// Display values
	for (auto& point : *cloud_in) std::cout << point << " ";
	std::cout << std::endl;
	for (auto& point : *cloud_out) std::cout << point << " ";
	std::cout << std::endl;

	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
	icp.setInputSource(cloud_in);
	icp.setInputTarget(cloud_out);

	pcl::PointCloud<pcl::PointXYZ> Final;
	icp.align(Final); // Q: what is this final? matching operation? A: resultant cloud after applying the algorithm

	std::cout << "Has converged: " << icp.hasConverged() << " score: " << icp.getFitnessScore() << std::endl;
	std::cout << icp.getFinalTransformation() << std::endl;

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
