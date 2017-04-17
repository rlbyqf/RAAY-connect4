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

string sendstringmessage(string player)
{
	printplayermessage(player);
	return player;
}

string sendwinner(string player)
{
	printwinner(player);
	return player;
}


