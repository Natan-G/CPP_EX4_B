#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace coup {

    Captain::Captain(Game &game, const string& name): Player(game,name){
        this->role_name="Captain";
    }
   
    void Captain::steal(Player &p) {
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(!p.isPlaying()){
            throw runtime_error("player is not playing!");
        }
        if(this->game->turn()!=this->name){
            throw runtime_error("this is not ur turn!");
        }
        //can steal 0/1/2
        if(p.getCoins() == 1){
            this->coin++;
            p.setCoins(-1);
        }
        if(p.getCoins() >= 2){
            this->coin+=2;
            p.setCoins(-2);
        }
        this->curr_action_player=&p;
        this->curr_action="steal";
        this->game->next_turn();
        
    }

    void Captain::block(Player &p){
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(!p.isPlaying()){
            throw runtime_error("player is not playing!");
        }
        if(p.getCurrAction() != "steal"){
            throw runtime_error("cannot steal");
        }
        p.setCoins(-2);
        p.curr_action_player->setCoins(-2);
    }
}