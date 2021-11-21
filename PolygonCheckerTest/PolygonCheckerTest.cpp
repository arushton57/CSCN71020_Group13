#include "pch.h"
#include "CppUnitTest.h"

#define TOTALDEGREES 180
extern "C" char* TriangleChecker(int side1, int side2, int side3);
extern "C" char* TriangleAngle(int side1, int side2, int side3);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleCheckerTest
{
	TEST_CLASS(TriangleCheckerTest)
	{
	public:
		
		// If anything other than an int is put into an int, it will return null.
		TEST_METHOD(TestNoTriangle_1)
		{
			char* intendedResult = "Not a triangle";
			char* result = TriangleChecker(7, NULL, 3);
			Assert::AreEqual(intendedResult, result);
		}
		// Also test if the user inputted 0
		TEST_METHOD(TestNoTriangle_2)
		{
			char* intendedResult = "Not a triangle";
			char* result = TriangleChecker(5, 14, 0);
			Assert::AreEqual(intendedResult, result);
		}
		// Or anything under that
		TEST_METHOD(TestNoTriangle_3)
		{
			char* intendedResult = "Not a triangle";
			char* result = TriangleChecker(-3, 2, 8);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestEquilateralTriangle_1)
		{
			char* intendedResult = "equilateral triangle";
			char* result = TriangleChecker(7, 7, 7);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestIsoscelesTriangle_1)
		{
			char* intendedResult = "isosceles triangle";
			char* result = TriangleChecker(8, 8, 3);
			Assert::AreEqual(intendedResult, result);
		}
		TEST_METHOD(TestIsoscelesTriangle_2)
		{
			char* intendedResult = "isosceles triangle";
			char* result = TriangleChecker(1, 5, 5);
			Assert::AreEqual(intendedResult, result);
		}
		TEST_METHOD(TestIsoscelesTriangle_3)
		{
			char* intendedResult = "isosceles triangle";
			char* result = TriangleChecker(66, 2, 66);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestScaleneTriangle_1)
		{
			char* intendedResult = "scalene triangle";
			char* result = TriangleChecker(1, 2, 3);
			Assert::AreEqual(intendedResult, result);
		}
		TEST_METHOD(TestScaleneTriangle_2)
		{
			char* intendedResult = "scalene triangle";
			char* result = TriangleChecker(6, 4, 2);
			Assert::AreEqual(intendedResult, result);
		}

	};

	TEST_CLASS(Angleformulatest)
	{
	public:


		TEST_METHOD(TestCorrectAngles)
		{
			int intendedResult = TOTALDEGREES;
			int result = TriangleAngle(1, 2, 3);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestTrianglewithZero)
		{
			char* intendedResult = "NotTriangle";
			char* result = TriangleAngle(1, 2, 0);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestIncorrectAngles)
		{
			int intendedResult = TOTALDEGREES;
			int result = TriangleAngle(4, 2, 2);
			Assert::AreNotEqual(intendedResult, result);
		}

	}
}
