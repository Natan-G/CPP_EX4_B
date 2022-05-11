#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

namespace coup {
    Game::Game(){
        this->curr_turn=0;
        this->game_started=false;
        this->game_ended=false;
        this->winner_name="";

    }

    string Game::turn(){
        if(this->_players.empty()){
            throw runtime_error("no players in the game!");
        }
        return this->_players.at(this->curr_turn % this->_players.size())->getName();
    }

    string Game::winner(){
        if(!this->game_ended){
            throw runtime_error("the game not over yet!");
        }
        int count=0;
        for(size_t i=0 ; i< this->_players.size() ; i++){
            if(this->_players.at(i)->isPlaying()){
                count++;
            }
        }
        if(count==1){
            for(size_t i=0 ; i <this->_players.size() ; i++){
                if(this->_players.at(i)->isPlaying()){
                    return this->_players.at(i)->getName();
                }
            }
        }
        throw runtime_error("still no winner!");
        
    }
    
    vector<string> Game:: players(){

        vector<string> players_names;
        for(size_t i=0; i < this->_players.size() ; i++){
            if(this->_players.at(i)->in_game){
                players_names.push_back(this->_players.at(i)->getName());
            }
        }
        return players_names;
    }

    void Game::next_turn(){
        this->curr_turn++;
        //while the next player is still in game 
        while(!(this->_players.at(this->curr_turn % this->_players.size())->isPlaying())){
            this->curr_turn++;
        }
    }

    void Game::addPlayer(Player *p){
        this->_players.push_back(p);
    }


}
