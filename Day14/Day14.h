//
//  Advent of Code 2018 Solutions: Day 14
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/13/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay14 {
//Function Definitions

    struct elf {
        int index;
        int score;
    };
    
    void addRecipe(std::vector<int>& recipes, struct elf& e1, struct elf& e2);
    std::string findRecipeCode(std::vector<int>& recipes, int numRecipes);
    std::string findRecipeCode2(std::vector<int>& recipes, int numRecipes);
}
