//
//  Advent of Code 2018 Solutions: Day 23
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/22/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay23 {
//Function Definitions

    class NanoBot {
    public:
        NanoBot(int x, int y, int z, int r);
        int getDistance(const NanoBot& rhs) const;
        int x;
        int y;
        int z;
        int signal;
    };
    
    std::string performB(const std::vector<std::string>& input);
    std::string performB2(const std::vector<std::string>& input);
    std::string performB3(const std::vector<std::string>& input);
}
