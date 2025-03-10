//This module provides test benches that can be invoked through a command-line switch
//Author: Bryan Poling
//Copyright (c) 2021 Sentek Systems, LLC. All rights reserved. 

//System Includes
//#include <tuple>
#include <iostream>
#include <chrono>

//External Includes
#include "../../handycpp/Handy.hpp"
#include <opencv2/opencv.hpp>
//#include <opencv2/core/persistence.hpp>

//TorchLib Includes
#include "../../libtorch-cxx11-abi-shared-with-deps-1.8.1+cpu/libtorch/include/torch/csrc/api/include/torch/torch.h"

//Project Includes
#include "TestBenches.hpp"
#include "Polygon.hpp"
#include "SurveyRegionManager.hpp"
#include "Maps/MapUtils.hpp"
#include "Modules/Guidance/Guidance.hpp"
#include "Modules/DJI-Drone-Interface/DroneManager.hpp"
#include "Modules/DJI-Drone-Interface/DroneComms.hpp"

#define PI 3.14159265358979

// Local function declarations (static linkage)
static bool TestBench0(std::string const & Arg);   static bool TestBench1(std::string const & Arg);
static bool TestBench2(std::string const & Arg);   static bool TestBench3(std::string const & Arg);
static bool TestBench4(std::string const & Arg);   static bool TestBench5(std::string const & Arg);
static bool TestBench6(std::string const & Arg);   static bool TestBench7(std::string const & Arg);
static bool TestBench8(std::string const & Arg);   static bool TestBench9(std::string const & Arg);
static bool TestBench10(std::string const & Arg);  static bool TestBench11(std::string const & Arg);
static bool TestBench12(std::string const & Arg);  static bool TestBench13(std::string const & Arg);
static bool TestBench14(std::string const & Arg);  static bool TestBench15(std::string const & Arg);
static bool TestBench16(std::string const & Arg);  static bool TestBench17(std::string const & Arg);
static bool TestBench18(std::string const & Arg);  static bool TestBench19(std::string const & Arg);
static bool TestBench20(std::string const & Arg);  static bool TestBench21(std::string const & Arg);
static bool TestBench22(std::string const & Arg);  static bool TestBench23(std::string const & Arg);
static bool TestBench24(std::string const & Arg);  static bool TestBench25(std::string const & Arg);
static bool TestBench26(std::string const & Arg);

// ************************************************************************************************************************************************
// *********************************************************   Public Function Definitions   ******************************************************
// ************************************************************************************************************************************************

namespace TestBenches {
	void RunTestBench(int TestNum, std::string const & TestBenchArg) {
		if ((TestNum < 0) || (TestNum >= (int) AvailableTestBenches.size())) {
			std::cerr << "Invalid testbench index. Aborting.\r\n";
			return;
		}
		std::cerr << "Running Test number " << TestNum << "\r\n";
		std::cerr << "TestBench description: " << AvailableTestBenches[TestNum] << "\r\n";
		bool result = false;
		switch (TestNum) {
			case 0:  result = TestBench0(TestBenchArg);  break;
			case 1:  result = TestBench1(TestBenchArg);  break;
			case 2:  result = TestBench2(TestBenchArg);  break;
			case 3:  result = TestBench3(TestBenchArg);  break;
			case 4:  result = TestBench4(TestBenchArg);  break;
			case 5:  result = TestBench5(TestBenchArg);  break;
			case 6:  result = TestBench6(TestBenchArg);  break;
			case 7:  result = TestBench7(TestBenchArg);  break;
			case 8:  result = TestBench8(TestBenchArg);  break;
			case 9:  result = TestBench9(TestBenchArg);  break;
			case 10: result = TestBench10(TestBenchArg); break;
			case 11: result = TestBench11(TestBenchArg); break;
			case 12: result = TestBench12(TestBenchArg); break;
			case 13: result = TestBench13(TestBenchArg); break;
			case 14: result = TestBench14(TestBenchArg); break;
			case 15: result = TestBench15(TestBenchArg); break;
			case 16: result = TestBench16(TestBenchArg); break;
			case 17: result = TestBench17(TestBenchArg); break;
			case 18: result = TestBench18(TestBenchArg); break;
			case 19: result = TestBench19(TestBenchArg); break;
			case 20: result = TestBench20(TestBenchArg); break;
			case 21: result = TestBench21(TestBenchArg); break;
			case 22: result = TestBench22(TestBenchArg); break;
			case 23: result = TestBench23(TestBenchArg); break;
			case 24: result = TestBench24(TestBenchArg); break;
			case 25: result = TestBench25(TestBenchArg); break;
			case 26: result = TestBench26(TestBenchArg); break;
			default: break;
		}
		if (result)
			std::cerr << "Testbench passed.\r\n";
		else
			std::cerr << "Testbench failed.\r\n";
	}
}

// ************************************************************************************************************************************************
// ********************************************************   Internal Function Definitions   *****************************************************
// ************************************************************************************************************************************************

static bool TestBench0(std::string const & Arg) {
	std::Evector<LineSegment> InputSegments;
	InputSegments.emplace_back(Eigen::Vector2d(0.0, 0.0), Eigen::Vector2d(1.0, 0.0));
	InputSegments.emplace_back(Eigen::Vector2d(0.0, 0.0), Eigen::Vector2d(0.0, 1.0));
	std::Evector<LineSegment> OutputSegments = BreakAtIntersections(InputSegments);
	std::cerr << "Input Segments:\r\n";
	for (auto const & item : InputSegments)
		std::cerr << item << "\r\n";
	std::cerr << "Output Segments:\r\n";
	for (auto const & item : OutputSegments)
		std::cerr << item << "\r\n";
	std::cerr << "\r\n";
	
	InputSegments.clear();
	InputSegments.emplace_back(Eigen::Vector2d(0.0,  0.0), Eigen::Vector2d(1.0, 0.0));
	InputSegments.emplace_back(Eigen::Vector2d(0.01, 0.0), Eigen::Vector2d(0.0, 1.0));
	OutputSegments = BreakAtIntersections(InputSegments);
	std::cerr << "Input Segments:\r\n";
	for (auto const & item : InputSegments)
		std::cerr << item << "\r\n";
	std::cerr << "Output Segments:\r\n";
	for (auto const & item : OutputSegments)
		std::cerr << item << "\r\n";
	std::cerr << "\r\n";
	
	InputSegments.clear();
	InputSegments.emplace_back(Eigen::Vector2d(0.0,  0.0), Eigen::Vector2d(5.0,  0.0));
	InputSegments.emplace_back(Eigen::Vector2d(0.0, -1.0), Eigen::Vector2d(0.0,  1.0));
	InputSegments.emplace_back(Eigen::Vector2d(0.0,  1.0), Eigen::Vector2d(1.0, -1.0));
	InputSegments.emplace_back(Eigen::Vector2d(1.0, -1.0), Eigen::Vector2d(2.0,  1.0));
	InputSegments.emplace_back(Eigen::Vector2d(2.0,  1.0), Eigen::Vector2d(3.0, -1.0));
	InputSegments.emplace_back(Eigen::Vector2d(3.0, -1.0), Eigen::Vector2d(3.0,  1.0));
	OutputSegments = BreakAtIntersections(InputSegments);
	std::cerr << "Input Segments:\r\n";
	for (auto const & item : InputSegments)
		std::cerr << item << "\r\n";
	std::cerr << "Output Segments:\r\n";
	for (auto const & item : OutputSegments)
		std::cerr << item << "\r\n";
	std::cerr << "\r\n";
	
	return true;
}

static bool TestBench1(std::string const & Arg) {
	SimplePolygon poly;
	std::Evector<Eigen::Vector2d> vertices;
	
	//Test if simple polygon is left unchanged
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 0.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(0.0, 1.0);
	poly.SetBoundary(vertices);
	std::cerr << "Sanitized Simple Polygon:\r\n" << poly << "\r\n";
	
	//Test if simple polygon is left unchanged
	vertices.clear();
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 0.1);
	vertices.emplace_back(1.1, 1.1);
	vertices.emplace_back(0.1, 0.9);
	poly.SetBoundary(vertices);
	std::cerr << "Sanitized Simple Polygon:\r\n" << poly << "\r\n";
	
	//Test order reversal of simple polygon
	vertices.clear();
	vertices.emplace_back(0.0, 1.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(1.0, 0.0);
	vertices.emplace_back(0.5, 0.0);
	vertices.emplace_back(0.0, 0.0);
	poly.SetBoundary(vertices);
	std::cerr << "Sanitized Simple Polygon:\r\n" << poly << "\r\n";
	
	//Test order reversal of simple polygon
	vertices.clear();
	vertices.emplace_back(1.1, 1.1);
	vertices.emplace_back(1.0, 0.1);
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(0.1, 0.9);
	poly.SetBoundary(vertices);
	std::cerr << "Sanitized Simple Polygon:\r\n" << poly << "\r\n";
	
	//Test tracing for simple self-intersecting polygon
	vertices.clear();
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(0.0, 1.0);
	vertices.emplace_back(1.0, 0.0);
	poly.SetBoundary(vertices);
	std::cerr << "Sanitized Simple Polygon:\r\n" << poly;
	std::cerr << "Area: " << poly.GetArea() << "\r\n";
	
	//Test winding-number polygon inclusion test
	Eigen::Vector2d P;
	P << 0, 0;
	std::cerr << "(" << P(0) << ", " << P(1) << ") is " << (poly.ContainsPoint(P) ? "in"s : "not in"s) << " polygon.\r\n";
	P << -0.01, 0;
	std::cerr << "(" << P(0) << ", " << P(1) << ") is " << (poly.ContainsPoint(P) ? "in"s : "not in"s) << " polygon.\r\n";
	P << 0.01, 0.005;
	std::cerr << "(" << P(0) << ", " << P(1) << ") is " << (poly.ContainsPoint(P) ? "in"s : "not in"s) << " polygon.\r\n";
	P << 0.5, 0.25;
	std::cerr << "(" << P(0) << ", " << P(1) << ") is " << (poly.ContainsPoint(P) ? "in"s : "not in"s) << " polygon.\r\n";
	P << 0.0, 0.5;
	std::cerr << "(" << P(0) << ", " << P(1) << ") is " << (poly.ContainsPoint(P) ? "in"s : "not in"s) << " polygon.\r\n";
	
	std::cerr << "\r\n";
	
	return true;
}

static bool TestBench2(std::string const & Arg) {
	SimplePolygon polyA, polyB;
	std::Evector<Eigen::Vector2d> vertices;
	
	//Simple Test - polygon with itself
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 0.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(0.0, 1.0);
	polyA.SetBoundary(vertices);
	polyB.SetBoundary(vertices);
	std::cerr << "*** Before Fragmentation ***\r\n";
	std::cerr << "Polygon A:\r\n" << polyA << "\r\n";
	std::cerr << "Polygon B:\r\n" << polyB << "\r\n";
	polyA.FragmentIntersections(polyB);
	std::cerr << "*** After Fragmentation ***\r\n";
	std::cerr << "Polygon A:\r\n" << polyA << "\r\n";
	std::cerr << "Polygon B:\r\n" << polyB << "\r\n";
	
	//Simple Test
	vertices.clear();
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 0.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(0.0, 1.0);
	polyA.SetBoundary(vertices);
	vertices.clear();
	vertices.emplace_back(0.5, 0.25);
	vertices.emplace_back(1.5, 0.25);
	vertices.emplace_back(1.5, 0.75);
	vertices.emplace_back(0.5, 0.75);
	polyB.SetBoundary(vertices);
	std::cerr << "*** Before Fragmentation ***\r\n";
	std::cerr << "Polygon A:\r\n" << polyA << "\r\n";
	std::cerr << "Polygon B:\r\n" << polyB << "\r\n";
	polyA.FragmentIntersections(polyB);
	std::cerr << "*** After Fragmentation ***\r\n";
	std::cerr << "Polygon A:\r\n" << polyA << "\r\n";
	std::cerr << "Polygon B:\r\n" << polyB << "\r\n";
	
	//Simple Test
	vertices.clear();
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 0.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(0.0, 1.0);
	polyA.SetBoundary(vertices);
	vertices.clear();
	vertices.emplace_back(0.5, 0.0);
	vertices.emplace_back(1.5, 0.0);
	vertices.emplace_back(1.5, 1.0);
	vertices.emplace_back(0.5, 1.0);
	polyB.SetBoundary(vertices);
	std::cerr << "*** Before Fragmentation ***\r\n";
	std::cerr << "Polygon A:\r\n" << polyA << "\r\n";
	std::cerr << "Polygon B:\r\n" << polyB << "\r\n";
	polyA.FragmentIntersections(polyB);
	std::cerr << "*** After Fragmentation ***\r\n";
	std::cerr << "Polygon A:\r\n" << polyA << "\r\n";
	std::cerr << "Polygon B:\r\n" << polyB << "\r\n";
	
	return true;
}

static bool TestBench3(std::string const & Arg) {
	Polygon poly;
	std::Evector<Eigen::Vector2d> vertices;
	vertices.emplace_back(0.0, 0.0);
	vertices.emplace_back(1.0, 0.0);
	vertices.emplace_back(1.0, 1.0);
	vertices.emplace_back(0.0, 1.0);
	poly.m_boundary.SetBoundary(vertices);
	
	std::Evector<Triangle> Triangles;
	poly.Triangulate(Triangles);
	std::cerr << "Triangulation:\r\n";
	for (auto const & triangle : Triangles)
		std::cerr << triangle << "\r\n";
	std::cerr << "\r\n";
	
	vertices.clear();
	vertices.emplace_back(0.2, 0.2);
	vertices.emplace_back(0.8, 0.2);
	vertices.emplace_back(0.8, 0.8);
	vertices.emplace_back(0.2, 0.8);
	poly.m_holes.emplace_back();
	poly.m_holes.back().SetBoundary(vertices);
	
	Triangles.clear();
	poly.Triangulate(Triangles);
	std::cerr << "Triangulation:\r\n";
	for (auto const & triangle : Triangles)
		std::cerr << triangle << "\r\n";
	std::cerr << "\r\n";
	
	return true;
	
}

static bool TestBench4(std::string const & Arg) {
	std::Evector<Eigen::Vector2d> vertices;
	
	{
		SurveyRegion region;
		region.m_Name = "Test Region"s;
		
		vertices.clear();
		vertices.emplace_back(0.0, 0.0);
		vertices.emplace_back(1.0, 0.0);
		vertices.emplace_back(1.0, 1.0);
		vertices.emplace_back(0.0, 1.0);
		region.m_Region.m_components.emplace_back();
		region.m_Region.m_components.back().m_boundary.SetBoundary(vertices);
		
		vertices.clear();
		vertices.emplace_back(0.2, 0.2);
		vertices.emplace_back(0.8, 0.2);
		vertices.emplace_back(0.8, 0.8);
		vertices.emplace_back(0.2, 0.8);
		region.m_Region.m_components.back().m_holes.emplace_back();
		region.m_Region.m_components.back().m_holes.back().SetBoundary(vertices);
		
		vertices.clear();
		vertices.emplace_back(2.0, 0.0);
		vertices.emplace_back(3.0, 0.0);
		vertices.emplace_back(2.5, 1.5);
		region.m_Region.m_components.emplace_back();
		region.m_Region.m_components.back().m_boundary.SetBoundary(vertices);
		//On destruction, region should be saved to disk automatically
	}
	
	{
		SurveyRegion region("Test Region"s); //Should load from disk
		std::cerr << "Region Contents:\r\n";
		std::cerr << region.m_Region;
		std::cerr << "\r\n\r\n";
		std::cerr << "Triangulation:\r\n";
		for (auto const & t : region.m_triangulation)
			std::cerr << t << "\r\n";
		std::cerr << "\r\n";
	}
	
	return true;
	
}

static bool TestBench5(std::string const & Arg) {
	std::Evector<Eigen::Vector2d> vertices;
	
	{
		SurveyRegion region;
		region.m_Name = "Minneapolis Sample Region"s;
		
		vertices.clear();
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982718, -93.290769)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982199, -93.290775)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982212, -93.290120)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.981684, -93.289543)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.981813, -93.288494)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982791, -93.288633)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982671, -93.289731)));
		region.m_Region.m_components.emplace_back();
		region.m_Region.m_components.back().m_boundary.SetBoundary(vertices);
		
		vertices.clear();
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982401, -93.289944)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982255, -93.289962)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982259, -93.289604)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982439, -93.289628)));
		region.m_Region.m_components.back().m_holes.emplace_back();
		region.m_Region.m_components.back().m_holes.back().SetBoundary(vertices);
		
		vertices.clear();
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.981965, -93.291486)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.981958, -93.292436)));
		vertices.emplace_back(LatLonToNM(PI/180.0*Eigen::Vector2d(44.982602, -93.291921)));
		region.m_Region.m_components.emplace_back();
		region.m_Region.m_components.back().m_boundary.SetBoundary(vertices);
		
		//On destruction, region should be saved to disk automatically
	}
	
	return true;
}

static bool TestBench6(std::string const & Arg) {
	//First test bench for guidance module - setup test case and call EstimateMissionTime() for mission time flying between two points
	DroneInterface::Waypoint A;
	DroneInterface::Waypoint B;
	double TargetSpeed = 15.0; //Max mission speed for DJI drones being controlled through SDK (m/s)
	
	//First point about 100 feet above the ground in Lamberton test area
	A.Latitude  =  0.772121618310453;
	A.Longitude = -1.663470726988503;
	A.Altitude  = 380.0;
	
	//Second point about 100 feet above the ground in Lamberton test area
	B.Latitude  =  0.772065994667192;
	B.Longitude = -1.663426622518305;
	B.Altitude  = 380.0;
	
	double time = Guidance::EstimateMissionTime(A, B, TargetSpeed);
	std::cerr << "Estimated flight fime from point A to point B (stopped at beginning and end) is: " << time << " seconds.\r\n";
	
	return false; //Ideally check result somehow and return true on success and false on failure (otherwise manually verify result somehow)
}

static bool TestBench7(std::string const & Arg)  { return false; }
static bool TestBench8(std::string const & Arg)  { return false; }
static bool TestBench9(std::string const & Arg)  { return false; }
static bool TestBench10(std::string const & Arg) { return false; }

static std::filesystem::path SimDatasetStringArgToDatasetPath(std::string const & Arg) {
	int datasetNum = 0;
	if ((Arg.empty()) || (! str2int(Arg, datasetNum)) || (datasetNum < 0))
		std::cerr << "No Argument or invalid argument (" << Arg << ") provided to testbench... using first sim dataset (lexicographically).\r\n";
	std::vector<std::filesystem::path> subDirs = Handy::SubDirectories(Handy::Paths::ThisExecutableDirectory().parent_path() / "Simulation-Data-Sets"s);
	std::sort(subDirs.begin(), subDirs.end(), [](std::string const & A, std::string const & B) -> bool { return StringNumberAwareCompare_LessThan(A, B); });
	if (datasetNum >= int(subDirs.size())) {
		std::cerr << "Aborting test bench - dataset not found.\r\n";
		return std::filesystem::path();
	}
	return subDirs[datasetNum];
}

static cv::Mat GetRefFrame(std::filesystem::path const & DatasetPath) {
	std::filesystem::path refFramePath = DatasetPath / "RefFrame.jpeg"s;
	if (! std::filesystem::exists(refFramePath))
		return cv::Mat();
	
	cv::Mat frame = cv::imread(refFramePath.string(), cv::IMREAD_COLOR);
	if (DroneInterface::SimulatedDrone::Resize_4K_to_720p(frame))
		return frame;
	else
		return cv::Mat();
}

//Return the path of the first .MOV file in the given folder (lexicographically)
static std::filesystem::path GetSimVideoFilePath(std::filesystem::path const & DatasetPath) {
	std::vector<std::filesystem::path> files = GetNormalFilesInDirectory(DatasetPath);
	std::sort(files.begin(), files.end(), [](std::string const & A, std::string const & B) -> bool { return StringNumberAwareCompare_LessThan(A, B); });
	for (auto const & file : files) {
		std::string ext = file.extension().string();
		if ((ext == ".mov"s) || (ext == ".MOV") || (ext == ".Mov"))
			return file;
	}
	return std::filesystem::path();
}

//Load GCPs from the file GCP.txt in the given folder - we also adjust them from file native res (4K) to 720p
//Returned fiducials are in form needed by Shadow Detection Engine.
static std::Evector<std::tuple<Eigen::Vector2d, Eigen::Vector3d>> LoadFiducialsFromFile(std::filesystem::path const & DatasetPath) {
	std::filesystem::path GCPsFilePath = DatasetPath / "GCPs.txt"s;
	std::Evector<std::tuple<Eigen::Vector2d, Eigen::Vector3d>> GCPs;
	if (! std::filesystem::exists(GCPsFilePath))
		return GCPs;
	
	std::ifstream file;
	file.open(GCPsFilePath.string().c_str());
	if (! file.good())
		return GCPs;
	
	std::string line;
	char character;
	size_t index;
	while (!file.eof()) {
		std::getline(file, line);
		index = line.find_first_not_of(" \t"s);
		if (index != std::string::npos) {
			//Line is non-empty. Check if it is a comment line
			character = line.at(index);
			if (character != '#') {
				//Line is non-empty and not a comment line
				line = line.substr(index);
				std::vector<std::string> parts = StringSplit(line, ","s);
				if (parts.size() != 6U)
					std::cerr << "Warning in LoadFiducials(): Dropping invalid line.\r\n";
				else {
					StringStrip(parts[5], " \t\r\n"); //Make sure newline or space chars don't mess us up at end of line
					double col, row, latDeg, lonDeg, altM;
					if (str2double(parts[1], col) && str2double(parts[2], row) && 
					    str2double(parts[3], latDeg) && str2double(parts[4], lonDeg) && str2double(parts[5], altM)) {
						Eigen::Vector2d PixCoords(col/3.0, row/3.0); //Convert 4K to 720p
						Eigen::Vector3d LLA(latDeg*PI/180.0, lonDeg*PI/180.0, altM); //Convert degrees to radians
						GCPs.push_back(std::make_tuple(PixCoords, LLA));
					}
					else
						std::cerr << "Warning: Dropping invalid GCP from file. Line: " << line << "\r\n";
				}
			}
		}
	}
	return GCPs;
}

//Shadow Detection: Non-realtime simulation
static bool TestBench11(std::string const & Arg) {
	//Parse argument and load dataset
	std::filesystem::path datasetPath = SimDatasetStringArgToDatasetPath(Arg);
	std::cerr << "Simulation dataset path: " << datasetPath.string() << "\r\n";
	cv::Mat refFrame = GetRefFrame(datasetPath);
	std::filesystem::path sourceVideoPath = GetSimVideoFilePath(datasetPath);
	std::Evector<std::tuple<Eigen::Vector2d, Eigen::Vector3d>> GCPs = LoadFiducialsFromFile(datasetPath);
	
	//Set up drone sim
	DroneInterface::Drone * myDrone = DroneInterface::DroneManager::Instance().GetDrone("Simulation"s);
	if (myDrone == nullptr) {
		std::cerr << "Error: Unable to get simulated drone from drone manager.\r\n";
		return false;
	}
	DroneInterface::SimulatedDrone * mySimDrone = dynamic_cast<DroneInterface::SimulatedDrone *>(myDrone);
	if (mySimDrone == nullptr) {
		std::cerr << "Error: Could not down-cast Drone to SimulatedDrone.\r\n";
		return false;
	}
	mySimDrone->SetRealTime(false);
	mySimDrone->SetSourceVideoFile(sourceVideoPath);
	
	//Set reference frame and fiducials in shadow detection module
	ShadowDetection::ShadowDetectionEngine::Instance().SetReferenceFrame(refFrame);
	ShadowDetection::ShadowDetectionEngine::Instance().SetFiducials(GCPs);
	
	//Register callback with the shadow detection engine for monitoring its output (if desired)
	bool showLiveOutput = true;
	if (showLiveOutput) {
		ShadowDetection::ShadowDetectionEngine::Instance().RegisterCallback([](ShadowDetection::InstantaneousShadowMap const & ShadowMap) {
			auto duration = ShadowMap.Timestamp.time_since_epoch();
			double secondsSinceEpoch = double(duration.count()) * double(std::chrono::system_clock::period::num) / double(std::chrono::system_clock::period::den);
			std::cerr << "Shadow map received. Timestamp: " << secondsSinceEpoch << "\r\n";
			cv::imshow("Live Shadow Map", ShadowMap.Map);
			cv::waitKey(1);
		});
	}
	
	//Start the shadow detection engine, using imagery from the sim drone
	ShadowDetection::ShadowDetectionEngine::Instance().Start("Simulation"s);
	
	//Start the sim drone video feed
	myDrone->StartDJICamImageFeed(1.0);
	
	//wait until video feed is done
	while (myDrone->IsCamImageFeedOn())
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	//Stop the shadow detection engine and instruct it to save it's shadow map history
	ShadowDetection::ShadowDetectionEngine::Instance().Stop();
	ShadowDetection::ShadowDetectionEngine::Instance().SaveAndFlushShadowMapHistory();
	std::cerr << "Shadow map history saved to FRF files. Look in 'Shadow Map Files' folder in BIN directory.\r\n";
	
	return true;
}

//Shadow Detection: Realtime simulation
static bool TestBench12(std::string const & Arg) {
	//Parse argument and load dataset
	std::filesystem::path datasetPath = SimDatasetStringArgToDatasetPath(Arg);
	std::cerr << "Simulation dataset path: " << datasetPath.string() << "\r\n";
	cv::Mat refFrame = GetRefFrame(datasetPath);
	std::filesystem::path sourceVideoPath = GetSimVideoFilePath(datasetPath);
	std::Evector<std::tuple<Eigen::Vector2d, Eigen::Vector3d>> GCPs = LoadFiducialsFromFile(datasetPath);
	
	//Set up drone sim
	DroneInterface::Drone * myDrone = DroneInterface::DroneManager::Instance().GetDrone("Simulation"s);
	if (myDrone == nullptr) {
		std::cerr << "Error: Unable to get simulated drone from drone manager.\r\n";
		return false;
	}
	DroneInterface::SimulatedDrone * mySimDrone = dynamic_cast<DroneInterface::SimulatedDrone *>(myDrone);
	if (mySimDrone == nullptr) {
		std::cerr << "Error: Could not down-cast Drone to SimulatedDrone.\r\n";
		return false;
	}
	mySimDrone->SetRealTime(true);
	mySimDrone->SetSourceVideoFile(sourceVideoPath);
	
	//Set reference frame and fiducials in shadow detection module
	ShadowDetection::ShadowDetectionEngine::Instance().SetReferenceFrame(refFrame);
	ShadowDetection::ShadowDetectionEngine::Instance().SetFiducials(GCPs);
	
	//Register callback with the shadow detection engine for monitoring its output (if desired)
	bool showLiveOutput = true;
	if (showLiveOutput) {
		ShadowDetection::ShadowDetectionEngine::Instance().RegisterCallback([](ShadowDetection::InstantaneousShadowMap const & ShadowMap) {
			auto duration = ShadowMap.Timestamp.time_since_epoch();
			double secondsSinceEpoch = double(duration.count()) * double(std::chrono::system_clock::period::num) / double(std::chrono::system_clock::period::den);
			std::cerr << "Shadow map received. Timestamp: " << secondsSinceEpoch << "\r\n";
			cv::imshow("Live Shadow Map", ShadowMap.Map);
			cv::waitKey(1);
		});
	}
	
	//Start the shadow detection engine, using imagery from the sim drone
	ShadowDetection::ShadowDetectionEngine::Instance().Start("Simulation"s);
	
	//Start the sim drone video feed
	myDrone->StartDJICamImageFeed(1.0);
	
	//wait until video feed is done
	while (myDrone->IsCamImageFeedOn())
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	//Stop the shadow detection engine and instruct it to save it's shadow map history
	ShadowDetection::ShadowDetectionEngine::Instance().Stop();
	ShadowDetection::ShadowDetectionEngine::Instance().SaveAndFlushShadowMapHistory();
	std::cerr << "Shadow map history saved to FRF files. Look in 'Shadow Map Files' folder in BIN directory.\r\n";
	
	return true;
}

static bool TestBench13(std::string const & Arg) { return false; }
static bool TestBench14(std::string const & Arg) { return false; }
static bool TestBench15(std::string const & Arg) { return false; }
static bool TestBench16(std::string const & Arg) { return false; }
static bool TestBench17(std::string const & Arg) { return false; }
static bool TestBench18(std::string const & Arg) { return false; }
static bool TestBench19(std::string const & Arg) { return false; }
static bool TestBench20(std::string const & Arg) { return false; }

//DJI Drone Interface: Simulated Drone Imagery. This test bench sets up the simulated drone for non-realtime operation and just displays video
static bool TestBench21(std::string const & Arg) {
	//Parse argument and load dataset
	std::filesystem::path datasetPath = SimDatasetStringArgToDatasetPath(Arg);
	std::cerr << "Simulation dataset path: " << datasetPath.string() << "\r\n";
	std::filesystem::path sourceVideoPath = GetSimVideoFilePath(datasetPath);
	
	DroneInterface::Drone * myDrone = DroneInterface::DroneManager::Instance().GetDrone("Simulation"s);
	if (myDrone == nullptr) {
		std::cerr << "Error: Unable to get simulated drone from drone manager.\r\n";
		return false;
	}
	DroneInterface::SimulatedDrone * mySimDrone = dynamic_cast<DroneInterface::SimulatedDrone *>(myDrone);
	if (mySimDrone == nullptr) {
		std::cerr << "Error: Could not down-cast Drone to SimulatedDrone.\r\n";
		return false;
	}
	mySimDrone->SetRealTime(false);
	mySimDrone->SetSourceVideoFile(sourceVideoPath);
	
	//Register a callback with the drone for imagery
	myDrone->RegisterCallback([](cv::Mat const & Frame, DroneInterface::Drone::TimePoint const & Timestamp) {
		auto duration = Timestamp.time_since_epoch();
		double secondsSinceEpoch = double(duration.count()) * double(std::chrono::system_clock::period::num) / double(std::chrono::system_clock::period::den);
		std::cerr << "Image received. Timestamp: " << secondsSinceEpoch << "\r\n";
		cv::imshow("Sim Drone Imagery", Frame);
		cv::waitKey(1);
	});
	
	//Start video feed
	myDrone->StartDJICamImageFeed(1.0);
	
	//wait until video feed is done
	while (myDrone->IsCamImageFeedOn())
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	return true;
}

//DJI Drone Interface: Simulated Drone Imagery. This test bench sets up the simulated drone for realtime operation and just displays video
static bool TestBench22(std::string const & Arg) {
	//Parse argument and load dataset
	std::filesystem::path datasetPath = SimDatasetStringArgToDatasetPath(Arg);
	std::cerr << "Simulation dataset path: " << datasetPath.string() << "\r\n";
	std::filesystem::path sourceVideoPath = GetSimVideoFilePath(datasetPath);
	
	DroneInterface::Drone * myDrone = DroneInterface::DroneManager::Instance().GetDrone("Simulation"s);
	if (myDrone == nullptr) {
		std::cerr << "Error: Unable to get simulated drone from drone manager.\r\n";
		return false;
	}
	DroneInterface::SimulatedDrone * mySimDrone = dynamic_cast<DroneInterface::SimulatedDrone *>(myDrone);
	if (mySimDrone == nullptr) {
		std::cerr << "Error: Could not down-cast Drone to SimulatedDrone.\r\n";
		return false;
	}
	mySimDrone->SetRealTime(true);
	mySimDrone->SetSourceVideoFile(sourceVideoPath);
	
	//Register a callback with the drone for imagery
	myDrone->RegisterCallback([](cv::Mat const & Frame, DroneInterface::Drone::TimePoint const & Timestamp) {
		auto duration = Timestamp.time_since_epoch();
		double secondsSinceEpoch = double(duration.count()) * double(std::chrono::system_clock::period::num) / double(std::chrono::system_clock::period::den);
		std::cerr << "Image received. Timestamp: " << secondsSinceEpoch << "\r\n";
		cv::imshow("Sim Drone Imagery", Frame);
		cv::waitKey(1);
	});
	
	//Start video feed
	myDrone->StartDJICamImageFeed(1.0);
	
	//wait until video feed is done
	while (myDrone->IsCamImageFeedOn())
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	return true;
}

//DJI Drone Interface: Serialization/Deserialization
static bool TestBench23(std::string const & Arg) {
	DroneInterface::Packet myPacket;
	
	{
		std::cerr << "Testing Core Telemetry Packet... ... ... ... . ";
		DroneInterface::Packet_CoreTelemetry coreTelemetryA;
		DroneInterface::Packet_CoreTelemetry coreTelemetryB;
		coreTelemetryA.IsFlying  = 1U;         //Flying
		coreTelemetryA.Latitude  = 44.237246;  //Degrees
		coreTelemetryA.Longitude = -95.305901; //Degrees
		coreTelemetryA.Altitude  = 445.0;      //meters
		coreTelemetryA.HAG       = 100.0f;     //meters
		coreTelemetryA.V_N       = 2.00f;      //m/s
		coreTelemetryA.V_E       = 0.01f;      //m/s
		coreTelemetryA.V_D       = -0.04f;     //m/s
		coreTelemetryA.Yaw       = 0.0f;       //Degrees
		coreTelemetryA.Pitch     = -5.1f;      //Degrees
		coreTelemetryA.Roll      = 0.01f;      //Degrees
		coreTelemetryA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		coreTelemetryB.Deserialize(myPacket);
		if (coreTelemetryA == coreTelemetryB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << coreTelemetryA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << coreTelemetryB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Extended Telemetry Packet... ... ... . ";
		DroneInterface::Packet_ExtendedTelemetry extendedTelemetryA;
		DroneInterface::Packet_ExtendedTelemetry extendedTelemetryB;
		extendedTelemetryA.GNSSSatCount = 13U;
		extendedTelemetryA.GNSSSignal   = 5U;
		extendedTelemetryA.MaxHeight    = 0U;
		extendedTelemetryA.MaxDist      = 1U;
		extendedTelemetryA.BatLevel     = 73U;
		extendedTelemetryA.BatWarning   = 0U;
		extendedTelemetryA.WindLevel    = 1U;
		extendedTelemetryA.DJICam       = 1U;
		extendedTelemetryA.FlightMode   = 10U;
		extendedTelemetryA.MissionID    = 17U;
		extendedTelemetryA.DroneSerial  = "S856772896"s;
		extendedTelemetryA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		extendedTelemetryB.Deserialize(myPacket);
		if (extendedTelemetryA == extendedTelemetryB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << extendedTelemetryA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << extendedTelemetryB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Image Packet... ... ... ... ... ... .. ";
		DroneInterface::Packet_Image PacketA;
		DroneInterface::Packet_Image PacketB;
		PacketA.TargetFPS = 1.2f; //s
		PacketA.Frame = cv::Mat(720, 1280, CV_8UC3);
		cv::Vec3b & pix(PacketA.Frame.at<cv::Vec3b>(7, 45));
		pix(0) = 71U;
		pix(1) = 13U;
		pix(2) = 207U;
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		if (PacketA == PacketB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Acknowledgment Packet... ... ... ... . ";
		DroneInterface::Packet_Acknowledgment PacketA;
		DroneInterface::Packet_Acknowledgment PacketB;
		PacketA.Positive  = 1U;
		PacketA.SourcePID = 253U;
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		if (PacketA == PacketB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Message String Packet... ... ... ... . ";
		DroneInterface::Packet_MessageString PacketA;
		DroneInterface::Packet_MessageString PacketB;
		PacketA.Type    = 0U;
		PacketA.Message = "This is a debug message! Debugging is going great!"s;
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		if (PacketA == PacketB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Emergency Command Packet... ... ... .. ";
		DroneInterface::Packet_EmergencyCommand PacketA;
		DroneInterface::Packet_EmergencyCommand PacketB;
		PacketA.Action = 2U; //RTL
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		if (PacketA == PacketB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Camera Control Packet... ... ... ... . ";
		DroneInterface::Packet_CameraControl PacketA;
		DroneInterface::Packet_CameraControl PacketB;
		PacketA.Action    = 1U;
		PacketA.TargetFPS = 1.5f;
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		if (PacketA == PacketB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Execute Waypoint Mission Packet... ... ";
		DroneInterface::Packet_ExecuteWaypointMission PacketA;
		DroneInterface::Packet_ExecuteWaypointMission PacketB;
		PacketA.LandAtEnd = 0U;
		PacketA.CurvedFlight = 0U;
		PacketA.Waypoints.clear();
		PacketA.Waypoints.emplace_back();
		PacketA.Waypoints.back().Latitude     = 0.772121618310453;  //Radians
		PacketA.Waypoints.back().Longitude    = -1.663470726988503; //Radians
		PacketA.Waypoints.back().Altitude     = 380.0;              //m
		PacketA.Waypoints.back().CornerRadius = 5.0f;               //m
		PacketA.Waypoints.back().Speed        = 8.1f;               //m/s
		PacketA.Waypoints.back().LoiterTime   = std::nanf("");      //Don't loiter
		PacketA.Waypoints.back().GimbalPitch  = std::nanf("");      //Don't control gimbal
		
		PacketA.Waypoints.emplace_back();
		PacketA.Waypoints.back().Latitude     = 0.772121618310453;  //Radians
		PacketA.Waypoints.back().Longitude    = -1.663470726988503; //Radians
		PacketA.Waypoints.back().Altitude     = 401.3;              //m
		PacketA.Waypoints.back().CornerRadius = 4.1f;               //m
		PacketA.Waypoints.back().Speed        = 7.6f;               //m/s
		PacketA.Waypoints.back().LoiterTime   = std::nanf("");      //Don't loiter
		PacketA.Waypoints.back().GimbalPitch  = std::nanf("");      //Don't control gimbal
		
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		//Because serialization and deserialization involve degree <-> radian conversion true equality test will generally fail.
		bool essentiallyEqual = true;
		if ((PacketA.LandAtEnd != PacketB.LandAtEnd) || (PacketA.CurvedFlight != PacketB.CurvedFlight))
			essentiallyEqual = false;
		else if (PacketA.Waypoints.size() != PacketB.Waypoints.size())
			essentiallyEqual = false;
		else {
			for (size_t n = 0U; n < PacketA.Waypoints.size(); n++) {
				DroneInterface::Waypoint const & A(PacketA.Waypoints[n]);
				DroneInterface::Waypoint const & B(PacketB.Waypoints[n]);
				bool LoiterTimesMatch   = (std::isnan(A.LoiterTime)  && std::isnan(B.LoiterTime))  || (A.LoiterTime  == B.LoiterTime);
				bool GimbalPitchesMatch = (std::isnan(A.GimbalPitch) && std::isnan(B.GimbalPitch)) || (std::fabs(A.GimbalPitch - B.GimbalPitch) <= 1e-10);
				if ((std::fabs(A.Latitude  - B.Latitude)  > 1e-10) ||
				    (std::fabs(A.Longitude - B.Longitude) > 1e-10) ||
				    (A.Altitude     != B.Altitude)                 ||
				    (A.CornerRadius != B.CornerRadius)             ||
				    (A.Speed        != B.Speed)                    ||
				    (! LoiterTimesMatch)                           ||
				    (! GimbalPitchesMatch))
				{
					essentiallyEqual = false;
					break;
				}
				
			}
		}
		if (essentiallyEqual)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << ".\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	{
		std::cerr << "Testing Virtual Stick Command Packet... ... .. ";
		DroneInterface::Packet_VirtualStickCommand PacketA;
		DroneInterface::Packet_VirtualStickCommand PacketB;
		PacketA.Mode    = 0U;    //Mode A (V_x is V_North, and V_y is V_East)
		PacketA.Yaw     = 31.0f; //degrees, relative to true north (positive yaw is clockwise rotation)
		PacketA.V_x     = 1.2f;  //m/s
		PacketA.V_y     = -0.7f; //m/s
		PacketA.HAG     = 39.5f; //m
		PacketA.timeout = 5.0f;  //s
		PacketA.Serialize(myPacket);
		if (! myPacket.IsFinished()) {
			std::cerr << "Packet Completion Test Failed.\r\n";
			return false;
		}
		PacketB.Deserialize(myPacket);
		if (PacketA == PacketB)
			std::cerr << "Equality Test Passed.\r\n";
		else {
			std::cerr << "Equality Test Failed.\r\n";
			std::cerr << "Original Object:\r\n" << PacketA << "\r\n";
			std::cerr << "Deserialized Object:\r\n" << PacketB << "\r\n";
			return false;
		}
	}
	
	return true;
}


static bool TestBench24(std::string const & Arg) { return false; }
static bool TestBench25(std::string const & Arg) { return false; }


static bool TestBench26(std::string const & Arg) {
	torch::Tensor tensor = torch::rand({2, 3});
	std::cerr << tensor << std::endl;
	
	return true;
}




