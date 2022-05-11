#pragma once
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace coup {
    
    class Player{
        protected:
            int coin;
            string name;
            string role_name;
            Game *game;
            string curr_action;
            

        public:
            Player(Game &game, const string& name);
            bool in_game;
            Player *curr_action_player;
            string last_action;

            string role();
            void income();
            void foreign_aid();
            void coup(Player &p);
            int coins() const;

            //getters abd setters
            string getName(){
                return this->name;
            }

            bool isPlaying(){
                return this->in_game;
            }
            void setPlaying(bool flag){
                this->in_game=flag;
            }
            string getRoleName(){
                return this->role_name;
            }
            int getCoins(){
                return this->coin;
            }
            void setCoins(int coins){
                this->coin += coins;
            }
            string getCurrAction(){
                return this->curr_action;
            }
            void setCurrAction(string action){
                this->curr_action = action;
            }
            void checkWinner();
    };
}