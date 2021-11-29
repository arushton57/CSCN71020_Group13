#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/PolygonChecker.c"

#define TOTALDEGREES 180

extern "C" char* TriangleChecker(int side1, int side2, int side3);
extern "C" int TriangleAngle(int side1, int side2, int side3);
extern "C" bool RectangleChecker(int *rectangleSides[8]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerEnvironment
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

		TEST_METHOD(TestEquilateral_1)
		{
			char* intendedResult = "equilateral triangle";
			char* result = TriangleChecker(7, 7, 7);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestIsosceles_1)
		{
			char* intendedResult = "isosceles triangle";
			char* result = TriangleChecker(8, 8, 3);
			Assert::AreEqual(intendedResult, result);
		}
		TEST_METHOD(TestIsosceles_2)
		{
			char* intendedResult = "isosceles triangle";
			char* result = TriangleChecker(1, 5, 5);
			Assert::AreEqual(intendedResult, result);
		}
		TEST_METHOD(TestIsosceles_3)
		{
			char* intendedResult = "isosceles triangle";
			char* result = TriangleChecker(66, 2, 66);
			Assert::AreEqual(intendedResult, result);
		}

		TEST_METHOD(TestScalene_1)
		{
			char* intendedResult = "scalene triangle";
			char* result = TriangleChecker(1, 2, 3);
			Assert::AreEqual(intendedResult, result);
		}
		TEST_METHOD(TestScalene_2)
		{
			char* intendedResult = "scalene triangle";
			char* result = TriangleChecker(6, 4, 2);
			Assert::AreEqual(intendedResult, result);
		}
	};

	TEST_CLASS(Angleformulatest)
	{
	public:


		
		TEST_METHOD(TestIncorrectAngle)
		{
			//Arrange
			int angle1 = 45;
			int angle2 = 45;
			int angle3 = 90;
			int actual = TriangleAngle(3,1,sqrt(2));

			//Act
			

			//Assert
			Assert::AreNotEqual(angle1, actual);
		}
		

		TEST_METHOD(TestTriangleAngle1)
		{
			//Arrange
			int angle1 = 45;
			int angle2 = 45;
			int angle3 = 90;
			int actual = TriangleAngle(1,1,sqrt(2));

			//Assert
			Assert::AreEqual(angle1, actual);
		}

		TEST_METHOD(TestTriangleAngle2)
		{
			//Arrange
			int angle1 = 30;
			int angle2 = 60;
			int angle3 = 90;
			int actual = TriangleAngle(sqrt(3), 1, 2);

			//Assert
			Assert::AreEqual(angle2, actual);
		}

		TEST_METHOD(TestIncorrectAngle2)
		{
			//Arrange
			int angle1 = 70;
			int angle2 = 45;
			int angle3 = 90;
			int actual = TriangleAngle(4, 6, 12);

			//Assert
			Assert::AreNotEqual(angle1, actual);
		}

		TEST_METHOD(TestEquilateralTriangle)
		{
			//Arrange
			int angle1 = 60;
			int angle2 = 60;
			int angle3 = 60;
			int actual = TriangleAngle(3, 3, 3);

			//Assert
			Assert::AreEqual(angle1, actual);
		}

	};


	TEST_CLASS(RectangleChecker) {
		public

			//Will be using proper coordinates to create a regular rectangle. Should past the first test in the function
			TEST_METHOD(TestProperRectangle)
		{
			bool result;
			rectangleSides[8] = { 0,0,0,4,6,4,6,0 };
			
			result = RectangleChecker(rectangleSides[8]);


			Assert::AreEqual(true,result);
		}

		//Will be testing the third test method in the function where it checks for the length of the diagonal lines
		TEST_METHOD(TestParallelogram)
		{
			bool result;
			rectangleSides[8] = { 0,0,7,5,16,5,9,0 };

			result = RectangleChecker(rectangleSides[8]);


			Assert::AreEqual(false, result);
		}

		//This test should fail. Should fail at the first test in the function
		TEST_METHOD(TestRandomCoordinates)
		{
			bool result;
			rectangleSides[8] = { 1,3,7,8,8,9,3,1 };

			result = RectangleChecker(rectangleSides[8]);


			Assert::AreEqual(false, result);
		}

		//Will be going through all test and should succeed. 
		TEST_METHOD(TestSlantedRectangle)
		{
			bool result;
			rectangleSides[8] = { -6,3,0,6,2,2,-4,1 };

			result = RectangleChecker(rectangleSides[8]);


			Assert::AreEqual(true, result);
		}


	};
}
