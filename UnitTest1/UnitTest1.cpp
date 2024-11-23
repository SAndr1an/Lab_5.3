#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.3/Lab_5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double kp = 0;
			double kk = 0.5;
			int n = 5;
			double dk = ( kk - kp) / n;
			double k = kp;

			double expected[] =
			{
				-0.2393596777,
				-0.2947202502,
				-0.3137888667,
				-0.2953115211,
				-0.2356663417,	
				-0.1286474288
			};

			for (int i = 0; i <= n; ++i) 
			{
				double result = j(1 + k + j(k)) + (k * k) * (1 + pow(k, 2));
				Assert::AreEqual(expected[i], result, 0.0001);
				k += dk;
			}
		}
	};
}
