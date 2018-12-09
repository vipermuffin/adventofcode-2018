//
//  Advent of Code 2018 Main Runner: Day 9
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/09/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay09{
   extern std::string solvea();
   extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

	std::cout << "Day09" << "a: " << AocDay09::solvea() << std::endl;
	std::cout << "Day09" << "b: " << AocDay09::solveb() << std::endl;
	return 0;
}
