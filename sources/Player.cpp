#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int max_players = 6;
const int cup_cost = 7;
const int max_coins = 10;

namespace coup {
    //constructor
    Player::Player(Game &game, const string &name) {
        this->game = &game;
        this->name = name;
        this->coin = 0;
        this->curr_action="";
        this->curr_action_player=NULL;
        
        //all checks
        if(this->game->game_started){
            throw runtime_error("game alerdy started!");
        }
        if(this->game->_players.size()>= max_players){
            throw runtime_error("too many players , maximum 6 players!");
        }
        this->game->addPlayer(this);
        this->in_game=true;

    }

    void Player::income() {
        //all checks
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("this is not ur turn!");
        }
        if(this->game->_players.size()==1){
            throw runtime_error("the game is over!");
        }

        this->game->game_started=true;
        this->game->next_turn();
        this->curr_action="income";
        this->coin++;
        
    }

    void Player::foreign_aid(){
        //all checks
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("this is not ur turn!");
        }
        if(this->game->_players.size()==1){
            throw runtime_error("the game is over!");
        }
        if(this->coin >= max_coins){
            throw runtime_error("player must coup!");
        }
        this->game->game_started=true;
        this->game->next_turn();
        this->curr_action="foreign_aid";
        this->coin+=2;
    }

    void Player::coup(Player &p) {
        //all checks
        if(!this->in_game){
            throw runtime_error("you are not playing!");
        }
        if(!p.isPlaying()){
            throw runtime_error("this player is no more playing!");
        }
        if(this->game->turn()!= this->name){
            throw runtime_error("this is not ur turn!");
        }
        if((this->coin) < cup_cost){
            throw runtime_error("cup cost 7 coins!");
        }
        this->game->game_started=true;
        
        this->coin-=cup_cost; //coup cost 7 coins

        p.setPlaying(false);//not playing anymore

        this->curr_action="coup";
        this->game->next_turn();
        checkWinner();
        
    }

    int Player::coins()const {
        return this->coin;
    }
    
    string Player::role(){
        return this->role_name;
    }
    
    void Player::checkWinner(){
        int count=0;
        for(size_t i = 0; i < this->game->_players.size(); i++){
            if(this->game->_players.at(i)->isPlaying()){
                count++;
            }
        }
        if(count == 1){
            this->game->game_ended = true;
        }   
    }
    


}