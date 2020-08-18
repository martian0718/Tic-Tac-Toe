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
void Game::start() {
    int position = 0;
    p1->setTurn(true);  //player one will always go first
    while(!gameOver) {
        if(p1->getTurn()) {
            position = playerTurn(p1);
            p1->setTurn(false);
            if(tictactoe->checkVictory(p1->getLetter(), position)) {
                gameOver = true;
                cout <<  p1->getName() << " is victorious" << endl;
            }
            if(tictactoe->isFilled() && !gameOver) {
                cout << "Game Over, no one wins" << endl;
                gameOver = true;
            }
            tictactoe->displayBoard();
        } else {
            position = playerTurn(p2);
            p1->setTurn(true);
            if(tictactoe->checkVictory(p2->getLetter(), position)) {
                gameOver = true;
                cout << p2->getName() << " is victorious" << endl;
            }
            if(tictactoe->isFilled() && !gameOver) {
                cout << "Game Over, no one wins" << endl;
                gameOver = true;
            }
            tictactoe->displayBoard();
        }
    }
}

Game::~Game() {
    delete p1;
    delete p2;
    delete tictactoe;
}