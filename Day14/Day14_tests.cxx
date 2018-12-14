//
//  Advent of Code 2018 Tests: Day 14
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/13/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay14{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay14;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("1150511382", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("20173656", solveb());
}

TEST(Example,Test1) {
    vector<int> v {
        3,
        7
    };
    struct elf e1{0,3};
    struct elf e2{1,7};
    addRecipe(v, e1, e2);
	ASSERT_EQ(4,v.size());
    EXPECT_EQ(3,v[0]);
    EXPECT_EQ(7,v[1]);
    EXPECT_EQ(1,v[2]);
    EXPECT_EQ(0,v[3]);
    
    addRecipe(v, e1, e2);
    ASSERT_EQ(6,v.size());
    EXPECT_EQ(3,v[0]);
    EXPECT_EQ(7,v[1]);
    EXPECT_EQ(1,v[2]);
    EXPECT_EQ(0,v[3]);
    EXPECT_EQ(1,v[4]);
    EXPECT_EQ(0,v[5]);
    
}

TEST(Example,Test2) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode(v, 9);
    ASSERT_EQ("5158916779", s);
}

TEST(Example,Test2a) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode2(v, 9);
    ASSERT_EQ("3710101245158", s);
}

TEST(Example,Test3) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode(v, 5);
    ASSERT_EQ("0124515891", s);
}

TEST(Example,Test3a) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode2(v, 5);
    ASSERT_EQ("371010124", s);
}

TEST(Example,Test4) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode(v, 18);
    ASSERT_EQ("9251071085", s);
}

TEST(Example,Test4a) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode2(v, 18);
    ASSERT_EQ("371010124515891677925107108510111078111982416114", s);
}

TEST(Example,Test5) {
    vector<int> v {
        3,
        7
    };
    auto s = findRecipeCode(v, 2018);
    ASSERT_EQ("5941429882", s);
}
