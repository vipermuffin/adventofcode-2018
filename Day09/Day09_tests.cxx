//
//  Advent of Code 2018 Tests: Day 9
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/09/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("429943", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("3615691746", solveb());
}

TEST(Example,Test1) {
	int x = playGame(10, 1618);
	EXPECT_EQ(8317,x);
}

TEST(Example,Test2) {
    int x = playGame(13, 7999);
    EXPECT_EQ(146373,x);
}

TEST(Example,Test3) {
    int x = playGame(17, 1104);
    EXPECT_EQ(2764,x);
}

TEST(Example,Test4) {
    int x = playGame(21, 6111);
    EXPECT_EQ(54718,x);
}

TEST(Example,Test5) {
    int x = playGame(30, 5807);
    EXPECT_EQ(37305,x);
}
