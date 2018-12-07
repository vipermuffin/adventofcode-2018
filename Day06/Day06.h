//
//  Advent of Code 2018 Solutions: Day 6
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/05/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay06 {
//Function Definitions

    int findMaxFiniteArea(const std::vector<std::string>& input);
    std::vector<int> getIndexOfFinitePairs(const std::vector<std::pair<int,int>>&);
    int findSizeOfAreaLessThan(const std::vector<std::string>& input, int size = 10000);
}
