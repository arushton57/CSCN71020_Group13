#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "PolygonChecker.h"
#define RADIAN_DEGREES 57.2958
#define TOTALDEGREES 180


void main()
{
	// Main (including this welcome message) executes only once
	printf_s("\n **********************\n**     Welcome to     **\n**   Polygon Checker  **\n **********************\n\n");

	// The real program starts
	PrintFunctions();
}

// Is a looping function
void PrintFunctions()
{
	printf("To choose a function, enter its letter label:\na) Check triangle\nb) Check rectangle\nc) Quit\n");

	// Takes in char inputs a, b, and c
	char input = '.';
	while (input != 'a' && input != 'b' && input != 'c')
	{
		scanf_s(" %c", &input, 1);
		// If multiple values are ever entered, the buffer is cleared to prevent variables from inappropriately outputting
		while (getchar() != '\n'); 
		// Warn the user if a bad input is entered
		if (input != 'a' && input != 'b' && input != 'c')
			printf("Inappropriate input!\n");
	}

	// Once a true input has been typed, execute it
	switch (input)
	{
	case 'a':
		printf("\nTriangle selected.\n");

		// Primatively collected variables. When using loops, I got an index-out-of-range error from index 11 and 15?
		int triangleSides[3] = { 0, 0, 0 };
		printf("Enter the first side of the triangle: ");
		scanf_s("%d", &triangleSides[0]);
		printf("Enter the second side of the triangle: ");
		scanf_s("%d", &triangleSides[1]);
		printf("Enter the third side of the triangle: ");
		scanf_s("%d", &triangleSides[2]);

		// Executes the values typed to check what kind of triangle it is
		TriangleChecker(triangleSides[0], triangleSides[1], triangleSides[2]);

		break;

	case 'b':
		printf("\nRectangle selected.\n");

		int rectangleSides[4] = { 0, 0, 0, 0 };
		printf("Enter the first side of the rectangle: ");
		scanf_s("%d", &rectangleSides[0]);
		printf("Enter the second side of the rectangle: ");
		scanf_s("%d", &rectangleSides[1]);
		printf("Enter the third side of the rectangle: ");
		scanf_s("%d", &rectangleSides[2]);
		printf("Enter the fourth side of the rectangle: ");
		scanf_s("%d", &rectangleSides[3]);

		// Executes the values typed to check if the rectangle lines intersect
		RectangleChecker(rectangleSides[0], rectangleSides[1], rectangleSides[2], rectangleSides[3]);

		break;

	case 'c':
		// This is self explanitory.
		printf("\nQuit selected. Exiting program...\n");
	}
}

// Takes in 3 integers to check what kind of triangle it creates
void TriangleChecker(int side1, int side2, int side3)
{
	// Prepares a result
	char* result = "";
	// If the integer could not recieve the input value, or if any input value is equal to 0, clear the buffer. We don't want these variables to output prematurely
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		while (getchar() != '\n');
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}
	triangleAngle(side1, side2, side3);
	// Print the result, and start the program again
	printf_s("%s\n\n", result);
	PrintFunctions();
}

void RectangleChecker(int side1, int side2, int side3, int side4)
{

	PrintFunctions();
}

void triangleAngle(int side1, int side2, int side3)
{
	double angle1, angle2, angle3;
	//angle returned in radians due to acos
	//1 radian = 57.2958
	angle1 = RADIAN_DEGREES * acos((double)(side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3));//angle formula using radians
	angle2 = RADIAN_DEGREES * acos((double)(side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1 * side3));
	//3rd angle found using total degrees
	angle3 = TOTALDEGREES - (angle1 + angle2);
}
