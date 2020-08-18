/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 15th, 2020
*   Tictactoe Program using Object Orientated Concepts
*   Game.h File
*     Declaration of the Game Class
*/

#ifndef GAME_H
#define GAME_H 

#include "player.h"
#include "board.h"
#include <string>

using namespace std;

class Game {
    private:
        Player *p1;
        Player *p2;
        Board *tictactoe;
        bool gameOver;
    public:
        Game(Player *one, Player *two);
        bool getGameOver();
        void setGameOver(bool over);
        void showGame();
        int playerTurn(Player *p);
        void start();
        ~Game();
};

#endif