//
//  Advent of Code 2018 Solutions: Day 7
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/06/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "AoCUtils.h"
//Common Libraries

using namespace std;
namespace AocDay07 {

	static const std::string InputFileName = "Day07.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return determineOrder(input);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(determineOrder2(input));
	}
    
    bool isReady(const char& key, const std::string& preqs, const std::set<char>& steps) {
        if(steps.count(key) != 0) {
            return false;
        }
        for(const auto& c : preqs) {
            if(steps.count(c) == 0) {
                return false;
            }
        }
        return true;
    }
    
    string determineOrder(const std::vector<std::string>& input) {
        map<char,std::pair<string,string>> directions{};
        set<char> steps;
        set<char> iSet;
        string result;
        
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            directions[words[1][0]].first.append(words[7]);
            directions[words[7][0]].second.append(words[1]);
            steps.insert(words[1][0]);
            steps.insert(words[7][0]);
        }

        auto sItr = steps.begin();
        while(sItr != steps.end()) {
            if(isReady(*sItr, directions[*sItr].second, iSet)) {
                result += *sItr;
                iSet.insert(*sItr);
                sItr = steps.begin();
            } else {
                ++sItr;
            }
        }

        return result;
    }

    int determineOrder2(const std::vector<std::string>& input, const int NUM_WORKERS, const int NUM_SECONDS) {
        map<char,std::pair<string,string>> directions{};
        set<char> steps;
        set<char> iSet;
        string result;
        vector<std::pair<char,int>> activeSteps;
        int time{0};
        
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            directions[words[1][0]].first.append(words[7]);
            directions[words[7][0]].second.append(words[1]);
            steps.insert(words[1][0]);
            steps.insert(words[7][0]);
        }
        
        auto sItr = steps.begin();
        set<char> cooking;
        while(iSet.size() != steps.size()) {
            auto asItr = activeSteps.begin();
            vector<char> x;
            while(asItr != activeSteps.end()) {
                if(asItr->second++ == (asItr->first - 'A' + NUM_SECONDS)) {
                    result += asItr->first;
                    iSet.insert(asItr->first);
                    x.push_back(asItr->first);
                }
                ++asItr;
            }
            
            for(auto i : x) {
                auto cItr = activeSteps.begin();
                bool found = false;
                while(!found && cItr !=activeSteps.end()) {
                    found = cItr->first == i;
                    if(!found) {
                        ++cItr;
                    }
                }
                if(cItr != activeSteps.end()) {
                    activeSteps.erase(cItr);
                }
            }
            
            //Checking for readiness
            for(sItr = steps.begin();(activeSteps.size() < NUM_WORKERS) && sItr != steps.end();++sItr) {
                if((cooking.count(*sItr) == 0) && isReady(*sItr, directions[*sItr].second, iSet)) {
                    activeSteps.emplace_back(*sItr,0);
                    cooking.insert(*sItr);
                }
            }
            
            ++time;
        }
        
        return time-1;
    }
}
