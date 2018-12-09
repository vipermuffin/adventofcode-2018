//
//  Advent of Code 2018 Tests: Day 7
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/06/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay07{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay07;

TEST(SolvePartA, FinalSolution) {
    EXPECT_EQ("BGKDMJCNEQRSTUZWHYLPAFIVXO", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("941", solveb());
}

TEST(Example,Test1) {
    vector<string> i {
        "Step C must be finished before step A can begin.",
        "Step C must be finished before step F can begin.",
        "Step A must be finished before step B can begin.",
        "Step A must be finished before step D can begin.",
        "Step B must be finished before step E can begin.",
        "Step D must be finished before step E can begin.",
        "Step F must be finished before step E can begin."
    };
    auto x = determineOrder(i);
    EXPECT_EQ("CABDFE",x);
}

TEST(Example,Test2) {
    vector<string> i {
        "Step C must be finished before step A can begin.",
        "Step C must be finished before step F can begin.",
        "Step F must be finished before step B can begin.",
        "Step A must be finished before step D can begin.",
        "Step B must be finished before step E can begin.",
        "Step D must be finished before step E can begin.",
        "Step F must be finished before step E can begin."
    };
    auto x = determineOrder(i);
    EXPECT_EQ("CADFBE",x);
}

TEST(Example,Test3) {
    vector<string> i {
        "Step C must be finished before step A can begin.",
        "Step C must be finished before step F can begin.",
        "Step A must be finished before step B can begin.",
        "Step A must be finished before step D can begin.",
        "Step B must be finished before step E can begin.",
        "Step D must be finished before step E can begin.",
        "Step F must be finished before step E can begin."
    };
    auto x = determineOrder2(i,2,0);
	EXPECT_EQ(15,x);
}
