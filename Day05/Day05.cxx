//
//  Advent of Code 2018 Solutions: Day 5
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/04/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "AoCUtils.h"
//Common Libraries
#include <sstream>
#include <cmath>
#include <array>
#include <thread>

using namespace std;
namespace AocDay05 {

	static const std::string InputFileName = "Day05.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int fs{0};
        performChemistry(input[0],fs);

		return to_string(fs);
	}

    void do_join(std::thread& t) {
        t.join();
    }
    
	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        string abc{"abcdefghijklmnopqrstuvwxyz"};
        string ABC{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        array<int, 26> mins;
        vector<thread> tV{};
        
        for(int x = 0;x < abc.size();++x) {
            tV.push_back(thread(performChemistry,std::ref(input[0]), std::ref(mins[x]),&abc[x],&ABC[x]));
        }
        
        for_each(tV.begin(), tV.end(), do_join);
    
        auto min = min_element(mins.begin(), mins.end());
        return to_string(*min);
	}

    void performChemistry(const std::string& input, int& finalStrSize, const char* c1, const char* c2) {
        int diff = 'a' - 'A';
        auto iStr{input};
        int d = 1;
        while(d != 0) {
            stringstream ss;
            d = 0;
            int i{0};
            for(i = 0;i<iStr.size()-1;++i) {
                if((c1 != nullptr && iStr[i] == *c1) || (c2 != nullptr && iStr[i] == *c2)) {
                } else if(abs(iStr[i] - iStr[i+1]) == diff) {
                    ++i;
                    ++d;
                } else {
                    ss << iStr[i];
                }
            }
            if(i==iStr.size()-1) {
                ss << iStr[i];
            }
            iStr = ss.str();
        }
        finalStrSize = iStr.size();
    }
}
