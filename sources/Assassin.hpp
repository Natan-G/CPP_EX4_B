#pragma once
#include "Player.hpp"
using namespace std;

namespace coup {
    class Assassin: public Player {
    public:
        Assassin(Game &game, const string& name);
        void coup(Player &p);
    };
}