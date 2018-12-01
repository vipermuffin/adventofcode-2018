//
//  Advent of Code 2018 Solutions: Day 1
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 11/30/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay01 {

	static const std::string InputFileName = "Day01.txt";
	std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);

        return to_string(std::accumulate(input.begin(), input.end(), 0));
	}

	std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        unordered_map<int, int> freqs{};
        int sum{0};
        while( sum < INT_MAX ) {
            for(const auto& x : input) {
                sum += x;
                freqs[sum] += 1;
                if(freqs[sum] == 2) {
                    return to_string(sum);
                }
            }
        }
		return "---";
	}

}
