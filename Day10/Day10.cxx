//
//  Advent of Code 2018 Solutions: Day 10
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/10/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort
#include <climits>

using namespace std;
using namespace AocUtils;
namespace AocDay10 {


	static const std::string InputFileName = "Day10.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<xyTraveler> ltv;
        int maxY{INT_MIN};
        for(const auto& line: input) {
            int xp,yp,xv,yv;
            sscanf(line.c_str(),"position=<%d, %d> velocity=< %d,  %d>",&xp,&yp,&xv,&yv);
            ltv.emplace_back(xp,yp,xv,yv);
            if(yp > maxY) {
                maxY = yp;
            }
        }
        
        for(int i = 1;i < maxY;++i) {
            if(performStep(ltv) ) {
                printXyTraveler(ltv);
                cout << "Time: " << i;
            }
        }
		return "---";
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return "---";
	}

    bool performStep(vector<xyTraveler>& v) {
        vector<int> vals;
        for(auto& lt : v) {
            lt.step();
            vals.push_back(lt.y.position());
        }
        auto m = minmax_element(vals.begin(), vals.end());
        
        return (*m.second - *m.first) <= 10;
    }
    
    void printXyTraveler(vector<xyTraveler>& v) {
        vector<int> xs;
        vector<int> ys;
        for(const auto& lt : v) {
            xs.push_back(lt.x.position());
            ys.push_back(lt.y.position());
        }
        auto m = minmax_element(xs.begin(), xs.end());
        auto xOffset = *m.first;
        auto width = *m.second - *m.first + 1;
        m = minmax_element(ys.begin(), ys.end());
        auto yOffset = *m.first;
        auto height = *m.second - *m.first;
        
        string blanks(width,' ');
        vector<string> output;
        for(int i = 0;i <= height;++i) {
            output.push_back(blanks);
        }
        
        for(const auto& lt : v) {
            output[lt.y.position()-yOffset][lt.x.position()-xOffset] = '#';
        }
        
        cout << "----Stars----" << endl;
        for(const auto& line : output) {
            cout << line << endl;
        }
    }
}
