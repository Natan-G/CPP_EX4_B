#pragma once
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string.h>
using namespace std;

namespace coup {
    class Player;
    class Game {
        
        public:
            Game();
            unsigned long curr_turn;
            bool game_started;
            bool game_ended;
            string winner_name;
            vector<Player*> _players;
            
            string turn();
            vector<string>players();
            string winner();
            void next_turn();
            void addPlayer(Player* p);
            void checkWinner();
           
            
    };
}
