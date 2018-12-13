//
//  Advent of Code 2018 Solutions: Day 12
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/11/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day12.h"
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
//#include <thread>
//#include <tuple>

//#include <unordered_set>


using namespace std;
namespace AocDay12 {

	static const std::string InputFileName = "Day12.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string, char> codes;
        
        for(int i = 2; i < input.size();++i) {
            auto words = parseLineForWords(input[i]);
            codes[words[0]] = words[2][0];
        }
        
        auto firstLine = parseLineForWords(input[0]);
        string initial{firstLine[2]};
        long index{0};
        for(int i = 0; i < 20;++i) {
            initial = performGeneration(codes, initial,&index);
        }
        
		return to_string(sumPlantNumbers(initial,index));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string, char> codes;
        vector<string> seen;
        unordered_map<string, long> seenIndex;
        
        for(int i = 2; i < input.size();++i) {
            auto words = parseLineForWords(input[i]);
            codes[words[0]] = words[2][0];
        }
        
        auto firstLine = parseLineForWords(input[0]);
        bool found = false;
        string initial{firstLine[2]};
        long index{0};
        for(int i = 0; !found && i < 5000000;++i) {
            initial = performGeneration(codes, initial,&index);
            if(seenIndex.count(initial) > 0) {
                found = true;
            } else {
                seen.push_back(initial);
                seenIndex[initial] = index;
            }
        }
        
        if(found) {
            auto indexSteps = index - seenIndex[initial];
            auto mod = 50000000000 - seen.size()-1;
            index += mod*indexSteps;
            auto x = sumPlantNumbers(initial, index);
            return to_string(x);
        }
        
        return "---";
	}
    
    std::string performGeneration(std::unordered_map<std::string,char>& recipe,std::string initState, long* index) {
        string newState{"...."+initState+"...."};
        initState.insert(0, "....");
        initState.append("....");
        if(index != nullptr) {
            *index -=4;
        }
        auto sItr = initState.begin();
        for(int i = 2; i < newState.size();++i) {
            auto cmpStr = string(sItr,(sItr+5 < initState.end()) ? sItr+5 : initState.end());
            while(cmpStr.size() < 5) {
                cmpStr.append(".");
            }
            if(recipe.count(cmpStr)) {
                newState[i] = recipe[cmpStr];
            } else {
                newState[i] = '.';
            }
            
            ++sItr;
        }
        auto x = newState.find("#");
        if (x != string::npos) {
            *index += x;
        }
        auto y = newState.find_last_of("#");
        
        return string(newState.begin()+x,newState.begin()+y+1);
    }
    
    int countPlants(const std::string& p) {
        int sum{0};
        for(const auto& c : p) {
            if(c == '#') {
                ++sum;
            }
        }
        return sum;
    }
    
    long sumPlantNumbers(const std::string& p,long start) {
        long sum{0};
        for(const auto& c : p) {
            if(c == '#') {
                sum += start;
            }
            start++;
        }
        return sum;
    }

}
