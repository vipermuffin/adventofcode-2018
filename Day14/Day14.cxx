//
//  Advent of Code 2018 Solutions: Day 14
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/13/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day14.h"
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
#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay14 {
    long findRecipeCode3(std::vector<int>& recipes, int numRecipes);
	static const std::string InputFileName = "Day14.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<int> v {
            3,
            7
        };
        auto numRuns = stoi(input[0]);
        v.reserve(numRuns+12);
		return findRecipeCode(v, stoi(input[0]));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<int> v {
            3,
            7
        };
        v.reserve(222000000);
        auto x = findRecipeCode3(v, stoi(input[0]));
        
		return to_string(x);
	}
    
    void addRecipe(std::vector<int>& recipes, struct elf& e1, struct elf& e2) {
        e1.index += 1+e1.score;
        e2.index += 1+e2.score;
        
        while(e1.index >= recipes.size()) {
            e1.index -= recipes.size();
        }
        
        while(e2.index >= recipes.size()) {
            e2.index -= recipes.size();
        }
        e1.score = recipes[e1.index];
        e2.score = recipes[e2.index];
        
        auto score = e1.score + e2.score;
        if(score > 9) {
            recipes.push_back(score/10);
        }
        recipes.push_back(score%10);
    }

    std::string findRecipeCode(std::vector<int>& recipes, int numRecipes) {
        stringstream output{};
        int num =numRecipes + 10;
        struct elf e1{0,3};
        struct elf e2{1,7};
        
        while(recipes.size() < num) {
            addRecipe(recipes, e1, e2);
        }
        auto itr = recipes.begin()+numRecipes;
        num = 0;
        while(num < 10 && itr != recipes.end()) {
            output << *itr++;
            ++num;
        }
        
        return output.str();
    }
    
    std::string findRecipeCode2(std::vector<int>& recipes, int numRecipes) {
        string output{"37"};
        string num = to_string(numRecipes);
        struct elf e1{0,3};
        struct elf e2{1,7};
        
        while(output.find(num) == string::npos) {
            auto lastSize = recipes.size();
            addRecipe(recipes, e1, e2);
            auto it = recipes.end()-(recipes.size()-lastSize);
            while(it != recipes.end()) {
                output.append(to_string(*it++));
            }
        }
        
        auto x = output.find(num);
        
        return string(output.begin(),output.begin()+x);
    }
    
    long findRecipeCode3(std::vector<int>& recipes, int numRecipes) {
        string num = to_string(numRecipes);
        auto numItr = num.begin();
        struct elf e1{0,3};
        struct elf e2{1,7};
        
        while(numItr != num.end()) {
            auto lastSize = recipes.size();
            addRecipe(recipes, e1, e2);
            auto it = recipes.end()-(recipes.size()-lastSize);
            while(numItr != num.end() && it != recipes.end()) {
                if(*numItr == ('0' +*it++)) {
                    ++numItr;
                } else {
                    numItr = num.begin();
                }
            }
            if(it != recipes.end()) {
                recipes.erase(it);
            }
        }
        
        return recipes.size()-num.size();
    }
}
