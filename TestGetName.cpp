#include "CppUnitTest.h"
#include "connect4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestConnect4
{
	TEST_CLASS(TestConnect4H)
	{
	public:

		TEST_METHOD(TestGetName)
		{
			string actual_value = "Nina";
			string one;
			get_name(one);
			Assert::AreEqual(actual_value, one);
		}

	};
}