//
//  Advent of Code 2018 Solutions: Day 3
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/02/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day03.h"
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
#include <regex>
//#include <set>
#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay03 {
    
	static const std::string InputFileName = "Day03.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string, int> claims;
        int sqFt{0};

        regex re{"#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"};
        for(const auto& claim : input) {
            try {
                sregex_iterator next{claim.begin(),claim.end(),re};
                sregex_iterator end;
                while(next != end) {
                    smatch match = *next;
//                    int id = stoi(match[1]);
                    int lOffset = stoi(match[2]);
                    int tOffset = stoi(match[3]);
                    int width = stoi(match[4]);
                    int height = stoi(match[5]);
                    for(int y = tOffset;y < tOffset + height;++y) {
                        for(int x = lOffset; x < lOffset + width;++x) {
                            auto p = to_string(x) + "," + to_string(y);
                            if(++claims[p] == 2) {
                                ++sqFt;
                            }
                        }
                    }
                    ++next;
                }
            } catch (regex_error& e ) {
                //Syntax error in regex
                cout << "ERROR: " << e.what() << endl;
            }
        }
        
		return to_string(sqFt);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string, int> claims;
        int sqFt{0};
        
        regex re{"#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"};
        for(const auto& claim : input) {
            try {
                sregex_iterator next{claim.begin(),claim.end(),re};
                sregex_iterator end;
                while(next != end) {
                    smatch match = *next;
//                    int id = stoi(match[1]);
                    int lOffset = stoi(match[2]);
                    int tOffset = stoi(match[3]);
                    int width = stoi(match[4]);
                    int height = stoi(match[5]);
                    for(int y = tOffset;y < tOffset + height;++y) {
                        for(int x = lOffset; x < lOffset + width;++x) {
                            auto p = to_string(x) + "," + to_string(y);
                            ++claims[p];
                        }
                    }
                    ++next;
                }
            } catch (regex_error& e ) {
                //Syntax error in regex
                cout << "ERROR: " << e.what() << endl;
            }
        }
        
        for(const auto& claim : input) {
            try {
                sregex_iterator next{claim.begin(),claim.end(),re};
                sregex_iterator end;
                while(next != end) {
                    smatch match = *next;
                    int id = stoi(match[1]);
                    int lOffset = stoi(match[2]);
                    int tOffset = stoi(match[3]);
                    int width = stoi(match[4]);
                    int height = stoi(match[5]);
                    bool overlap{false};
                    for(int y = tOffset;y < tOffset + height;++y) {
                        for(int x = lOffset; x < lOffset + width;++x) {
                            auto p = to_string(x) + "," + to_string(y);
                            if(claims[p] != 1) {
                                overlap = true;
                            }
                        }
                    }
                    if(!overlap) {
                        return to_string(id);
                    }
                    ++next;
                }
            } catch (regex_error& e ) {
                //Syntax error in regex
                cout << "ERROR: " << e.what() << endl;
            }
        }
        
        return "---";
	}
    
    void parseClaim(const std::string& claim) {

    }

}
