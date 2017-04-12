#include <iostream>
#include "connect4.h"
using namespace std;

int main()
{
	int A[6][7];
	string one,two;
	int check=1;
  bool win = false;

	for(int i=0;i<6;i++)
		for (int j=0;j<7;j++)
		{
			A[i][j]=0;
			
		}
	print_board(A);
	one = get_name(one);
	two = get_name2(two);
	while(!win)
	{
    if(!win)
    {
		  make_move(A,one,1);
	  	win = win_case(A,1,one);
    }
    if(!win)
    {		
    make_move(A,two,2);
		win = win_case(A,2,two);
    }
	}
	
	/*make_moveTwo(A,player);
	player++;
	make_moveTwo(A,player);
	player--;
	make_moveTwo(A,player);
	*/
	return 0;
}





