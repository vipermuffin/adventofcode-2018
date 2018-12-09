//
//  Advent of Code 2018 Solutions: Day 8
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/07/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "AoCUtils.h"
//Common Libraries

using namespace std;
namespace AocDay08 {

	static const std::string InputFileName = "Day08.txt";
	std::string solvea() {
        auto input = parseFileForNumbers(InputFileName);
        auto b = input[0].begin();
        return to_string(sumAllMetadata(b,input[0].end()));
	}

	std::string solveb() {
        auto input = parseFileForNumbers(InputFileName);
        auto b = input[0].begin();
		return to_string(valueOfRootNode(b,input[0].end()));
	}
    
    
    int sumAllMetadata(std::vector<int>::iterator& b, const std::vector<int>::iterator e) {
        int sum = 0;
        int numChild{0};
        int metaDataNodes{1};
        if(b < e-2) {
            numChild = *b;
            ++b;
            metaDataNodes = *b;
            ++b;
        }
        
        for(int i = 0 ; i < numChild; ++i) {
            sum += sumAllMetadata(b, e);
        }
        for(int i = 0; i < metaDataNodes; ++i) {
            sum += *b;
            ++b;
        }
        return sum;
    }
    
    int findValue(std::vector<int>::iterator& b, const std::vector<int>::iterator e) {
        int sum = 0;
        int numChild{0};
        int metaDataNodes{1};
        vector<int>children;
        if(b < e-2) {
            numChild = *b;
            ++b;
            metaDataNodes = *b;
            ++b;
        }
        
        if(numChild == 0) {
            for(int i = 0; i < metaDataNodes; ++i) {
                sum += *b;
                ++b;
            }
        } else {
            
            for(int i = 0 ; i < numChild; ++i) {
                children.push_back(findValue(b, e));
            }
            for(int i = 0; i < metaDataNodes; ++i) {
                if(*b > 0 && *b <= children.size()) {
                    sum += children[*b-1];
                }
                ++b;
            }
        }
        
        return sum;
    }
    
    int valueOfRootNode(std::vector<int>::iterator& b, const std::vector<int>::iterator e) {
        return findValue(b, e);
    }
}
