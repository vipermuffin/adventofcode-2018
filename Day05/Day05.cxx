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
    constexpr bool THREADED = true;
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
            if constexpr(THREADED) {
            tV.emplace_back(performChemistry,std::ref(input[0]), std::ref(mins[x]),&abc[x],&ABC[x]);
            } else {
                performChemistry(input[0], mins[x],&abc[x],&ABC[x]);
            }
        }
        
        for_each(tV.begin(), tV.end(), do_join);
    
        auto min = min_element(mins.begin(), mins.end());
        return to_string(*min);
	}

    void performChemistry(const std::string& input, int& finalStrSize, const char* c1, const char* c2) {
        int diff = 'a' - 'A';
        auto iStr{input};
        bool repeat = true;
        while(repeat) {
            string ss{};
            ss.reserve(iStr.length());
            auto front = iStr.begin();
            auto itr = front;
            auto next = itr+1;
            bool d = false;
            while(!d) {
                d = true;
                
                //Need to check next against c1 and c2 and adjust pointers accordingly
                while((itr >= front && next < iStr.end()) &&
                      !((c1 != nullptr && *itr == *c1) || (c2 != nullptr && *itr == *c2) || (abs(*itr - *next) == diff))) {
                    ++itr;
                    ++next;
                }
                
                while((itr >= front && next < iStr.end()) &&
                      ((c1 != nullptr && *itr == *c1) || (c2 != nullptr && *itr == *c2) || (abs(*itr - *next) == diff))) {
                    if((c1 != nullptr && *itr == *c1) || (c2 != nullptr && *itr == *c2)) {
                        --itr;
                    } else {
                        --itr;
                        ++next;
                    }
                    d = false;
                }
                
                if(front <= itr) {
                    if(itr < iStr.end()) {
                        ++itr;
                    }
                    ss.append(front,itr);
                }
                front = next;
                itr = next++;
            }
            repeat = iStr != ss;
            iStr = ss;
        }
        finalStrSize = iStr.size();
    }
}
