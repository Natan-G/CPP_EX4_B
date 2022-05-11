#include "Game.hpp"
#include "Assassin.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
const int cup_7 = 7;
const int cup_3 = 3;


namespace coup {
    Assassin::Assassin(Game &game, const string& name): Player(game,name){
        this->role_name = "Assassin";
    }

    void Assassin::coup(Player &p){
        if(this->game->turn() != this->name){
            throw runtime_error("its not ur turn");
        }
        if(!p.isPlaying()){
            throw runtime_error("this player are not playing!");
        }
        this->game->game_started=true;
        if(this->coin < cup_3){
            throw runtime_error("not enough coins!");
        }    
        if(this->coin >= cup_3 && this->coin < cup_7){
            this->setCurrAction("cup3");
            this->coin -= cup_3;
            p.setPlaying(false);
            this->curr_action_player=&p;
            this->game->next_turn();
            checkWinner();
        }
        else{
            this->curr_action="coup";
            this->coin-=cup_7;
            p.setPlaying(false);
            this->game->next_turn();
            checkWinner();
        }
}

}

