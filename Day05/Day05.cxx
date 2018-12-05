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

using namespace std;
namespace AocDay05 {

	static const std::string InputFileName = "Day05.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int diff = 'a' - 'A';
        auto iStr{input[0]};
        int d = 1;
        while(d != 0) {
        stringstream ss;
            d = 0;
            int i{0};
            for(i = 0;i<iStr.size()-1;++i) {
                if(abs(iStr[i] - iStr[i+1]) == diff) {
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
		return to_string(iStr.size());
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int diff = 'a' - 'A';
        int minSize = INT_MAX;
        string abc{"abcdefghijklmnopqrstuvwxyz"};
        string ABC{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        for(int x = 0;x < abc.size();++x) {
            auto iStr{input[0]};
            int d = 1;
            while(d != 0) {
                stringstream ss;
                d = 0;
                int i{0};
                for(i = 0;i<iStr.size()-1;++i) {
                    if(iStr[i] == abc[x] || iStr[i] == ABC[x]) {
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
            if(iStr.size() < minSize) {
                minSize = iStr.size();
            }
        }

        return to_string(minSize);
	}

}
