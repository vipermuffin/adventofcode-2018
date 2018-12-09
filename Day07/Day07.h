//
//  Advent of Code 2018 Solutions: Day 7
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/06/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>

namespace AocDay07 {
//Function Definitions

    std::string determineOrder(const std::vector<std::string>& input);
    void printOrder(const std::map<std::string,std::vector<std::string>>&,const std::string& next, std::set<std::string>& steps, std::string& output) ;
    int determineOrder2(const std::vector<std::string>& input, const int NUM_WORKERS = 5, const int NUM_SECONDS = 60);
}
