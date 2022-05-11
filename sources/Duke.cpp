#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
namespace coup {

    Duke::Duke(Game &game, const string& name): Player(game, name){
        this->role_name="Duke";
    }
 
    void Duke::tax(){
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(this->game->turn()!=this->name){
            throw runtime_error("not your turn!");
        }
        this->game->game_started=true;
        this->game->next_turn();
        this->setCurrAction("tax");
        this->coin+=3;
    }

    void Duke::block(Player &p){
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(p.getCurrAction() != "foreign_aid"){
            throw runtime_error("canntot block!");
        }
        p.setCoins(-2);
        this->curr_action = "block";

    }

}