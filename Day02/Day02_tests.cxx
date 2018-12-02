//
//  Advent of Code 2018 Tests: Day 2
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/01/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay02{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay02;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("5704", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("umdryabviapkozistwcnihjqx", solveb());
}

TEST(Example,Test1) {
    vector<string> x{
        "abcdef",
        "bababc",
        "abbcde",
        "abcccd",
        "aabcdd",
        "abcdee",
        "ababab"
    };
	EXPECT_EQ(12,calculateChecksum(x));
}

TEST(Example,Test2) {
    vector<string> x{
        "abcde",
        "fghij",
        "klmno",
        "pqrst",
        "fguij",
        "axcye",
        "wvxyz"
    };
	EXPECT_EQ("fgij",findProtoBox(x));
}
