/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 17th, 2020
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
        Player *p1;                         //Player One
        Player *p2;                         //Player Two
        Board *tictactoe;                   //Game contains a board 
        bool gameOver;                      //signifies if game is over 
    public:
        Game(Player *one, Player *two);     //2 argument constructor for Game class 
        bool getGameOver();                 //getter method for getting gameOver (may not need)
        void setGameOver(bool over);        //setter method for changing gameOver (may not need)
        void showGame();                    //display board game 
        int playerTurn(Player *p);          //allows for player to make move input and update game board
        void checkBoard(Player *p);         //checks the board to see if game is over 
        void start();                       //starts the game 
        ~Game();                            //destructor to free up memory space
};

#endif