#include <iostream>
#include "connect4.h"
using namespace std;

int main()
{
	int A[6][7];
	string one,two;
	int check=1;
	
	for(int i=0;i<6;i++)
		for (int j=0;j<7;j++)
		{
			A[i][j]=0;
			//cout << A[i][j]<<endl;
		}
	print_board(A);
	get_name(one,two);
	
	
	while(1)
	{
		make_move(A,one,1);
		//win_case(A,1,one);
		make_move(A,two,2);
		//win_case(A,2,two);
	}
	
	/*make_moveTwo(A,player);
	player++;
	make_moveTwo(A,player);
	player--;
	make_moveTwo(A,player);
	*/
	return 0;
}





