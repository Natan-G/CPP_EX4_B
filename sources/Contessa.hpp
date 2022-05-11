#pragma once
#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace coup {
    class Contessa: public Player {
    public:
        Contessa(Game &game, const string& name);
        void block(Player &p);
       
    };
}