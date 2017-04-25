#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
using namespace std;

int command(int x);
string sendstringmessage(string player,int A[6][7],int check);
string sendstringmessage(string player,int A[6][9],int check);
string sendstringmessage(string player,int A[19][19],int check);
string sendwinner(string);

#endif
