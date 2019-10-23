//
//  Advent of Code 2018 Tests: Day 21
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/21/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay21{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay21;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("11513432", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("7434231", solveb());
}
