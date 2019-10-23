//
//  Advent of Code 2018 Solutions: Day 21
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/21/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <array>
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
namespace AocDay21 {
    constexpr int NUM_REGS = 6;
    unordered_map<std::string, std::function<void (array<int,3>&,array<int,NUM_REGS>&)>> ops {
        {"addr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]+regs[params[1]];}},
        {"addi",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]+params[1];}},
        {"mulr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]*regs[params[1]];}},
        {"muli",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]*params[1];}},
        {"banr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]&regs[params[1]];}},
        {"bani",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]&params[1];}},
        {"borr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]|regs[params[1]];}},
        {"bori",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]]|params[1];}},
        {"setr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=regs[params[0]];}},
        {"seti",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=params[0];}},
        {"gtir",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=(params[0]>regs[params[1]])?1:0;}},
        {"gtri",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=(regs[params[0]]>params[1])?1:0;}},
        {"gtrr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=(regs[params[0]]>regs[params[1]])?1:0;}},
        {"eqir",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=(params[0]==regs[params[1]])?1:0;}},
        {"eqri",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=(regs[params[0]]==params[1])?1:0;}},
        {"eqrr",[](array<int,3>&params,array<int,NUM_REGS>&regs){regs[params[2]]=(regs[params[0]]==regs[params[1]])?1:0;}}
    };
    
	static const std::string InputFileName = "Day21.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int ipRegIndex;
        sscanf(input[0].c_str(),"#ip %d",&ipRegIndex);
        array<int,NUM_REGS> r;
        r.fill(0);
        input.erase(input.begin()); // No longer need this line
        
        //Preparse out the parameters and intstructions to prevent doing it multiple times
        vector<string> program;
        vector<array<int,3>> params;
        program.reserve(input.size());
        program.reserve(input.size());
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            program.push_back(words[0]);
            array<int,3> p;
            p[0] = stoi(words[1]);
            p[1] = stoi(words[2]);
            p[2] = stoi(words[3]);
            params.push_back(p);
        }
        r[0] = 11513432;
        //Run the program
        int count = 0;
        while(r[ipRegIndex] != 28 && r[ipRegIndex] >=0 && r[ipRegIndex] < input.size()) {
            if(r[ipRegIndex] == 28) {
                cout << input[r[ipRegIndex]] << ":R[2]=" << r[2] << ", R[5]=" << r[5] << endl;
            }
            ops[program[r[ipRegIndex]]](params[r[ipRegIndex]],r);
            ++r[ipRegIndex];
            ++count;
        }
        return to_string(r[5]);
		return "---";
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int ipRegIndex;
        sscanf(input[0].c_str(),"#ip %d",&ipRegIndex);
        array<int,NUM_REGS> r;
        r.fill(0);
        input.erase(input.begin()); // No longer need this line
        
        //Preparse out the parameters and intstructions to prevent doing it multiple times
        vector<string> program;
        vector<array<int,3>> params;
        program.reserve(input.size());
        program.reserve(input.size());
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            program.push_back(words[0]);
            array<int,3> p;
            p[0] = stoi(words[1]);
            p[1] = stoi(words[2]);
            p[2] = stoi(words[3]);
            params.push_back(p);
        }

        //Run the program
        int zeroVal = 0;
        unordered_map<int, bool> m;
        while(r[ipRegIndex] >=0 && r[ipRegIndex] < input.size()) {
            ops[program[r[ipRegIndex]]](params[r[ipRegIndex]],r);
            ++r[ipRegIndex];
            if(r[ipRegIndex] == 28) {
                if(m[r[5]]) {
                    //Infinite...halt
                    r[ipRegIndex] += 10;
                } else {
                    m[r[5]] = true;
                    zeroVal = r[5];
                }
            }
        }
        //The last non-repeating r[5] value
        return to_string(zeroVal);
		return "---";
	}

}
