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
        int size;                                   //size of the board 
        char game_board[3][3];                      //the 2D Array to represent tictactoe
        vector<bool> openSpot;                      //to indicate which spots are open 
        vector<int> r;                              //to indicate how many x or o occupies each row
        vector<int> c;                              //to indicate how many x or o occupies each row
        vector<int> d;                              //to indicate how many x or o occupies each diagonal
    public:
        Board();                                    //no argument constructor
        bool updateBoard(int move, char letter);    //updates tictactoe board
        void displayBoard();                        //displays current board
        bool isFilled();                            //indicates if board is filled up 
        bool checkVictory(char letter, int move);   //indicates if someone has won or not 
        
};

#endif