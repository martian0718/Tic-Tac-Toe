/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 17th, 2020
*   Tictactoe Program using Object Orientated Concepts
*   Board.h File
*     Declaration of the Board Class
*/
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

using namespace std;

class Board {
    private:
        int size;
        char game_board[3][3];
        vector<bool> openSpot;
        vector<int> r;
        vector<int> c;
        vector<int> d;
    public:
        Board();                   //no argument constructor
        bool updateBoard(int move, char letter);     //updates tictactoe board
        void displayBoard();            //displays current board
        bool isFilled();
        bool checkVictory(char letter, int move);
        
};

#endif