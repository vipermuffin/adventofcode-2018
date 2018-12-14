//
//  Advent of Code 2018 Solutions: Day 13
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/13/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay13 {
//Function Definitions
    enum class INTERSECTION_TURN {LEFT, STRAIGHT, RIGHT};
    enum class DIRECTION{NORTH, EAST, SOUTH, WEST};
    
    class Cart {
    public:
        Cart(char dir, int initX, int initY);
        Cart();
        void step();
        void updateDirection(const char);
        int x;
        int y;
        bool isCrashed;
        bool operator <(const Cart& rhs) const;
        bool operator ==(const Cart& rhs) const;
        
    private:
        INTERSECTION_TURN nextTurn;
        DIRECTION currentDirection;
    };
    
    void findCarts(std::vector<std::string>& input, std::vector<Cart>& v);
    bool stepCarts(const std::vector<std::string>& paths, std::vector<Cart>& carts, bool keepGoing = false);
}
