#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "PolygonChecker.h"
#define RADIAN_DEGREES 57.2958
#define TOTALDEGREES 180
int rectangleSides[8];


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

		/* Setting in coordinates for each point for the rectangle function
		printf("\nPlease note that the order will be like so." 
		"\nPoint 1 will be the point that is the closest to the origin."
		"\nPoint 2 will be the point that will be vertically above point 1."
		"\nPoint 3 will be the point that will be to the right of point 2."
		"\nPoint 4 will be the point that will be vertically below point 3."
		);
		printf("\nFor the coordinates please enter values equal to or larger than 0. ");
		
		//Collecting points for the rectangle through a for loop 
		for (int i = 0; i < 8; i++)
		{
			//The count variable is purely asthetic so that the user knows what point they're 
			//putting coordinates in for
			count = (2 + i) / 2;
			printf("\nPlease enter in the x coordinate for point %i:", count);
			scanf_s("%d", &rectangleSides[i]);

			//Input validation through a while loop for the x-coordinate
			while (rectangleSides[i] < 0)
			{
				printf("\nThat is an invalid input. Please enter another input for the x coordinate:");
				scanf_s("%d", &rectangleSides[i]);
			}


			printf("\nPlease enter in the y coordinate for point %i:", count);
			scanf_s("%d", &rectangleSides[i + 1]);

			//Input validation through a while loop for the y-coordinate
			while (rectangleSides[i + 1] < 0)
			{
				printf("\nThat is an invalid input. Please enter another input for the y coordinate:");
				scanf_s("%d", &rectangleSides[i + 1]);
			}
			i = i + 1;
		}
		
		*/


		//The code below will not be usable 
		 
		
		// Executes the values typed to check if the rectangle lines intersect
		//RectangleChecker(rectangleSides[0], rectangleSides[1], rectangleSides[2], rectangleSides[3]);

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



void RectangleChecker(int* rectangleSides[8]) {
	
	
	
	

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
