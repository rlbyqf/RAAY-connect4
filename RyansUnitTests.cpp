#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "connect4.cpp"
using namespace std;

void AIHorizontalTest1()
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
		A[i][j]=0;
	
	A[5][0]=1;
	A[5][1]=1;
	A[5][2]=1;
	computer_turn(A,"player");
	if(A[5][3]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
}

void AIVerticalTest1()
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
	
	A[5][0]=1;
	A[4][0]=1;
	A[3][0]=1;
	computer_turn(A,"player");
	if(A[2][0]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
	
}

void AIDiagnalRightTest1()
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
			
	A[5][0]=1;
	A[4][1]=1;
	A[3][2]=1;
	A[3][3]=1;
	computer_turn(A,"player");
	if(A[2][3]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
}

void AIDiagnalLeftTest1()
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
			
	A[5][3]=1;
	A[4][2]=1;
	A[3][1]=1;
	A[3][0]=1;
	computer_turn(A,"player");
	if(A[2][0]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
}

int main()
{
	AIHorizontalTest1();
	//AIVerticalTest1();
	//AIDiagnalRightTest1();
	//AIDiagnalLeftTest1();
	return 0;
}
