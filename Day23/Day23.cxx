//
//  Advent of Code 2018 Solutions: Day 23
//
//  https://adventofcode.com/2018
//
//  Created by vipermuffin on 12/22/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>


using namespace std;

namespace std{
    namespace
    {
        
        // Code from boost
        // Reciprocal of the golden ratio helps spread entropy
        //     and handles duplicates.
        // See Mike Seymour in magic-numbers-in-boosthash-combine:
        //     https://stackoverflow.com/questions/4948780
        
        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        
        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
            static void apply(size_t& seed, Tuple const& tuple)
            {
                HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
                hash_combine(seed, get<Index>(tuple));
            }
        };
        
        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
            static void apply(size_t& seed, Tuple const& tuple)
            {
                hash_combine(seed, get<0>(tuple));
            }
        };
    }
    
    template <typename ... TT>
    struct hash<std::tuple<TT...>>
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {
            size_t seed = 0;
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);
            return seed;
        }
        
    };
}

namespace AocDay23 {

	static const std::string InputFileName = "Day23.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int x,y,z,r;
        vector<NanoBot> bots;
        for(const auto& line : input) {
            sscanf(line.c_str(),"pos=<%d,%d,%d>, r=%d",&x,&y,&z,&r);
            bots.emplace_back(x,y,z,r);
        }
        
        auto itr = bots.begin();
        auto maxB = itr;
        int maxR = INT_MIN;
        while(itr != bots.end()) {
            if(itr->signal > maxR) {
                maxR = itr->signal;
                maxB = itr;
            }
            ++itr;
        }
        int count = 0;
        itr = bots.begin();
        while(itr != bots.end()) {
            if(maxB->getDistance(*itr) <= maxR) {
                ++count;
            }
            ++itr;
        }
		return to_string(count);
	}

	std::string solveb() {
        //136914684 and 159771329 is too low
        auto input = parseFileForLines(InputFileName);
        return performB3(input);
	}
    
    std::string performB(const std::vector<std::string>& input) {
        int x,y,z,r;
        int maxX,minX,maxY,minY,maxZ,minZ;
        maxX = maxY = maxZ = INT_MIN;
        minX = minY = minZ = INT_MAX;
        vector<NanoBot> bots;
        for(const auto& line : input) {
            sscanf(line.c_str(),"pos=<%d,%d,%d>, r=%d",&x,&y,&z,&r);
            bots.emplace_back(x,y,z,r);
            if(x > maxX) {
                maxX = x;
            } else if (x < minX) {
                minX = x;
            }
            if(y > maxY) {
                maxY = y;
            } else if (y < minY) {
                minY = y;
            }
            if(z > maxZ) {
                maxZ = z;
            } else if (z < minZ) {
                minZ = z;
            }
        }
        
        unordered_map<string, int> m;
        int numDp{0};
        for(x = minX; x <= maxX;++x) {
            for(y = minY; y <= maxY; ++y) {
                for(z = minZ;z <= maxZ;++z) {
                    auto key = to_string(x)+","+to_string(y)+","+to_string(z);
                    NanoBot n{x,y,z,0};
                    for(const auto& nb : bots) {
                        if(nb.getDistance(n) <= nb.signal) {
                            ++m[key];
                        }
                    }
                    ++numDp;
                }
            }
        }
        
        int maxNode = INT_MIN;
        auto itrKvp = m.begin();
        auto maxItrNode = itrKvp;
        while(itrKvp != m.end()) {
            if(itrKvp->second > maxNode) {
                maxNode = itrKvp->second;
                maxItrNode = itrKvp;
//                cout << "NumPoints:" << to_string(itrKvp->second) << "-->" << itrKvp->first << endl;
            }
            
            ++itrKvp;
        }

        vector<NanoBot> most;
        for(const auto& kvp : m) {
            if(kvp.second == maxNode) {
                sscanf(kvp.first.c_str(), "%d,%d,%d",&x,&y,&z);
                most.emplace_back(x,y,z,0);
            }
        }
        NanoBot origin{0,0,0,0};
        int minNode = INT_MAX;
        auto itr = most.begin();
        auto finalItr = itr;
        while(itr != most.end()) {
            auto d = itr->getDistance(origin);
            if(d < minNode) {
                minNode = d;
                finalItr = itr;
            }
            ++itr;
        }

        return to_string(origin.getDistance(*finalItr));
    }
    
    std::string performB2(const std::vector<std::string>& input) {
        int x,y,z,r;
        int maxX,minX,maxY,minY,maxZ,minZ;
        maxX = maxY = maxZ = INT_MIN;
        minX = minY = minZ = INT_MAX;
        vector<NanoBot> bots;
        for(const auto& line : input) {
            sscanf(line.c_str(),"pos=<%d,%d,%d>, r=%d",&x,&y,&z,&r);
            bots.emplace_back(x,y,z,r);
            if(x > maxX) {
                maxX = x;
            } else if (x < minX) {
                minX = x;
            }
            if(y > maxY) {
                maxY = y;
            } else if (y < minY) {
                minY = y;
            }
            if(z > maxZ) {
                maxZ = z;
            } else if (z < minZ) {
                minZ = z;
            }
        }
        
        unordered_map<tuple<int,int,int>, int> m;
        int numDp{0};
        for(x = minX; x <= maxX;++x) {
            for(y = minY; y <= maxY; ++y) {
                for(z = minZ;z <= maxZ;++z) {
                    auto key = make_tuple(x,y,z);
                    NanoBot n{x,y,z,0};
                    for(const auto& nb : bots) {
                        if(nb.getDistance(n) <= nb.signal) {
                            ++m[key];
                        }
                    }
                    ++numDp;
                }
            }
        }
        
        int maxNode = INT_MIN;
        auto itrKvp = m.begin();
        auto maxItrNode = itrKvp;
        while(itrKvp != m.end()) {
            if(itrKvp->second > maxNode) {
                maxNode = itrKvp->second;
                maxItrNode = itrKvp;
                //                cout << "NumPoints:" << to_string(itrKvp->second) << "-->" << itrKvp->first << endl;
            }
            
            ++itrKvp;
        }
        
        vector<NanoBot> most;
        for(const auto& kvp : m) {
            if(kvp.second == maxNode) {
                auto t = kvp.first;
                x = get<0>(t);
                y = get<1>(t);
                z = get<2>(t);
                most.emplace_back(x,y,z,0);
            }
        }
        NanoBot origin{0,0,0,0};
        int minNode = INT_MAX;
        auto itr = most.begin();
        auto finalItr = itr;
        while(itr != most.end()) {
            auto d = itr->getDistance(origin);
            if(d < minNode) {
                minNode = d;
                finalItr = itr;
            }
            ++itr;
        }
        
        return to_string(origin.getDistance(*finalItr));
    }
    
    std::string performB3(const std::vector<std::string>& input) {
        int x,y,z,r;
        int maxX,minX,maxY,minY,maxZ,minZ;
        maxX = maxY = maxZ = INT_MIN;
        minX = minY = minZ = INT_MAX;
        vector<NanoBot> bots;
        for(const auto& line : input) {
            sscanf(line.c_str(),"pos=<%d,%d,%d>, r=%d",&x,&y,&z,&r);
            bots.emplace_back(x,y,z,r);
            int mX,mY,mZ;
            mX = x;
            mY = y;
            mZ = z;
            if(mX > maxX) {
                maxX = mX;
            } else if (mX < minX) {
                minX = mX;
            }
            if(mY > maxY) {
                maxY = mY;
            } else if (mY < minY) {
                minY = mY;
            }
            if(mZ > maxZ) {
                maxZ = mZ;
            } else if (mZ < minZ) {
                minZ = mZ;
            }
        }
        
        unordered_map<tuple<int,int,int>, int> m;
        int step = 2;
        while (step > 1) {
            m.clear();
            step = (maxX - minX)/10;
            if(step <= 1) {
                step = 1;
            }
            for(x = minX; x <= maxX;x+=step) {
                for(y = minY; y <= maxY; y+=step) {
                    for(z = minZ;z <= maxZ;z+=step) {
                        auto key = make_tuple(x,y,z);
                        NanoBot n{x,y,z,0};
                        for(const auto& nb : bots) {
                            if(nb.getDistance(n) <= nb.signal) {
                                ++m[key];
                            }
                        }
                    }
                }
            }
            int maxNode = INT_MIN;
            auto itrKvp = m.begin();
            auto maxItrNode = itrKvp;
            while(itrKvp != m.end()) {
                if(itrKvp->second > maxNode) {
                    maxNode = itrKvp->second;
                    maxItrNode = itrKvp;
                    //                cout << "NumPoints:" << to_string(itrKvp->second) << "-->" << itrKvp->first << endl;
                }
                
                ++itrKvp;
            }
            auto t = maxItrNode->first;
            minX = get<0>(t)-step;
            maxX = get<0>(t)+step;
            minY = get<1>(t)-step;
            maxY = get<1>(t)+step;
            minZ = get<2>(t)-step;
            maxZ = get<2>(t)+step;
        }
        
        
        int maxNode = INT_MIN;
        auto itrKvp = m.begin();
        auto maxItrNode = itrKvp;
        while(itrKvp != m.end()) {
            if(itrKvp->second > maxNode) {
                maxNode = itrKvp->second;
                maxItrNode = itrKvp;
                //                cout << "NumPoints:" << to_string(itrKvp->second) << "-->" << itrKvp->first << endl;
            }
            
            ++itrKvp;
        }
        
        vector<NanoBot> most;
        for(const auto& kvp : m) {
            if(kvp.second == maxNode) {
                auto t = kvp.first;
                x = get<0>(t);
                y = get<1>(t);
                z = get<2>(t);
                most.emplace_back(x,y,z,0);
            }
        }
        NanoBot origin{0,0,0,0};
        int minNode = INT_MAX;
        auto itr = most.begin();
        auto finalItr = itr;
        while(itr != most.end()) {
            auto d = itr->getDistance(origin);
            if(d < minNode) {
                minNode = d;
                finalItr = itr;
            }
            ++itr;
        }
        
        return to_string(origin.getDistance(*finalItr));
    }

    NanoBot::NanoBot(int X, int Y, int Z, int r) {
        x = X;
        y = Y;
        z = Z;
        signal = r;
    }
    
    int NanoBot::getDistance(const NanoBot &rhs) const{
        return abs(x-rhs.x)+abs(y-rhs.y)+abs(z-rhs.z);
    }
}
