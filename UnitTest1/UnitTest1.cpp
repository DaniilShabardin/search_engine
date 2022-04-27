#include "pch.h"
#include "CppUnitTest.h"
#include"../search_engine/class.h"
#include"../search_engine/libraries.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(1 == 1, L"ОШИБКА!");
			Logger::WriteMessage("Всем привет");
		}
	};
}
