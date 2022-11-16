#include "pch.h"
#include "CppUnitTest.h"
#include "../laba7.1(2)/laba7.1(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest712
{
	TEST_CLASS(UnitTest712)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int s[1] = { 1 };
			int** r = new int* [5];
			for (int i = 0; i < 5; i++)
				r[i] = new int[5];
			Create(r, 5, 5, 1, 1, 0, 0);
			int t = r[1][1];
			Assert::AreEqual(t, 1);

		}
	};
}
