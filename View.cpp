#include "View.h"

void printplayerone()
{
	cout <<endl<< "Please enter Player 1's name: ";
}

void printplayertwo()
{
	cout << "Please enter Player 2's name: ";
}

string printplayermessage(string player)
{
	cout << endl<< player << ", please choose a column, numbered from left to right, to place a piece: ";
	return player;
}

void printfullmessage()
{
	cout << "That column is full: please choose another column:" << endl;
}

void printsuccessfullmove()
{
	cout << "The move was successful!" << endl;
}

string printwinner(string player)
{
	cout << player << " wins!" << endl;
	return player;
}

void printincorrectchoice()
{
	cout << "Please choose a column number between 1 and 7: " << endl;
}
