//
//  Advent of Code 2018 Solutions: Day 3
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/02/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay03 {
//Function Definitions
    std::unordered_map<uint32_t, int> getInputMap(const std::vector<std::string>& input);
    int getSqFtOverlap(const std::unordered_map<uint32_t, int>&);
    int getIdNoOverlap(std::unordered_map<uint32_t, int>&claims, const std::vector<std::string>& input);
}
