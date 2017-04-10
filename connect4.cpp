#include <iostream>
#include "connect4.h"
using namespace std;

int main()
{
	int A[6][7];
	int player=1;
	
	for(int i=0;i<6;i++)
		for (int j=0;j<7;j++)
		{
			A[i][j]=0;
			//cout << A[i][j]<<endl;
		}
	print_board(A);
	get_name();
	make_moveOne(A,player);
	player++;
	make_moveOne(A,player);
	player--;
	make_moveOne(A,player);
	make_moveTwo(A,player);
	player++;
	make_moveTwo(A,player);
	player--;
	make_moveTwo(A,player);
	
	return 0;
}





