#include "Ambassador.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

namespace coup {
    Ambassador::Ambassador(Game &game, const string& name): Player(game,name) {
        this->role_name = "Ambassador";
    }
    //transfer 1 coins from 1 player to other
    void Ambassador::transfer(Player &p1 , Player &p2){
        //all checks
        if(!this->in_game){
            throw runtime_error("you are not playing");
        }
        if(!p1.isPlaying() || !p2.isPlaying()){
            throw runtime_error("players are not playing");
        }
        if( p1.getCoins()==0){
            throw runtime_error("cannot transfer , player have 0 coins!");
        }

        this->game->game_started=true;
        this->game->next_turn();
        this->setCurrAction("transfer");
        p2.setCoins(1);
        p1.setCoins(-1);
    }

    //block captain steal, doesn't "waste" turn!
    void Ambassador::block(Player &p){
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(!p.isPlaying()){
            throw runtime_error("this player didnt play anymore!");
        }
        if(p.getCurrAction() !="steal"){
            throw invalid_argument("cant block!");
        }

        p.setCoins(-2);//player return 2 coins
        p.curr_action_player->setCoins(2);
    }

}
