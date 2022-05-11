#pragma once
#include "Player.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace coup {
    class Duke: public Player{
    public:
        Duke(Game &game, const string& name);
        void tax();
        void block(Player &p);
        
    };
}