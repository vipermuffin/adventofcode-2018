//
//  Advent of Code 2018 Tests: Day 18
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/18/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay18{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay18;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("621205", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("228490", solveb());
}

TEST(Example,Test1) {
    vector<string> acre {
        ".#.#...|#.",
        ".....#|##|",
        ".|..|...#.",
        "..|#.....#",
        "#.#|||#|#|",
        "...#.||...",
        ".|....|...",
        "||...#|.#|",
        "|.||||..|.",
        "...#.|..|."
    };
	auto x = CountWoodsAndLumber(acre);
	EXPECT_EQ(27,x.first);
    EXPECT_EQ(17,x.second);
}

TEST(Example,Test2) {
    vector<string> acre {
        ".#.#...|#.",
        ".....#|##|",
        ".|..|...#.",
        "..|#.....#",
        "#.#|||#|#|",
        "...#.||...",
        ".|....|...",
        "||...#|.#|",
        "|.||||..|.",
        "...#.|..|."
    };
    vector<string> expected {
        ".......##.",
        "......|###",
        ".|..|...#.",
        "..|#||...#",
        "..##||.|#|",
        "...#||||..",
        "||...|||..",
        "|||||.||.|",
        "||||||||||",
        "....||..|."
    };
    RunTimeStep(acre);
    for(int i = 0;i < acre.size(); ++i) {
        EXPECT_EQ(expected[i],acre[i]);
    }
}


TEST(Example,Test3) {
    vector<string> acre {
        ".#.#...|#.",
        ".....#|##|",
        ".|..|...#.",
        "..|#.....#",
        "#.#|||#|#|",
        "...#.||...",
        ".|....|...",
        "||...#|.#|",
        "|.||||..|.",
        "...#.|..|."
    };
    for(int i = 0; i < 10; ++i) {
        RunTimeStep(acre);
    }
    auto x = CountWoodsAndLumber(acre);
	EXPECT_EQ(37,x.first);
    EXPECT_EQ(31,x.second);
}
