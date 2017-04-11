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

string get_name(string one, string two)
{	
	cout << "Please enter Player 1's name: ";
	cin >> one;
	cout << "Please enter Player 2's name: "; 
	cin >> two;
	
	return one,two;
}



int make_move(int A[6][7],string player,int check)
{
	int choice;
	cout << player << ", please choose a column, numbered from left to right, to place a piece:"<<endl;
	cin >> choice;
	choice--;
	if(A[0][choice] == 1)
	{
		cout << "That column is full: please choose another column:"<<endl;
		make_move(A,player,check);
	}
	else 
	{
		for(int i=5;i>0;i--)
		{
			if(A[i][choice]==0)
			{
				A[i][choice]=check;
				if(check==1)
					check++;
				if(check==2)
					check--;
				cout << "The move was successful!"<<endl;
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


bool win_case(int board[6][7], int char_piece, string player)
{
	bool winCase = false;
//6 row 7 column

// horizontal win
	for(int row = 0; row < 6; row++)
	{
		for(int col = 0; col < 4; col++)
		{
			if(board[row][col] == char_piece && board[row][col+1] == char_piece && board[row][col+2] == char_piece && board[row][col+3] == char_piece)
			{
				cout << player << " wins!" << endl;
				winCase = true;
			}
		}
	}
	
// vertical win
	for(int col = 0; col < 7; col++)
	{
		for(int row = 0; row < 3; row++)
		{
			if(board[row][col] == char_piece && board[row+1][col] == char_piece && board[row+2][col] == char_piece && board[row+3][col] == char_piece)
			{
				cout << player << " wins!" << endl;
				winCase = true;
			}
		}
	}
	
// diagonal win 
	for(int col = 0; col < 4; col++)
	{
		for(int row = 0; row < 3; row--)
		{
			if(board[row][col] == char_piece && board[row+1][col+1] == char_piece && board[row+2][col+2] == char_piece && board[row+3][col+3] == char_piece)
			{
				cout << player << " wins!" << endl;
				winCase = true;
			}
		}
	}

// diagonal win
	for(int col = 6; col > 2; col--)
	{
		for(int row = 5; row > 2; row--)
		{
			if(board[row][col] == char_piece && board[row-1][col-1] == char_piece && board[row-2][col-2] == char_piece && board[row-3][col-3] == char_piece)
			{
				cout << player << " wins!" << endl;
				winCase = true;
			}
		}
	}
	
	return winCase;
}
