// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <thread>

#include <Open3D/Open3D.h>

using namespace open3d;

std::tuple<std::shared_ptr<geometry::PointCloud>,
	std::shared_ptr<pipelines::registration::Feature>>
	PreprocessPointCloud(const char *file_name) {
	auto pcd = open3d::io::CreatePointCloudFromFile(file_name);
	auto pcd_down = pcd->VoxelDownSample(0.05);
	pcd_down->EstimateNormals(
		open3d::geometry::KDTreeSearchParamHybrid(0.1, 30));
	auto pcd_fpfh = pipelines::registration::ComputeFPFHFeature(
		*pcd_down, open3d::geometry::KDTreeSearchParamHybrid(0.25, 100));
	return std::make_tuple(pcd_down, pcd_fpfh);
}

void VisualizeRegistration(const open3d::geometry::PointCloud &source,
	const open3d::geometry::PointCloud &target,
	const Eigen::Matrix4d &Transformation) {
	std::shared_ptr<geometry::PointCloud> source_transformed_ptr(
		new geometry::PointCloud);
	std::shared_ptr<geometry::PointCloud> target_ptr(new geometry::PointCloud);
	*source_transformed_ptr = source;
	*target_ptr = target;
	source_transformed_ptr->Transform(Transformation);
	visualization::DrawGeometries({ source_transformed_ptr, target_ptr },
		"Registration result");
}

int main(int argc, char *argv[])
{
    std::cout << "Hello World!\n";

	utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);

	if (argc != 3 && argc != 4) {
		utility::LogInfo(
			"Usage : RegistrationRANSAC [path_to_first_point_cloud] "
			"[path_to_second_point_cloud] --visualize");
		return EXIT_FAILURE;
	}

	bool visualize = false;
	if (utility::ProgramOptionExists(argc, argv, "--visualize"))
		visualize = true;

	std::shared_ptr<geometry::PointCloud> source, target;
	std::shared_ptr<pipelines::registration::Feature> source_fpfh, target_fpfh;
	std::tie(source, source_fpfh) = PreprocessPointCloud(argv[1]);
	std::tie(target, target_fpfh) = PreprocessPointCloud(argv[2]);

	std::vector<std::reference_wrapper<
		const pipelines::registration::CorrespondenceChecker>>
		correspondence_checker;
	auto correspondence_checker_edge_length =
		pipelines::registration::CorrespondenceCheckerBasedOnEdgeLength(
			0.9);
	auto correspondence_checker_distance =
		pipelines::registration::CorrespondenceCheckerBasedOnDistance(
			0.075);
	auto correspondence_checker_normal =
		pipelines::registration::CorrespondenceCheckerBasedOnNormal(
			0.52359878);

	correspondence_checker.push_back(correspondence_checker_edge_length);
	correspondence_checker.push_back(correspondence_checker_distance);
	correspondence_checker.push_back(correspondence_checker_normal);
	auto registration_result =
		pipelines::registration::RegistrationRANSACBasedOnFeatureMatching(
			*source, *target, *source_fpfh, *target_fpfh, 0.075,
			pipelines::registration::TransformationEstimationPointToPoint(false),
			4, correspondence_checker,
			pipelines::registration::RANSACConvergenceCriteria(4000000, 1000));

	if (visualize) VisualizeRegistration(*source, *target, registration_result.transformation_);

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
