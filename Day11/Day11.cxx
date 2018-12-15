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
#include <algorithm> //std::sort
#include <climits>
#include <thread>
#include <unordered_map>
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
        vals.fill(INT_MIN);
        vector<thread> tV{};

        for(int i = 0; i <= 300;++i) {
            tV.emplace_back(findTopLeft,stoi(input[0]),&vals[i],i);
        }
        for_each(tV.begin(), tV.end(), do_join);
        
        int index;
        for(int i = 1;i < vals.size(); ++i) {
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
    const int GRID_SIZE = 300;
    
    const std::array<std::array<int,GRID_SIZE>,GRID_SIZE>& getGrid(const int sn) {
        static int lastSn = -1;
        static bool generated = false;
        static array<array<int,GRID_SIZE>,GRID_SIZE> grid;
        
        generated = generated && (lastSn==sn);
        
        if(!generated) {
            //Calculate power levels
            for(int x = 0;x < GRID_SIZE;++x) {
                for(int y = 0;y < GRID_SIZE;++y) {
                    grid[x][y] = calcPowerLevel(x, y, sn);
                }
            }
            //Generate Summed Table
            for(int y = 0; y < GRID_SIZE; ++y) {
                for(int x = 0; x < GRID_SIZE; ++x) {
                    auto val = grid[x][y];
                    if(x > 0) {
                        val += grid[x-1][y];
                    }
                    if(y > 0) {
                        val += grid[x][y-1];
                    }
                    if(x > 0 && y > 0) {
                        val -= grid[x-1][y-1];
                    }
                    grid[x][y] = val;
                }
            }
            
            lastSn = sn;
            generated = true;
        }
        
        return grid;
    }
    
    string findTopLeft(int sn, int* maxVal, int sq) {
        union {
            int xy[2];
            long val;
        } hashId;
        
        unordered_map<long, int> m;
        auto grid = getGrid(sn);
        
        for(int x = 0;x <= GRID_SIZE-sq;++x) {
            for(int y = 0;y <= GRID_SIZE-sq;++y) {
                hashId.xy[0] = x;
                hashId.xy[1] = y;
                long output = hashId.val;
                if(x == 0 && y == 0) {
                    m[output] = grid[x+sq-1][y+sq-1];
                } else if(x == 0){
                    m[output] = grid[x+sq-1][y+sq-1] - grid[x+sq-1][y-1];
                } else if(y == 0) {
                    m[output] = grid[x+sq-1][y+sq-1] - grid[x-1][y+sq-1];
                } else {
                    m[output] = grid[x+sq-1][y+sq-1] - grid[x-1][y+sq-1] - grid[x+sq-1][y-1] + grid[x-1][y-1];
                }
            }
        }
        
        int max = INT_MIN;
        for(const auto& p : m) {
            if(p.second > max) {
                max = p.second;
                hashId.val = p.first;
            }
        }
        if(maxVal != nullptr) {
            *maxVal = max;
        }
        string output = to_string(hashId.xy[0]);
        output.append(",");
        output.append(to_string(hashId.xy[1]));
        return output;
    }
}
