#include "CppUnitTest.h"
#include "Controller.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConnect4
{
	TEST_CLASS(TestController)
	{
	public:
		TEST_METHOD(TestCommand)
		{
			int x = 4;
			Assert::AreEqual(x, command(4));
		}
		TEST_METHOD(TestSendStringMessage)
		{
			string c = "yang";
			Assert::AreEqual(c, sendstringmessage("yang"));
		}
		TEST_METHOD(TestSendWinner)
		{
			string player = "yang";
			Assert::AreEqual(player, sendwinner("yang"));
		}
	};
}