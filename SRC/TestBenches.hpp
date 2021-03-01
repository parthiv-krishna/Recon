//This module provides test benches that can be invoked through a command-line switch
//Author: Bryan Poling
//Copyright (c) 2021 Sentek Systems, LLC. All rights reserved. 
#pragma once

//System Includes
#include <tuple>
#include <string>
#include <vector>

namespace TestBenches {
	inline std::vector<std::string> AvailableTestBenches = {
		"Geometry: Break line segments at intersections",
		"Geometry: Simple Polygon Sanitize - Outline Trace",
		"Geometry: Simple Polygon intersection fragmentation",
		"Geometry: Polygon Triangulation",
		"Survey Regions: Serialization",
		"Survey Regions: Create Sample Minneapolis Region"
	};
	
	void RunTestBench(int TestNum);
}
