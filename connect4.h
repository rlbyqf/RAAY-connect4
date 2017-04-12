#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
using namespace std;



void print_board(int A[6][7])
{
	for(int i=0;i<6;i++)
	{
		cout <<endl;
		for(int j=0;j<7;j++)
		{
			cout << A[i][j]<<" ";
		}
	}
	cout << endl << endl;
}

string get_name(string& one)
{	
	
	command(1);
	cin >> one;
	return one;
}

string get_name2(string two)
{
	command(2);
	cin >> two;
	return two;

}


int make_move(int A[6][7],string player,int check)
{
	int choice;
	sendstringmessage(player);
	cin >> choice;
	choice--;
	
	if(A[0][choice] !=0)
	{
		
		command(3);
		make_move(A,player,check);
		return 0;
	}
	if(choice > 6 || choice < 0)
	{
		command(5);
		make_move(A,player,check);
		return 0;
	}
	if(choice == 8)
		{
			command(5);
			make_move(A,player,check);
			return 0;
		}
	else 
	{
		for(int i = 5; i >= 0;i--)
		{
			if(A[i][choice]==0)
			{
				A[i][choice]=check;
				if(check==1)
					check++;
				if(check==2)
					check--;
				
				command(4);
				print_board(A);
				
				return check;
			}
		}
	}
	return 0;
}



/*int make_moveTwo(int A[6][7],int player)
{
	int choice;
	cout << playerTwo << ", please choose a column, numbered from left to right, to place a piece:"<<endl;
	cin >> choice;
	choice--;
	if(A[0][choice] == 1)
	{
		cout << "That column is full: please choose another column:"<<endl;
		make_moveTwo(A,player);
	}
	else 
	{
		for(int i=5;i>0;i--)
		{
			if(A[i][choice]==0)
			{
				A[i][choice]=player;
				cout << "The move was successful!"<<endl;
				print_board(A);
				return player;
			}
		}
	}
	return 0;
}
*/

bool win_case(int board[6][7], int char_piece, string player) // standard connect 4 board is 6x7
{
	bool winCase = false;
//6 row 7 column

// horizontal win
if(!winCase)
	for(int row = 0; row <= 5; row++)
	{
		for(int col = 0; col <=3; col++)
		{
			if(board[row][col] == char_piece && board[row][col+1] == char_piece && board[row][col+2] == char_piece && board[row][col+3] == char_piece)
			{

				sendwinner(player);

			

				winCase = true;
			}
		}
	}

if(!winCase)
// vertical win
	for(int col = 0; col <= 6; col++)
	{
		for(int row = 0; row <= 2; row++)
		{
			if(board[row][col] == char_piece && board[row+1][col] == char_piece && board[row+2][col] == char_piece && board[row+3][col] == char_piece)
			{
				sendwinner(player);
			
				winCase = true;
			}
		}
	}

if(!winCase)
// diagonal win 
	for(int col = 0; col <= 3; col++)
	{
		for(int row = 0; row <= 2; row++)
		{
			if(board[row][col] == char_piece && board[row+1][col+1] == char_piece && board[row+2][col+2] == char_piece && board[row+3][col+3] == char_piece)
			{
				sendwinner(player);
				
				winCase = true;
			}
		}
	}

if(!winCase)
// diagonal win
	for(int col = 6; col >= 3; col--)
	{
		for(int row = 0; row <= 2; row++)
		{
			if(board[row][col] == char_piece && board[row+1][col-1] == char_piece && board[row+2][col-2] == char_piece && board[row+3][col-3] == char_piece)
			{
				sendwinner(player);
				
				winCase = true;
			}
		}
	}
	
	// return true if there is a winning case
	return winCase;
}
