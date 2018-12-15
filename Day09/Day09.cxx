//
//  Advent of Code 2018 Solutions: Day 9
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/09/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm>
#include <list>

using namespace std;
namespace AocDay09 {

	static const std::string InputFileName = "Day09.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto words = parseLineForWords(input[0]);
		return to_string(playGame(stoi(words[0]), stoi(words[6])));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto words = parseLineForWords(input[0]);
        return to_string(playGame(stoi(words[0]), stoi(words[6])*100));
	}

    long playGame(const int numPlayers, const int lastMarble) {
        const int MAGIC_MARBLE{23};
        const int MAGIC_STEPS{8};
        list<int> x{};
        vector<long> players(numPlayers,0);
        
        auto itr = x.end();
        for(int i = 1; i <= lastMarble;++i) {
            int currentPlayer = i % numPlayers;
            auto current = itr;
            if(i%MAGIC_MARBLE == 0) {
                players[currentPlayer] += i;
                for(int y = 0;y < MAGIC_STEPS;++y) {
                    if(itr == x.begin()) {
                        itr = x.end();
                    } else {
                        --itr;
                    }
                }
                players[currentPlayer] += *itr;
                current = x.erase(itr);
                if(itr == x.end()) {
                    itr = x.begin();
                } else {
                    ++itr;
                }
                if(itr == x.end()) {
                    itr = x.begin();
                } else {
                    ++itr;
                }
            } else {
                if(itr == x.end()) {
                    itr = x.begin();
                } else {
                    ++itr;
                }
                current = x.insert(itr, i);
            }
        }
        auto max = max_element(players.begin(), players.end());
        return *max;
    }
}
