//
//  Advent of Code 2018 Tests: Day 4
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/03/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay04{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay04;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("19874", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("22687", solveb());
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
