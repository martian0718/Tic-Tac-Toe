/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 15th, 2020
*   Tictactoe Program using Object Orientated Concepts
*   Player.h File
*     Declaration of the Player Class
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector> 

using namespace std;

class Player {
    private:
        string name;
        bool turn;
        int move_input;
        char letter;
    public:
        Player();                   //no argument constructor
        Player(string n, char l);           //name argument constructor
        string getName();           //getter method for name
        char getLetter();           //getter method for letter
        bool getTurn();             //getter method for turn
        int getMove();              //getter method for move
        void setName(string n);     //setter method for name
        void setTurn(bool t);       //setter method for turn
};

#endif