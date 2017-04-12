#include "stdafx.h"
#include "CppUnitTest.h"
#include "connect4.h"
//#include "Controller.cpp"
#include "View.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConnect4
{
	TEST_CLASS(TestView)
	{
	public:

		TEST_METHOD(TestPrintPlayerMessage)
		{
			string player1 = "yang";
			Assert::AreEqual(player1, printplayermessage("yang"));
		}
		TEST_METHOD(TestPrintWinnner)
		{
			string player1 = "yang";
			Assert::AreEqual(player1, printwinner("yang"));
		}
	};
}