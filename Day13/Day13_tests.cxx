//
//  Advent of Code 2018 Tests: Day 13
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/13/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay13{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay13;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("129,50", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("69,73", solveb());
}

TEST(Example,Test1) {
    vector<string> paths {
        "/->-\\        ",
        "|   |  /----\\",
        "| /-+--+-\\  |",
        "| | |  | v  |",
        "\\-+-/  \\-+--/",
        "\\------/     "
    };
    vector<Cart> carts{};
    findCarts(paths, carts);
	ASSERT_EQ(2,carts.size());
    EXPECT_EQ("/---\\        ", paths[0]);
    EXPECT_EQ("| /-+--+-\\  |", paths[2]);
    EXPECT_EQ("| | |  | |  |", paths[3]);
    EXPECT_EQ(2, carts[0].x);
    EXPECT_EQ(0, carts[0].y);
    EXPECT_EQ(3, carts[1].y);
    EXPECT_EQ(9, carts[1].x);
}

TEST(Example,Test2) {
    vector<string> paths {
        "/->-\\        ",
        "|   |  /----\\",
        "| /-+--+-\\  |",
        "| | |  | v  |",
        "\\-+-/  \\-+--/",
        "\\------/     "
    };
    vector<Cart> carts{};
    findCarts(paths, carts);
    stepCarts(paths, carts);
    EXPECT_EQ(3, carts[0].x);
    EXPECT_EQ(0, carts[0].y);
    EXPECT_EQ(4, carts[1].y);
    EXPECT_EQ(9, carts[1].x);
    stepCarts(paths, carts);
    EXPECT_EQ(4, carts[0].x);
    EXPECT_EQ(0, carts[0].y);
    EXPECT_EQ(4, carts[1].y);
    EXPECT_EQ(10, carts[1].x);
    stepCarts(paths, carts);
    EXPECT_EQ(4, carts[0].x);
    EXPECT_EQ(1, carts[0].y);
    EXPECT_EQ(4, carts[1].y);
    EXPECT_EQ(11, carts[1].x);
}

TEST(Example,Test3) {
    vector<string> paths {
        "/->-\\        ",
        "|   |  /----\\",
        "| /-+--+-\\  |",
        "| | |  | v  |",
        "\\-+-/  \\-+--/",
        "\\------/     "
    };
    vector<Cart> carts{};
    findCarts(paths, carts);
    while(!stepCarts(paths, carts)) {
//        cout << "Cart 0: <" << carts[0].x << "," << carts[0].y << ">" << endl;
//        cout << "Cart 1: <" << carts[1].x << "," << carts[1].y << ">" << endl;
    }
    EXPECT_EQ(7, carts[0].x);
    EXPECT_EQ(3, carts[0].y);
    EXPECT_EQ(true, carts[0].isCrashed);
    EXPECT_EQ(3, carts[1].y);
    EXPECT_EQ(7, carts[1].x);
    EXPECT_EQ(true, carts[1].isCrashed);
}

TEST(Example,Test4) {
    vector<string> paths {
        "/>-<\\  ",
        "|   |  ",
        "| /<+-\\",
        "| | | v",
        "\\>+</ |",
        "  |   ^",
        "  \\<->/"
    };
    vector<Cart> carts{};
    findCarts(paths, carts);
    while(!stepCarts(paths, carts, true)) {
        //        cout << "Cart 0: <" << carts[0].x << "," << carts[0].y << ">" << endl;
        //        cout << "Cart 1: <" << carts[1].x << "," << carts[1].y << ">" << endl;
    }
    ASSERT_EQ(1, carts.size());
    EXPECT_EQ(6, carts[0].x);
    EXPECT_EQ(4, carts[0].y);
    EXPECT_EQ(false, carts[0].isCrashed);
}


