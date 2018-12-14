//
//  Advent of Code 2018 Solutions: Day 13
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/13/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort
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
//#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay13 {

	static const std::string InputFileName = "Day13.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<Cart> carts{};
        findCarts(input, carts);
        while(!stepCarts(input, carts));
        auto itr = carts.begin();
        while(itr != carts.end() && !itr->isCrashed) {
            ++itr;
        }
		return to_string(itr->x) + "," + to_string(itr->y);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<Cart> carts{};
        findCarts(input, carts);
        while(!stepCarts(input, carts,true));
        stepCarts(input, carts);
        return to_string(carts[0].x) + "," + to_string(carts[0].y);
	}

    Cart::Cart(char dir, int initX, int initY) {
        x = initX;
        y = initY;
        nextTurn = INTERSECTION_TURN::LEFT;
        isCrashed = false;
        switch (dir) {
            case '>':
                currentDirection = DIRECTION::EAST;
                break;
                
            case '<':
                currentDirection = DIRECTION::WEST;
                break;
                
            case '^':
                currentDirection = DIRECTION::NORTH;
                break;
                
            case 'v':
                currentDirection = DIRECTION::SOUTH;
                break;
                
            default:
                currentDirection = DIRECTION::NORTH;
                break;
        }
    }
    
    Cart::Cart() {
        x = 0;
        y = 0;
        currentDirection = DIRECTION::NORTH;
        nextTurn = INTERSECTION_TURN::LEFT;
        isCrashed = false;
    }
    
    void Cart::step() {
        switch(currentDirection) {
            case DIRECTION::NORTH:
                --y;
                break;
            case DIRECTION::SOUTH:
                ++y;
                break;
            case DIRECTION::EAST:
                ++x;
                break;
            case DIRECTION::WEST:
                --x;
                break;
        }
    }
    
    void Cart::updateDirection(const char dir) {
        switch (dir) {
            case '/':
                switch(currentDirection) {
                    case DIRECTION::NORTH:
                        currentDirection = DIRECTION::EAST;
                        break;
                    case DIRECTION::SOUTH:
                        currentDirection = DIRECTION::WEST;
                        break;
                    case DIRECTION::EAST:
                        currentDirection = DIRECTION::NORTH;
                        break;
                    case DIRECTION::WEST:
                        currentDirection = DIRECTION::SOUTH;
                        break;
                }
                break;
                
            case '\\':
                switch(currentDirection) {
                    case DIRECTION::NORTH:
                        currentDirection = DIRECTION::WEST;
                        break;
                    case DIRECTION::SOUTH:
                        currentDirection = DIRECTION::EAST;
                        break;
                    case DIRECTION::EAST:
                        currentDirection = DIRECTION::SOUTH;
                        break;
                    case DIRECTION::WEST:
                        currentDirection = DIRECTION::NORTH;
                        break;
                }
                break;
                
            case '+':
                switch(nextTurn) {
                    case INTERSECTION_TURN::LEFT:
                        switch(currentDirection) {
                            case DIRECTION::NORTH:
                                currentDirection = DIRECTION::WEST;
                                break;
                            case DIRECTION::SOUTH:
                                currentDirection = DIRECTION::EAST;
                                break;
                            case DIRECTION::EAST:
                                currentDirection = DIRECTION::NORTH;
                                break;
                            case DIRECTION::WEST:
                                currentDirection = DIRECTION::SOUTH;
                                break;
                        }
                        nextTurn = INTERSECTION_TURN::STRAIGHT;
                        break;
                    
                    case INTERSECTION_TURN::STRAIGHT:
                        nextTurn = INTERSECTION_TURN::RIGHT;
                        break;
                        
                    case INTERSECTION_TURN::RIGHT:
                        switch(currentDirection) {
                            case DIRECTION::NORTH:
                                currentDirection = DIRECTION::EAST;
                                break;
                            case DIRECTION::SOUTH:
                                currentDirection = DIRECTION::WEST;
                                break;
                            case DIRECTION::EAST:
                                currentDirection = DIRECTION::SOUTH;
                                break;
                            case DIRECTION::WEST:
                                currentDirection = DIRECTION::NORTH;
                                break;
                        }
                        nextTurn = INTERSECTION_TURN::LEFT;
                        break;
                }
                break;
                
            default:
                break;
        }
    }
    bool Cart::operator <(const Cart& rhs) const{
        if(y < rhs.y) {
            return true;
        } else {
            if(x < rhs.x) {
                return true;
            }
        }
        return false;
    }
    
    bool Cart::operator ==(const Cart& rhs) const{
        return x == rhs.x && y== rhs.y;
    }
    
    void findCarts(std::vector<std::string>& input, std::vector<Cart>& v) {
        for(int y = 0; y < input.size();++y) {
            for(int x = 0; x < input[y].size(); ++x) {
                auto c = input[y][x];
                switch (c) {
                    case '>':
                    case '<':
                        v.emplace_back(c,x,y);
                        input[y][x] = '-';
                        break;
                    case '^':
                    case 'v':
                        v.emplace_back(c,x,y);
                        input[y][x] = '|';
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    bool stepCarts(const std::vector<std::string>& paths, std::vector<Cart>& carts, bool keepGoing) {
        unordered_map<int,Cart*> seen;
        sort(carts.begin(),carts.end());
        for(auto& cart : carts) {
            if(!cart.isCrashed) {
                auto coordId = cart.x+(cart.y*512);
                if(seen[coordId] != nullptr) {
                    //Crash
                    
                } else {
                    cart.step();
                    cart.updateDirection(paths[cart.y][cart.x]);
                    coordId = cart.x+(cart.y*512);
                }
                
                if(seen[coordId] != nullptr) {
                    seen[coordId]->isCrashed = true;
                    cart.isCrashed = true;
                    if(keepGoing) {
                        seen[coordId] = nullptr;
                    } else {
                        return true;
                    }
                } else {
                    seen[coordId] = &cart;
                }
            }
        }
        //Remove crashed
        auto itr = carts.begin();
        while(itr != carts.end()) {
            if(itr->isCrashed) {
                carts.erase(itr);
                itr = carts.begin();
            } else {
                ++itr;
            }
        }
        return carts.size() == 1;
    }
}
