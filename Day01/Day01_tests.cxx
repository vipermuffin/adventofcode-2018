//
//  Advent of Code 2018 Tests: Day 1
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 11/30/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay01{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay01;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("502", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("71961", solveb());
}
