//
//  Advent of Code 2018 Solutions: Day 2
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/01/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "AoCUtils.h"
//Common Libraries
#include <unordered_map>

using namespace std;
namespace AocDay02 {

	static const std::string InputFileName = "Day02.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
      
		return to_string(calculateChecksum(input));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        return findProtoBox(input);
	}

    int calculateChecksum(const std::vector<std::string>& input) {
        vector<int> checksums{};
        int three{0};
        int two{0};
        
        for(const auto& x : input) {
            unordered_map<char,int> letters;
            bool found2{false};
            bool found3{false};
            for(const auto& c : x) {
                letters[c]++;
            }
            
            for(const auto& p : letters) {
                if(!found2 && p.second==2) {
                    two++;
                    found2=true;
                } else if(!found3 && p.second==3) {
                    three++;
                    found3= true;
                }
            }
        }
        
        return two*three;
    }
    
    std::string findProtoBox(const std::vector<std::string>& input) {
        for(int i = 0; i < input.size();++i) {
            for(int j = 0; j < input.size();++j) {
                if(i != j) {
                    int diffs{0};
                    int pos{0};
                    for(int y = 0; y < input[i].size() && diffs <= 1;++y) {
                        if(input[i][y] != input[j][y]) {
                            ++diffs;
                            pos = y;
                        }
                    }
                    if(diffs == 1) {
                        string s{input[i].begin(),input[i].begin()+pos};
                        s.append(string(input[i].begin()+pos+1,input[i].end()));
                        return s;
                    }
                }
            }
        }
        return "---";
    }
}
