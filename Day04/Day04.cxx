//
//  Advent of Code 2018 Solutions: Day 4
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/03/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "AoCUtils.h"
//Common Libraries
#include <unordered_map>

using namespace std;
namespace AocDay04 {

    void analyzeLog(std::vector<string>&,unordered_map<string,int>&,unordered_map<string, vector<int>>&);
	static const std::string InputFileName = "Day04.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        sort(input.begin(),input.end());
        unordered_map<string,int> log;
        unordered_map<string, vector<int>> minuteLog;

        analyzeLog(input, log, minuteLog);
        
        std::pair<string,int> maxT{"#-1",0};
        for(const auto& guard : log) {
            if(guard.second > maxT.second) {
                maxT = guard;
            }
        }
        auto maxMin = max_element(minuteLog[maxT.first].begin(), minuteLog[maxT.first].end());
        string x{maxT.first.begin()+1,maxT.first.end()};
        int gId = stoi(x);
        return to_string(gId*(maxMin-minuteLog[maxT.first].begin()));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        sort(input.begin(),input.end());
        unordered_map<string,int> log;
        unordered_map<string, vector<int>> minuteLog;
        
        analyzeLog(input, log, minuteLog);
        
        std::pair<string,int> maxT{"#-1",0};
        int maxMinute{0};
        for(const auto& guard : log) {
            auto maxMin = max_element(minuteLog[guard.first].begin(), minuteLog[guard.first].end());
            if(*maxMin > maxMinute) {
                maxMinute = *maxMin;
                maxT = make_pair(guard.first, maxMin - minuteLog[guard.first].begin());
            }
        }
        string x{maxT.first.begin()+1,maxT.first.end()};
        int gId = stoi(x);
        return to_string(gId*maxT.second);
	}

    void analyzeLog(std::vector<string>&input,unordered_map<string,int>&log,unordered_map<string, vector<int>>&minuteLog) {
        vector<int> noMinutes(60,0);
        
        string g;
        int sHour;
        int sMinute;
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            if(words[2] == "Guard") {
                if(log.count(words[3]) == 0) {
                    minuteLog[words[3]] = noMinutes;
                }
                g = words[3];
            } else if(words[2] == "falls") {
                sscanf(words[1].c_str(), "%d:%d]",&sHour,&sMinute);
            } else {
                int aHour, aMinute;
                sscanf(words[1].c_str(), "%d:%d]",&aHour,&aMinute);
                log[g] += aMinute - sMinute;
                for(int i = sMinute; i < aMinute;++i) {
                    ++minuteLog[g][i];
                }
            }
        }
    }
}
