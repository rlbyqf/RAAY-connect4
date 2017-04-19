#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "connect4.h"
using namespace std;

void AIHorizontalTest1(int A[6][7])
{
	if(A[5][3]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
	
}

void AIVerticalTest1(int A[6][7])
{

	if(A[2][0]==2)
	{
		cout << "Test successful"<<endl;
		
	}
	else cout<<"Test Failed"<<endl;
	
}

int main()
{
		int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
		A[i][j]=0;
	
	//A[5][0]=1;
	//A[5][1]=1;
	//A[5][2]=1;
	//A[4][0]=1;
	//A[3][0]=1;
	
	print_board(A);
	human_turn(A,"Ryan");
	AIHorizontalTest1(A);
	AIVerticalTest1(A);
	return 0;
}
