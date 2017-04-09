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
	cout << endl;
}

int make_move(int A[6][7],int player)
{
	int choice;
	cout<<"Please choose a column, numbered from left to right, to place a piece:"<<endl;
	cin >> choice;
	choice--;
	if(A[0][choice] == 1)
	{
		cout << "That column is full: please choose another column:"<<endl;
		make_move(A,player);
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

