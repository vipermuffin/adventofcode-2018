//
//  Advent of Code 2018 Solutions: Day 11
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/10/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day11.h"
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
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>
#include <array>

using namespace std;
namespace AocDay11 {

	static const std::string InputFileName = "Day11.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto x = findTopLeft(stoi(input[0]));
		return x;
	}

    void do_join(std::thread& t) {
        t.join();
    }
    
	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int max = INT_MIN;
        string output;
        array<int, 301> vals;
        vector<thread> tV{};

        for(int i = 3; i <= 30;++i) {
            tV.emplace_back(findTopLeft,stoi(input[0]),&vals[i],i);
        }
        for_each(tV.begin(), tV.end(), do_join);
        
        int index;
        for(int i = 0;i < vals.size(); ++i) {
            if(vals[i] > max) {
                max = vals[i];
                index = i;
            }
        }
        output = findTopLeft(stoi(input[0]),&max,index);
        output += ","+to_string(index);

		return output;
	}

    long calcPowerLevel(int x, int y, int sn) {
        int rackId = x+10;
        long powerLevel = rackId*y;
        powerLevel += sn;
        powerLevel *= rackId;
        powerLevel %=1000;
        powerLevel /=100;
        powerLevel -= 5;
        
        return powerLevel;
    }
    
    string findTopLeft(int sn, int* maxVal, int sq) {
        array<array<int,300>,300> grid;
        unordered_map<string, int> m;
        for(int x = 0;x < 300;++x) {
            for(int y = 0;y < 300;++y) {
                grid[x][y] = calcPowerLevel(x, y, sn);
            }
        }
        
        for(int x = 0;x <= 300-sq;++x) {
            for(int y = 0;y <= 300-sq;++y) {
                string output = to_string(x) + "," + to_string(y);
                for(int xo = 0; xo < sq;++xo) {
                    for(int yo = 0; yo< sq;++yo) {
                        m[output] += grid[x+xo][y+yo];
                    }
                }
            }
        }
        int max = INT_MIN;
        string maxId;
        for(const auto& p : m) {
            if(p.second > max) {
                max = p.second;
                maxId = p.first;
            }
        }
        if(maxVal != nullptr) {
            *maxVal = max;
        }
        return maxId;
    }
}
