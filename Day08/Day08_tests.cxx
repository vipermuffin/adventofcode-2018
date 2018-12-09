//
//  Advent of Code 2018 Tests: Day 8
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/07/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay08{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay08;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("42798", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("23798", solveb());
}

TEST(Example,Test1) {
    vector<int> y{2, 3, 0, 3, 10, 11, 12, 1, 1, 0, 1, 99, 2, 1, 1, 2};
    auto yItr = y.begin();
	int x = sumAllMetadata(yItr, y.end());
	EXPECT_EQ(138,x);
}

TEST(Example,Test2) {
    vector<int> y{2, 3, 0, 3, 10, 11, 12, 1, 1, 0, 1, 99, 2, 1, 1, 2};
    auto yItr = y.begin();
    int x = valueOfRootNode(yItr, y.end());
    EXPECT_EQ(66,x);
}

