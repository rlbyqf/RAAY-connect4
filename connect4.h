#ifndef CONNNECT4_H
#define CONNECT4_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "Controller.h"

using namespace std;

//welcome fucntion
void showWelcome();

//Menu Function
void showMenu();

//print the initial board
void print_board(int A[6][7]);

//ask for the user's choice of whether 2 players or CPU opponent
int player_mode(int mode);

string get_name(string &one);

string get_name2(string two);

int make_move(int A[6][7], string player, int check);

bool win_case(int board[6][7], int char_piece, string player); // standard connect 4 board is 6x7

int human_turn(int A[6][7],string player);

bool computer_turn(int A[6][7],string player);

int human_turn(int A[6][7],string player);

int showMatch(int A[6][7],string one, string two, int& oneWins, int& twoWins, int& games, bool win); // plays individual games in match and returns 1 or 2 depending on which player wins and a 3 for tie

bool fullboard(int A[6][7]);
#endif
