//
//  Advent of Code 2018 Solutions: Day 12
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/11/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay12 {
//Function Definitions
    std::string performGeneration(std::unordered_map<std::string,char>& recipe,std::string initState, long* index = nullptr);
    int countPlants(const std::string& p);
    long sumPlantNumbers(const std::string& p,long start);
}
