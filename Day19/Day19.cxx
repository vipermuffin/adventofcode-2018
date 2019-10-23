//
//  Advent of Code 2018 Solutions: Day 19
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day19.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <unordered_map>



using namespace std;
constexpr int NUM_REGS = 6;

namespace AocDay19 {
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

	static const std::string InputFileName = "Day19.txt";
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
        
        //Run the program
        while(r[ipRegIndex] >=0 && r[ipRegIndex] < input.size()) {
            ops[program[r[ipRegIndex]]](params[r[ipRegIndex]],r);
            ++r[ipRegIndex];
        }
		return to_string(r[0]);
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
        r[0] = 1;
        while(r[0] == 1 && r[ipRegIndex] >=0 && r[ipRegIndex] < input.size()) {
            ops[program[r[ipRegIndex]]](params[r[ipRegIndex]],r);
            ++r[ipRegIndex];
        }
        
        //(For my input)
        //Register 0 is the sum of all the factors of the number in register 5
        //Run the rest of the program much quicker
        int num = r[5];
        vector<int> factors;
        for(int i = 1; i <= num;++i) {
            if(num % i == 0) {
                factors.push_back(i);
            }
        }
        auto x = accumulate(factors.begin(),factors.end(),0);
        
        return to_string(x);
	}
}
