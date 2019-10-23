//
//  Advent of Code 2018 Solutions: Day 18
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/18/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
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
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay18 {

	static const std::string InputFileName = "Day18.txt";
    std::string convertToString(const std::vector<std::string>&in) {
        string s;
        s.reserve(in.size()*in[0].size());
        for(const auto& line : in) {
            s.append(line);
        }
        return s;
    }
    
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        for(int i = 0; i < 10; ++i) {
            RunTimeStep(input);
        }
        auto x = CountWoodsAndLumber(input);
        
		return to_string(x.first*x.second);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string,int> x;
        int i;
        int finalIndex{0};
        string a;
        for(i = 0; i < 1000000000; ++i) {
            RunTimeStep(input);
            a = convertToString(input);
            if(x.count(a) > 0) {
                finalIndex = 1000000000 - i-1;
                finalIndex %= i-x[a];
                finalIndex += x[a];
                break;
            } else {
                x[a] = i;
            }
        }
        auto itr = x.begin();
        while(itr->second != finalIndex) {
            ++itr;
        }
        vector<string> tmp{itr->first};
        auto y = CountWoodsAndLumber(tmp);
        
        return to_string(y.first*y.second);
	}

    inline void IncOpenWoodsOrLumber(const char& c, int& open, int& woods, int& lumber) {
        if(c == '|') {
            ++woods;
        } else if (c == '#') {
            ++lumber;
        } else if (c == '.') {
            ++open;
        }
    }
    void CountNeighbors(const std::vector<std::string>& acres, int& open, int& woods, int& lumber, int i, int j) {
        if(i > 0 && i < acres[i].size() - 1) {
            IncOpenWoodsOrLumber(acres[i-1][j], open, woods, lumber);
            IncOpenWoodsOrLumber(acres[i+1][j], open, woods, lumber);
            if( j > 0) {
                IncOpenWoodsOrLumber(acres[i-1][j-1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i][j-1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i+1][j-1], open, woods, lumber);
            }
            if( j < acres[i].size()-1) {
                IncOpenWoodsOrLumber(acres[i-1][j+1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i][j+1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i+1][j+1], open, woods, lumber);
            }
        } else if( i > 0) {
            IncOpenWoodsOrLumber(acres[i-1][j], open, woods, lumber);
            if( j > 0) {
                IncOpenWoodsOrLumber(acres[i-1][j-1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i][j-1], open, woods, lumber);
            }
            if( j < acres[i].size()-1) {
                IncOpenWoodsOrLumber(acres[i-1][j+1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i][j+1], open, woods, lumber);
            }
        } else {
            IncOpenWoodsOrLumber(acres[i+1][j], open, woods, lumber);
            if( j > 0) {
                IncOpenWoodsOrLumber(acres[i][j-1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i+1][j-1], open, woods, lumber);
            }
            if( j < acres[i].size()-1) {
                IncOpenWoodsOrLumber(acres[i][j+1], open, woods, lumber);
                IncOpenWoodsOrLumber(acres[i+1][j+1], open, woods, lumber);
            }
        }
    }
    
    void RunTimeStep(std::vector<std::string>& acres) {
        auto copy{acres};
        for(int i = 0; i < acres.size(); ++i) {
            for(int j = 0;j < acres[i].size(); ++j) {
                int open{0}, woods{0}, lumber{0};
                CountNeighbors(copy, open, woods, lumber, i, j);
                
                switch(acres[i][j]) {
                    case '.':
                        if(woods >= 3) {
                            acres[i][j] = '|';
                        }
                        break;
                        
                    case '|':
                        if(lumber >=3) {
                            acres[i][j] = '#';
                        }
                        break;
                    case '#':
                        if(!(lumber > 0 && woods > 0)) {
                            acres[i][j] = '.';
                        }
                    default:
                        break;
                }
            }
        }
    }
    
    std::pair<int,int> CountWoodsAndLumber(const std::vector<std::string>& input) {
        std::pair<int,int> x{0,0};
        for(const auto& row : input) {
            for(const auto& c : row) {
                if(c == '|') {
                    ++x.first;
                } else if (c == '#') {
                    ++x.second;
                }
            }
        }
        return x;
    }
}
