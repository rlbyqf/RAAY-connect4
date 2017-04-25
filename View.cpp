#include "View.h"
#include "View2.cpp"

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
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);	
	cout << endl<< player;
	ResetConsoleColour(Attributes);	
	cout << ", please choose a column, numbered from left to right, to place a piece: ";
	
	return player;
}

string printplayermessage2(string player)
{
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);	
	cout << endl<< player;
	ResetConsoleColour(Attributes);	
	cout << ", please choose a column, numbered from left to right, to place a piece: ";
	
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
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);	
	cout << endl<< player;
	ResetConsoleColour(Attributes);	
	cout << " wins!" << endl;
	return player;
}

string printwinner2(string player)
{
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);	
	cout << endl<< player;
	ResetConsoleColour(Attributes);	
	cout << " wins!" << endl;
	return player;
}

void printincorrectchoice()
{
	cout << "Please choose a column number between 1 and 7: " << endl;
}
