//
//  Advent of Code 2018 Tests: Day 11
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/10/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay11{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("22,18", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("---", solveb());
}

TEST(Example,Test1) {
	auto x = calcPowerLevel(3, 5, 8);
	EXPECT_EQ(4,x);
}

TEST(Example,Test2) {
	auto x = calcPowerLevel(122, 79, 57);
	EXPECT_EQ(-5,x);
}

TEST(Example,Test3) {
	auto x = calcPowerLevel(217, 196, 39);
	EXPECT_EQ(0,x);
}

TEST(Example,Test4) {
    auto x = calcPowerLevel(101, 153, 71);
    EXPECT_EQ(4,x);
}

TEST(Example,Test5) {
    auto x = findTopLeft(18);
    EXPECT_EQ("33,45",x);
}

TEST(Example,Test6) {
    auto x = findTopLeft(42);
    EXPECT_EQ("21,61",x);
}
