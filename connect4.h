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

void print_board(int A[6][7]);

int player_mode(int mode);

string get_name(string &one);

string get_name2(string two);

int make_move(int A[6][7], string player, int check);

bool win_case(int board[6][7], int char_piece, string player); // standard connect 4 board is 6x7

#endif