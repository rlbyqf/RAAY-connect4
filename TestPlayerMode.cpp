#include "CppUnitTest.h"
#include "connect4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConnect4
{
	TEST_CLASS(TestConnect4H)
	{
	public:

		TEST_METHOD(TestPlayerMode)
		{
			int actual_value = 1;
			Assert::AreEqual(actual_value, player_mode(1));
		}
	};
}