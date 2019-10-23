//
//  Advent of Code 2018 Tests: Day 23
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/22/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay23{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay23;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("889", solvea());
}

TEST(SolvePartB, FinalSolution) {
    EXPECT_EQ("160646364", solveb());
}

TEST(Example,Test1) {
    vector<string> in {
        "pos=<10,12,12>, r=2",
        "pos=<12,14,12>, r=2",
        "pos=<16,12,12>, r=4",
        "pos=<14,14,14>, r=6",
        "pos=<50,50,50>, r=200",
        "pos=<10,10,10>, r=5"
    };
	EXPECT_EQ("36",performB(in));
}

TEST(Example,Test2) {
    vector<string> in {
        "pos=<10,12,12>, r=2",
        "pos=<12,14,12>, r=2",
        "pos=<16,12,12>, r=4",
        "pos=<14,14,14>, r=6",
        "pos=<50,50,50>, r=200",
        "pos=<10,10,10>, r=5"
    };
    EXPECT_EQ("36",performB2(in));
}

TEST(Example,Test3) {
    vector<string> in {
        "pos=<10,12,12>, r=2",
        "pos=<12,14,12>, r=2",
        "pos=<16,12,12>, r=4",
        "pos=<14,14,14>, r=6",
        "pos=<50,50,50>, r=200",
        "pos=<10,10,10>, r=5"
    };
    EXPECT_EQ("36",performB3(in));
}
