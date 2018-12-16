//
//  Advent of Code 2018 Solutions: Day 16
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/15/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "AoCUtils.h"
//Common Libraries
#include <array>
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <set>
#include <unordered_map>

using namespace std;
namespace AocDay16 {

	static const std::string InputFileName = "Day16.txt";
    int AnalyzeSamples(std::vector<std::string>& input,std::unordered_map<int, std::set<std::string>>&codes);
    unordered_map<std::string, std::function<void (array<int,3>&,array<int,4>&)>> ops {
        {"addr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]+regs[params[1]];}},
        {"addi",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]+params[1];}},
        {"mulr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]*regs[params[1]];}},
        {"muli",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]*params[1];}},
        {"banr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]&regs[params[1]];}},
        {"bani",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]&params[1];}},
        {"borr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]|regs[params[1]];}},
        {"bori",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]]|params[1];}},
        {"setr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=regs[params[0]];}},
        {"seti",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=params[0];}},
        {"gtir",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=(params[0]>regs[params[1]])?1:0;}},
        {"gtri",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=(regs[params[0]]>params[1])?1:0;}},
        {"gtrr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=(regs[params[0]]>regs[params[1]])?1:0;}},
        {"eqir",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=(params[0]==regs[params[1]])?1:0;}},
        {"eqri",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=(regs[params[0]]==params[1])?1:0;}},
        {"eqrr",[](array<int,3>&params,array<int,4>&regs){regs[params[2]]=(regs[params[0]]==regs[params[1]])?1:0;}}
    };
    
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        
        unordered_map<int, set<string>> codes;
        
		return to_string(AnalyzeSamples(input, codes));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        //Analyze example instructions to see possible instructions
        unordered_map<int, set<string>> codes;
        (void) AnalyzeSamples(input, codes);
        
        //Analyze possible instructions to determine actual op code mapping
        vector<string> opCodesStr(ops.size(),"");
        set<string> found;
        while(found.size() < ops.size()) {
            for(auto& kvp : codes) {
                if(kvp.second.size() == 1) {
                    auto instruction = kvp.second.begin();
                    found.insert(*instruction);
                    opCodesStr[kvp.first] = *instruction;
                    kvp.second.erase(instruction);
                } else if (kvp.second.size() > 1) {
                    for(const auto& k : found) {
                        auto x = kvp.second.find(k);
                        if(x != kvp.second.end()) {
                            kvp.second.erase(x);
                        }
                    }
                }
            }
        }
        
        //Find start of program (comes after three new lines
        auto itr = input.begin();
        int blankCount = 0;
        while(blankCount < 3) {
            if(*itr++ == "") {
                ++blankCount;
            } else {
                blankCount = 0;
            }
        }
        //Execute program
        array<int,4> regs;
        regs.fill(0);
        array<int,3> params;
        while(itr < input.end()) {
            auto x = parseLineForNumbers(*itr++);
            params[0]=x[1];
            params[1]=x[2];
            params[2]=x[3];
            ops[opCodesStr[x[0]]](params,regs);
        }
        
		return to_string(regs[0]);
	}
    
    int AnalyzeSamples(std::vector<std::string>& input,std::unordered_map<int, std::set<std::string>>&codes) {
        int sum = 0;
        for(int i = 0;i < input.size()-4;i+=4){
            if(input[i].substr(0,6) == "Before"){
                array<int,4> start;
                array<int,4> finish;
                sscanf(input[i].c_str(),"Before: [%d, %d, %d, %d]",&start[0],&start[1],&start[2],&start[3]);
                sscanf(input[i+2].c_str(),"After: [%d, %d, %d, %d]",&finish[0],&finish[1],&finish[2],&finish[3]);
                auto x = parseLineForNumbers(input[i+1]);
                array<int,4> regs;
                array<int,3> params{x[1],x[2],x[3]};
                int count=0;
                for(auto& kvp : ops) {
                    for(int j = 0;j<4;++j) {
                        regs[j] = start[j];
                    }
                    kvp.second(params,regs);
                    if(finish[0] == regs[0] &&
                       finish[1] == regs[1] &&
                       finish[2] == regs[2] &&
                       finish[3] == regs[3]) {
                        codes[x[0]].insert(kvp.first);
                        ++count;
                    }
                }
                if(count >=3) {
                    ++sum;
                }
            }
        }
        return sum;
    }
}
