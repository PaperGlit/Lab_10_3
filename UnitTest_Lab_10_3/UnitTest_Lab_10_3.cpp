#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_3/Lab_10_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab103
{
	TEST_CLASS(UnitTestLab103)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char filename[255] = "TestRoutes.txt";
			char search[100] = "Test";
			string searchres = "Test - Dest (15)\n";
			string searchres1 = ProcessTXT(filename, search);
			int result = searchres.compare(searchres1);
			Assert::AreEqual(result, 0);
		}
	};
}
