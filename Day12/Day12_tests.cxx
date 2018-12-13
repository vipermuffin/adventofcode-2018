//
//  Advent of Code 2018 Tests: Day 12
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/11/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <unordered_map>

namespace AocDay12{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay12;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("2281", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("2250000000120", solveb());
}

TEST(Example,Test1) {
    unordered_map<string, char> dict {
        {"...##",'#'},
        {"..#..",'#'},
        {".#...",'#'},
        {".#.#.",'#'},
        {".#.##",'#'},
        {".##..",'#'},
        {".####",'#'},
        {"#.#.#",'#'},
        {"#.###",'#'},
        {"##.#.",'#'},
        {"##.##",'#'},
        {"###..",'#'},
        {"###.#",'#'},
        {"####.",'#'}
    };
    long i{0};
    string s{"#..#.#..##......###...###"};
	auto x = performGeneration(dict, s,&i);
	EXPECT_EQ("#...#....#.....#..#..#..#",x);
    EXPECT_EQ(0,i);
    x = performGeneration(dict, x,&i);
    EXPECT_EQ("##..##...##....#..#..#..##",x);
    x = performGeneration(dict, x,&i);
    EXPECT_EQ("#.#...#..#.#....#..#..#...#",x);
    EXPECT_EQ(-1,i);
}

TEST(Example,Test2) {
    string s{"..#...#....#.....#..#..#..#.."};
    int x = countPlants(s);
	EXPECT_EQ(7,x);
}

TEST(Example,Test3) {
    string plants {".#....##....#####...#######....#.#..##."};
    int x = sumPlantNumbers(plants,-3);
	EXPECT_EQ(325,x);
}
