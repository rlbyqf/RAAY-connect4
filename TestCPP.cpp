#include "CppUnitTest.h"
#include "connect4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConnect4
{		
	TEST_CLASS(TestConnect4CPP)
	{
	public:
		
		TEST_METHOD(TestWinCase1)
		{
			//test win case 1- horizontal win
			//int i = 6, j = 7;
			int A[6][7] = { 
				{ 0,0,0,0,0,0,0 },
				{ 0,0,0,0,0,0,0 },
				{ 0,0,0,0,0,0,0 },
				{ 2,0,0,0,0,0,0 },
				{ 2,0,0,0,0,0,0 },
				{ 2,1,1,1,1,0,0 }};
			bool b = 1;
			Assert::AreEqual(b, win_case(A,1,"yang"));
		}
		TEST_METHOD(TestWinCase2)
		{
			//test win case 2- vertical win
			//int i = 6, j = 7;
			int A[6][7] = {
				{ 0,0,0,0,0,0,0 },
				{ 0,0,0,0,0,0,0 },
				{ 0,1,0,0,0,0,0 },
				{ 0,1,2,0,0,0,0 },
				{ 0,1,2,0,0,0,0 },
				{ 0,1,2,0,0,0,0 } };
			bool b = 1;
			Assert::AreEqual(b, win_case(A, 1, "yang"));
		}
		TEST_METHOD(TestWinCase3)
		{
			//test win case 3- dialognal win
			//int i = 6, j = 7;
			int A[6][7] = {
				{ 0,0,0,0,0,0,0 },
				{ 0,0,0,0,0,0,0 },
				{ 2,0,0,0,0,0,0 },
				{ 1,2,0,0,0,0,0 },
				{ 2,2,2,0,0,0,0 },
				{ 1,1,1,2,1,1,0 } };
			bool b = 1;
			Assert::AreEqual(b, win_case(A, 2, "yang"));
		}
		TEST_METHOD(TestWinCase4)
		{
			//test win case 1- dialognal win
			//int i = 6, j = 7;
			int A[6][7] = {
				{ 0,0,0,0,0,0,0 },
				{ 0,0,0,0,0,0,0 },
				{ 0,1,0,1,0,0,0 },
				{ 0,2,1,0,0,0,0 },
				{ 0,1,2,2,0,0,0 },
				{ 1,2,1,0,0,0,0 } };
			bool b = 1;
			Assert::AreEqual(b, win_case(A, 1, "yang"));
		}
	};
}