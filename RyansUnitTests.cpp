#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "connect4.cpp"
using namespace std;

/*
These tests are to be used one at a time. 
Also, they won't work unless you comment out the main() function in
connect4.cpp.
The reason for such a strange set up is because I couldn't get 
Visual Studio to accept any unit tests.
This includes the well written, properly working unit tests written by Nina.
I am sorry for the confusion and hope that the below tests are thorough enough.
-Ryan Bay
*/

void AIHorizontalTest1() //prevent opponent's horizontal win
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

void AIVerticalTest1()//prevent opponent's vertacal win
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

void AIDiagnalRightTest1()//prevents opponent's "diagnal right" win
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

void AIDiagnalLeftTest1() //prevents opponent's "diagnal left" win
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

void AIHolesTest1() //prevents player from winning based on holes
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
			
	A[5][0]=1;
	A[5][2]=1;
	computer_turn(A,"player");
	if(A[5][1]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;

}
AILeft2Test1() //tests left-of-group placement
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
			
	A[5][1]=2;
	A[5][2]=1;
	A[4][1]=1;
	computer_turn(A,"player");
	if(A[5][0]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
}

AIRight2Test1() //tests right-of-group placement
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
			
	A[5][1]=2;
	A[5][0]=1;
	A[4][1]=1;
	computer_turn(A,"player");
	if(A[5][2]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
}

AITop2Test1() //tests vertical placement
{
	int A[6][7];
	for(int i=0;i<6;i++)
		for(int j=0;j<7;j++)
			A[i][j]=0;
			
	A[5][1]=2;
	A[5][0]=1;
	A[5][2]=1;
	computer_turn(A,"player");
	if(A[4][1]==2)
	{
		cout << "Test successful"<<endl;
	}
	else cout<<"Test Failed"<<endl;
}

int main()
{
	//AIHorizontalTest1();
	//AIVerticalTest1();
	//AIDiagnalRightTest1();
	//AIDiagnalLeftTest1();
	//AIHolesTest1();
	//AILeft2Test1();
	//AIRight2Test1();
	AITop2Test1();
	return 0;
}
