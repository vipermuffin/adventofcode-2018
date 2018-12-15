//
//  Advent of Code 2018 Solutions: Day 6
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/05/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "AoCUtils.h"
//Common Libraries
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
namespace AocDay06 {

	static const std::string InputFileName = "Day06.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        
		return to_string(findMaxFiniteArea(input));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findSizeOfAreaLessThan(input));
	}

    int findMaxFiniteArea(const vector<std::string>& input) {
        vector<std::pair<int,int>> coordinates;
        coordinates.reserve(input.size());
        int maxX{INT_MIN},maxY{INT_MIN};
        int minX{INT_MAX},minY{INT_MAX};
        for(const auto& line : input) {
            int x,y;
            string copy{line};
            sscanf(copy.c_str(),"%d, %d", &x,&y);
            coordinates.emplace_back(x,y);
            if(x > maxX) {
                maxX = x;
            }
            if(x < minX) {
                minX = x;
            }
            if(y > maxY) {
                maxY = y;
            }
            if(y < minY) {
                minY = y;
            }
        }

        vector<vector<std::pair<int,int>>> grid;
        grid.reserve(maxY-minY);
        vector<std::pair<int,int>> t;
        t.reserve(maxX-minX);
        std::pair<int,int> initP{INT_MAX, -1};
        for(int i = 0;i <= maxX-minX;++i) {
            t.push_back(initP);
        }
        
        for(int i = 0;i <= maxY-minY;++i) {
            grid.push_back(t);
        }
        
        //min distance, id (index) of node
        for(int kvp = 0;kvp < coordinates.size();++kvp) {
            for(int y = 0;y < grid.size();++y) {
                for(int x = 0;x < grid[y].size();++x) {
                    int dist = abs(coordinates[kvp].first-minX-x)+abs(coordinates[kvp].second-minY-y);
                    if(dist < grid[y][x].first) {
                        grid[y][x] = make_pair(dist,kvp);
                    } else if(grid[y][x].first == dist) {
                        if(grid[y][x].second == -1) {
                            grid[y][x].second = kvp;
                        } else {
                            grid[y][x].second =-2;
                        }
                    }
                }
            }
        }
        
        //Determine unbounded indexes
        unordered_set<int> notSafe{};
        for(const auto& p : grid[0]) {
            notSafe.insert(p.second);
        }
        for(const auto& p : grid.back()) {
            notSafe.insert(p.second);
        }
        for(const auto& p : grid) {
            notSafe.insert(p[0].second);
            notSafe.insert(p.back().second);
        }
        
        //Count area of all finite spaces
        unordered_map<int,int> counts;
        for(const auto& v : grid) {
            for(const auto& p : v) {
                if(p.second > 0 && notSafe.count(p.second) == 0) {
                    ++counts[p.second];
                }
            }
        }
        
        //Extract Max area
        int m = INT_MIN;
        for(const auto& kvp : counts) {
            if(kvp.second > m) {
                m = kvp.second;
            }
        }

        return m;
    }
    
        int findSizeOfAreaLessThan(const std::vector<std::string>& input, int size) {
        vector<std::pair<int,int>> coordinates;
        coordinates.reserve(input.size());
        int maxX{INT_MIN},maxY{INT_MIN};
        int minX{INT_MAX},minY{INT_MAX};
        for(const auto& line : input) {
            int x,y;
            string copy{line};
            sscanf(copy.c_str(),"%d, %d", &x,&y);
            coordinates.emplace_back(x,y);
            if(x > maxX) {
                maxX = x;
            }
            if(x < minX) {
                minX = x;
            }
            if(y > maxY) {
                maxY = y;
            }
            if(y < minY) {
                minY = y;
            }
        }
        
        vector<vector<int>> grid;
        grid.reserve(maxY-minY);
        vector<int> t;
        t.reserve(maxX-minX);
        for(int i = 0;i < maxX-minX;++i) {
            t.push_back(0);
        }
        
        for(int i = 0;i <= maxY-minY;++i) {
            grid.push_back(t);
        }
        
        for(int kvp = 0;kvp < coordinates.size();++kvp) {
            for(int y = 0;y < grid.size();++y) {
                for(int x = 0;x < grid[y].size();++x) {
                    int dist = abs(coordinates[kvp].first-minX-x)+abs(coordinates[kvp].second-minY-y);
                    grid[y][x] += dist;
                }
            }
        }
        
        int counts{0};
        for(const auto& v : grid) {
            for(const auto& p : v) {
                if(p < size) {
                    ++counts;
                }
            }
        }
        return counts;
    }
}
