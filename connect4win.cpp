#include <iostream>

using namespace std;

bool win_case(char board[6][7], char char_piece, string player)
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
