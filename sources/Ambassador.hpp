#pragma once
#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace coup {
    class Ambassador: public Player {
        public:
            Ambassador(Game &game ,const string& name);
            void transfer(Player &p1 , Player &p2);
            void block(Player &p);
    };
}