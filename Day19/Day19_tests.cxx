//
//  Advent of Code 2018 Tests: Day 19
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day19.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay19{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay19;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("2520", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("27941760", solveb());
}

