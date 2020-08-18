/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 17th, 2020
*   Tictactoe Program using Object Orientated Concepts
*   Game.cpp File
*     Implementation of the Game Class
*/

#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Game::Game(Player *one, Player *two) {
    p1 = one;
    p2 = two;
    tictactoe = new Board();
}
bool Game::getGameOver() {
    return gameOver;
}
void Game::setGameOver(bool over) {
    gameOver = over;
}
//displays board game from game class 
void Game::showGame() {
    tictactoe->displayBoard();
}
int Game:: playerTurn(Player *p) {
    int position = p->getMove();
     if(tictactoe->updateBoard(position, p->getLetter())) {
        cout << "Move successful" << endl;
        return position;
    } else 
        return playerTurn(p);         
}
//function to check board to see if there is a winner or the board is filled 
void Game::checkBoard(Player *p) {
    int position = playerTurn(p);
    if(tictactoe->checkVictory(p->getLetter(), position)) {
        gameOver = true;
        cout <<  p->getName() << " is victorious" << endl;
    }
    if(tictactoe->isFilled() && !gameOver) {
        cout << "Game Over, no one wins" << endl;
        gameOver = true;
    }
    tictactoe->displayBoard();
}
void Game::start() {
    p1->setTurn(true);  //player one will always go first
    while(!gameOver) {
        if(p1->getTurn()) {
            p1->setTurn(false);
            checkBoard(p1);
        } else {
            p1->setTurn(true);
            checkBoard(p2);
        }
    }
}
//destructor to free up memory space 
Game::~Game() {
    delete p1;
    delete p2;
    delete tictactoe;
}