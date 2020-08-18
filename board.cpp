/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 17th, 2020
*   Tictactoe Program using Object Orientated Concepts
*   Board.cpp File
*     Implementation of the Board Class
*/
#include "board.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>


using namespace std;

Board::Board() {
    size = 3;
    r.resize(size);
    c.resize(size);
    d.resize(2);
    openSpot.resize(size*size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            openSpot[i*size + j] = true;
            game_board[i][j] = '0' + ((i*3)+j+1);
        }
        
    }
}                   //no argument constructor
bool Board::updateBoard(int move, char letter) {
    //check if spot is available
    int row = (int)ceil(move/double(size)) - 1;
    int col = (move-1) % 3;

    if(move >= 1 && move <= size*size && openSpot[move-1]) {
        game_board[row][col] = letter;
        openSpot[move-1] = false;
        return true;
    } else {
        cout << "Move is out of range or unavailable!" << endl;
        return false;
    }
}     //updates tictactoe board
void Board::displayBoard() {
    for(int i = 0; i < size; i++) {
        cout << "                   ";
        for(int j = 0; j < size; j++) {
            cout << game_board[i][j];
            if((j+1) % size != 0)  cout << "|";
        } 
        if(i==2)    break;
        cout << "\n";
        cout << "                   ";
        cout << "------" << endl;
    }
    cout << "\n";   
}            //displays current board
bool Board::isFilled() {
    for(int i = 0; i < openSpot.size(); i++) {
        if(openSpot[i]) return false;
    }
    return true;
}
bool Board::checkVictory(char letter, int move) {

    int row = (int)ceil(move/double(size)) - 1;
    int col = (move-1) % 3;
    if(letter == 'o') {
        r[row]--;
        c[col]--;
    } else {
        r[row]++;
        c[col]++;
    }
    
    if(row == col) {
        if(letter == 'o')   d[0]--;
        else                d[0]++;
        if(d[0] == size || d[0] == -1*size)    return true;
    } 
    if(row + col == size-1) {
        if(letter == 'o')   d[1]--;
        else                d[1]++;
        if(d[1] == size || d[1] == -1*size)    return true;
    }
    for(int i = 0; i < size; i++) {
        if(r[i] == size || c[i] == size)    return true;
        if(r[i] == -1*size || c[i] == -1*size)  return true;
    }
    return false;
}



        
