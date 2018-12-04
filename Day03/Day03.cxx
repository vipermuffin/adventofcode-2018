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
#include <regex>



using namespace std;
namespace AocDay03 {
    
    //Used to reduce parsing twice in part 2
    std::unordered_map<uint32_t, int>& getInputMapRef(const std::vector<std::string>& input);
    
	static const std::string InputFileName = "Day03.txt";
    static const std::regex re{"#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"};
    const int Xi = 0;
    const int Yi = 1;
    union {
        uint16_t pairs[2];
        uint32_t val;
    } tmp;
    
    
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        const auto& claims = getInputMapRef(input);
        
		return to_string(getSqFtOverlap(claims));
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto& claims = getInputMapRef(input);
        
        return to_string(getIdNoOverlap(claims, input));
	}
    
    std::unordered_map<uint32_t, int> getInputMap(const std::vector<std::string>& input) {
        unordered_map<uint32_t, int> claims;
        if(claims.size() != 0)
            return claims;
        string claim;
        for(const auto& claim : input) {
            try {
                sregex_iterator next{claim.begin(),claim.end(),re};
                sregex_iterator end;
                while(next != end) {
                    smatch match = *next;
                    int lOffset = stoi(match[2]);
                    int tOffset = stoi(match[3]);
                    int width = stoi(match[4]);
                    int height = stoi(match[5]);
                    for(int y = tOffset;y < tOffset + height;++y) {
                        for(int x = lOffset; x < lOffset + width;++x) {
                            tmp.pairs[Xi] = x;
                            tmp.pairs[Yi] = y;
                            ++claims[tmp.val];
                        }
                    }
                    ++next;
                }
            } catch (regex_error& e ) {
                //Syntax error in regex
                cout << "ERROR: " << e.what() << endl;
            }
        }
        return claims;
    }

    std::unordered_map<uint32_t, int>& getInputMapRef(const std::vector<std::string>& input) {
        static unordered_map<uint32_t, int> claims;
        static int inputSize{0};
        if(claims.size() != 0 && inputSize == input.size())
            return claims;
        inputSize = input.size();
        claims.clear();
        claims = getInputMap(input);
        return claims;
    }
    
    int getSqFtOverlap(const std::unordered_map<uint32_t, int>& claims) {
        int sqFt{0};
        for(const auto& kvp : claims) {
            if(kvp.second >= 2) {
                ++sqFt;
            }
        }
        return sqFt;
    }
    
    int getIdNoOverlap(std::unordered_map<uint32_t, int>&claims, const std::vector<string>& input) {
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
                            tmp.pairs[Xi] = x;
                            tmp.pairs[Yi] = y;
                            if(claims[tmp.val] != 1) {
                                overlap = true;
                                break;
                            }
                        }
                        if(overlap)
                            break;
                    }
                    if(!overlap) {
                        return id;
                    }
                    ++next;
                }
            } catch (regex_error& e ) {
                //Syntax error in regex
                cout << "ERROR: " << e.what() << endl;
            }
        }
        return -1;
    }
}
