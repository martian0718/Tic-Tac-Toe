/*
*   Author: Martin Wu
*   Date Created: August 14th, 2020
*   Date Modified: August 15th, 2020
*   Tictactoe Program using Object Orientated Concepts
*   Player.cpp File
*     Implementation of the Player Class
*/

#include "player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player() {name = "Player Two";}                   //no argument constructor
Player::Player(string n, char l) {
    name = n;
    letter = l;
}                      //name argument constructor
//getter method for name
string Player::getName() {
    return name;
}        
char Player::getLetter() {
    return letter;
}
//getter method for turn   
bool Player::getTurn() {
    return turn;
}        
//getter method for move
int Player::getMove() {
    cout << name << ", pick a number on the board: ";
    cin >> move_input;
    return move_input;
}      
//setter method for name       
void Player::setName(string n) {
    name = n;
}    
//setter method for turn
void Player::setTurn(bool t) {
    turn = t;
}      

