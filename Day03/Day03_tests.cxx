//
//  Advent of Code 2018 Tests: Day 3
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/02/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay03{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay03;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("103806", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("625", solveb());
}

TEST(Example,Test1) {
	int x = 0;
	EXPECT_EQ(0,x);
}

TEST(Example,Test2) {
	int x = 0;
	EXPECT_EQ(0,x);
}

TEST(Example,Test3) {
	int x = 0;
	EXPECT_EQ(0,x);
}
