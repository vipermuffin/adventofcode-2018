//
//  Advent of Code 2018 Solutions: Day 11
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/10/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay11 {
//Function Definitions
    long calcPowerLevel(int x, int y, int sn);
    std::string findTopLeft(int sn, int* maxVal=nullptr, int sq = 3);
}
