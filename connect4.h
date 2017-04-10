#include <iostream>
using namespace std;

int print_board(int A[6][7])
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

string get_name()
{
	string playerOne, playerTwo;
	
	cout << "Please enter Player 1's name: ";
	cin >> playerOne;
	cout << "Please enter Player 2's name: "; 
	cin >> playerTwo;
	
	return 0;
}


int make_moveOne(int A[6][7],int player)
{
	int choice;
	cout << playerOne << ", please choose a column, numbered from left to right, to place a piece:"<<endl;
	cin >> choice;
	choice--;
	if(A[0][choice] == 1)
	{
		cout << "That column is full: please choose another column:"<<endl;
		make_moveOne(A,player);
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


int make_moveTwo(int A[6][7],int player)
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
