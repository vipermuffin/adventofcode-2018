//
//  Advent of Code 2018 Tests: Day 6
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/05/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(SolvePartA, FinalSolution) {
    EXPECT_EQ("3010", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("48034", solveb());
}

TEST(Example,Test1) {
    vector<string> x {
        "1, 1",
        "1, 6",
        "8, 3",
        "3, 4",
        "5, 5",
        "8, 9"
    };
	EXPECT_EQ(17,findMaxFiniteArea(x));
}

TEST(Example,Test2) {
    vector<string> x {
        "1, 1",
        "1, 6",
        "8, 3",
        "3, 4",
        "5, 5",
        "8, 9"
    };
    EXPECT_EQ(16,findSizeOfAreaLessThan(x,32));
}

TEST(Example,Test3) {
	int x = 0;
	EXPECT_EQ(0,x);
}
