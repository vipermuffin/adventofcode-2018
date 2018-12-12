//
//  Advent of Code 2018 Solutions: Day 10
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/10/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include "LinearTraveler.h"

namespace AocDay10 {
//Function Definitions
    struct xyTraveler {
        xyTraveler(int xp, int yp, int xv, int yv) {
            x.setPosition(xp);
            x.setVelocityPerTimeStep(xv);
            y.setPosition(yp);
            y.setVelocityPerTimeStep(yv);
        }
        void step () {
            x.step();
            y.step();
        }
        AocUtils::LinearTraveler<int> x;
        AocUtils::LinearTraveler<int> y;
    };
    bool performStep(std::vector<xyTraveler>& v) ;
    void printXyTraveler(std::vector<xyTraveler>& v);
}
