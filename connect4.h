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

void print_board2(int A[6][9]);

void print_board3(int A[19][19]);

//ask for the user's choice of whether 2 players or CPU opponent
int player_mode(int mode);

string get_name(string &one);

string get_name2(string two);

int make_move(int A[6][7], string player, int check);

int make_move2(int A[6][9], string player, int check);  // connect 5

int make_move3(int A[19][19], string player, int check);    // connect 6

bool win_case(int board[6][7], int char_piece, string player); // standard connect 4 board is 6x7

int human_turn(int A[6][7],string player);

bool computer_turn(int A[6][7],string player);

int human_turn(int A[6][7],string player);

void showScoreboard(int board[6][4], string player[5]);

int showMatch(int A[6][7],string one, string two, int& oneWins, int& twoWins, int& games, bool win); // plays individual games in match and returns 1 or 2 depending on which player wins and a 3 for tie

bool fullboard(int A[6][7]);

bool fullboard2(int A[6][9]);

bool fullboard3(int A[19][19]);

void wincounter(int board[50],string playerwin, string playername[100],int matchtype);

#endif
