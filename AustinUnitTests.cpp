#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "connect4.cpp"
using namespace std;

void test_full_board_connect4()
{
	int A[6][7];
	
	// create a full board (no zeros)
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 7; j++)
		A[i][j] = 1;
	
	if(!(fullboard(A)))
		cout << "Test successful"<<endl;
	else 
		cout<<"Test Failed"<<endl;
}

void test_full_board_connect5()
{
	int A[6][9];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 9; j++)
			A[i][j] = 1;
	
	if(!(fullboard2(A)))
		cout << "Test successful"<<endl;
	else 
		cout<<"Test Failed"<<endl;
	
}

void connect5_win_horizontal()
{
	int A[6][9];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 9; j++)
			A[i][j] = 0;
			
	A[1][2] = 1;
	A[1][3] = 1;
	A[1][4] = 1;
	A[1][5] = 1;
	A[1][6] = 1;
	
	if(win_case2(A,1,"User"))
		cout << "Test successful" << endl;
	else
		cout<<"Test Failed"<<endl;
}

void connect5_win_vertical()
{
	int A[6][9];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 9; j++)
			A[i][j] = 0;
			
	A[4][1] = 1;
	A[4][2] = 1;
	A[4][3] = 1;
	A[4][4] = 1;
	A[4][5] = 1;
	
	if(win_case2(A,1,"User"))
		cout << "Test successful"<<endl;
	else
		cout<<"Test Failed"<<endl;
}

void connect5_win_diagonal_right()
{
	int A[6][9];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 9; j++)
			A[i][j] = 0;
			
	A[1][1] = 1;
	A[2][2] = 1;
	A[3][3] = 1;
	A[4][4] = 1;
	A[5][5] = 1;
	
	if((win_case2(A,1,"User")))
		cout << "Test successful"<<endl;
	else
		cout<<"Test Failed"<<endl;
}

void connect5_win_diagonal_left()
{
	int A[6][9];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 9; j++)
			A[i][j] = 0;
			
	A[1][5] = 1;
	A[2][4] = 1;
	A[3][3] = 1;
	A[4][2] = 1;
	A[5][1] = 1;
	
	if(win_case2(A,1,"User"))
		cout << "Test successful" << endl;
	else
		cout<< "Test Failed" << endl;
}

void test_full_board_connect6()
{
	int A[19][19];
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			A[i][j] = 1;
	
	if(!(fullboard3(A)))
	{
		cout << "Test successful" << endl;
	}
	else cout << "Test Failed" << endl;
}

void connect6_win_horizontal()
{
	int A[19][19];
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			A[i][j] = 0;
	
	A[9][3] = 1;
	A[9][4] = 1;
	A[9][5] = 1;
	A[9][6] = 1;
	A[9][7] = 1;
	A[9][8] = 1;
	
	if(win_case3(A,1,"User"))
		cout << "Test successful" << endl;
	else
		cout << "Test Failed" << endl;
}

void connect6_win_vertical()
{
	int A[19][19];
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			A[i][j] = 0;
	
	A[2][3] = 1;
	A[3][3] = 1;
	A[4][3] = 1;
	A[5][3] = 1;
	A[6][3] = 1;
	A[7][3] = 1;
	
	if(win_case3(A,1,"User"))
		cout << "Test successful" << endl;
	else
		cout << "Test Failed" << endl;
}

void connect6_win_diagonal_right()
{
	int A[19][19];
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			A[i][j] = 0;
	
	A[5][5] = 1;
	A[6][6] = 1;
	A[7][7] = 1;
	A[8][8] = 1;
	A[9][9] = 1;
	A[10][10] = 1;
	
	if(win_case3(A,1,"User"))
		cout << "Test successful" << endl;
	else
		cout << "Test Failed" << endl;
}

void connect6_win_diagonal_left()
{
	int A[19][19];
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			A[i][j] = 0;
	
	A[3][9] = 1;
	A[4][8] = 1;
	A[5][7] = 1;
	A[6][6] = 1;
	A[7][5] = 1;
	A[8][4] = 1;
	
	if(win_case3(A,1,"User"))
		cout << "Test successful" << endl;
	else
		cout << "Test Failed" << endl;
}

int main()
{
	test_full_board_connect4();
	test_full_board_connect5();
	connect5_win_horizontal();
	connect5_win_vertical();
	connect5_win_diagonal_right();
	connect5_win_diagonal_left();
	test_full_board_connect6();
	connect6_win_horizontal();
	connect6_win_vertical();
	connect6_win_diagonal_right();
	connect6_win_diagonal_left();
		
	return 0;
}
