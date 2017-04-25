#include "View.h"

int command(int x)
{
	if (x == 1)
		printplayerone();
	if (x == 2)
		printplayertwo();
	if (x == 3)
		printfullmessage();
	if (x == 4)
		printsuccessfullmove();
	if (x == 5)
		printincorrectchoice();
	return x;
}

string sendstringmessage(string player,int A[6][7],int check)
{
	if(check==1)
	{
	printplayermessage(player);
	}
	if(check==2)
	{
		printplayermessage2(player);
	}
	return player;
}

string sendwinner(int board[6][7], int char_piece, string player)
{
	if(char_piece==1)
	{
	    printwinner(player);
	}
	if(char_piece==2)
	{
		printwinner2(player);
	}
	return player;
}


