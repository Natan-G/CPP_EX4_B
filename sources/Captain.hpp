#pragma once
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace coup {
    class Captain: public Player {
    public:
        Captain(Game &game, const string& name);
        void steal (Player &p);
        void block(Player &p);
    };
}