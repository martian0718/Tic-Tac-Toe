/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 17th, 2020
*   TicTacToe Program using Object Orientated Concepts
*   Main.cpp File
*   2 Players has been implemented, 1 player is yet to be implemented
*/


#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "game.h"
#include "player.h"


using namespace std;

void startApp(int answer, vector<Player*> &players);

int main() {
    //starts the TicTacToe App
    vector<Player*> players; 
    int answer = 0;

    cout << "===========TIC-TAC-TOE=============" << "\n";
    cout << "Two Player or One Player Tic Tac Toe? (2 or 1)" << "\n";
    cin >> answer;

    if(answer > 2 || answer < 1)  return 0;

    startApp(answer, players);
    if(answer == 2) {
        Game *g = new Game(players[0], players[1]);
        g->showGame();
        g->start();
    }
}

void startApp(int answer, vector<Player*> &players) {
    string name;
    char letter;
    for(int i = 1; i <= answer; i++) {
        cout << "Player " << i << " Name: ";
        cin >> name;
        if(i == 1)  letter = 'x';
        else        letter = 'o';
        Player *p = new Player(name, letter);
        players.push_back(p);
    }
}