#include "Contessa.hpp"
#include "Game.hpp"
#include "Assassin.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

namespace coup {

    Contessa::Contessa(Game &game, const string& name): Player(game, name){
        this->role_name = "Contessa";
    }

    void Contessa::block(Player &p){
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(p.getCurrAction() != "cup3"){
            throw runtime_error("cannot eliminate");
        }
        p.curr_action_player->setPlaying(true);
    }
}