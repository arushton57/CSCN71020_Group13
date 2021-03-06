#include "PolygonChecker.h"

void main()
{
	// Main (including this welcome message) executes only once
	printf_s("\n **********************\n**     Welcome to     **\n**   Polygon Checker  **\n **********************\n\n");

	// The real program starts
	PrintFunctions();
}


void PrintFunctions()
{
	bool stopMenu = false;

	while (!stopMenu)
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
			while (getchar() != '\n'); // Clear the buffer in case a non numerical was typed and not put into int triangleSides[]

			printf("Enter the second side of the triangle: ");
			scanf_s("%d", &triangleSides[1]);
			while (getchar() != '\n');

			printf("Enter the third side of the triangle: ");
			scanf_s("%d", &triangleSides[2]);
			while (getchar() != '\n');

			// Executes the values typed to check what kind of triangle it is
			TriangleChecker(triangleSides[0], triangleSides[1], triangleSides[2]);
			break;

		case 'b':
			printf("\nRectangle selected.\n");

			int count;
			int rectangleSides[8];

			// Setting in coordinates for each point for the rectangle function
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
				/*The count variable is purely asthetic so that the user knows what point they're
				putting coordinates in for*/
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

			// Executes the values typed to check if the rectangle lines intersect
			RectangleChecker(rectangleSides);
			break;

		case 'c':
			// This is self explanitory.
			stopMenu = true;
			printf("\nQuit selected. Exiting program...\n");
		}
	}
}

// Takes in 3 integers to check what kind of triangle it creates
char* TriangleChecker(int side1, int side2, int side3)
{
	char* result;
	// Prepares a result
	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
		result = "Not a triangle";
	else if (side1 == side2 && side1 == side3)
		result = "equilateral triangle";
	else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2) || (side2 == side3 && side1 != side2))
		result = "isosceles triangle";
	else
		result = "scalene triangle";

	// Print the result, and starts the program again
	if (result != "Not a triangle")
	{
		printf("The angles of the %s are: ", result);
		TriangleAngle(side1, side2, side3);
	}
	else
	{
		printf("%s", result);
	}

	printf_s("\n\n");
	return result;
}

bool RectangleChecker(int rectangleSides[])
{
	// This will be used to hold the lengths of each of the sides of the shape
	double sideLengthHolders[4];
	double total = 0;
	double diagonalLine0;
	double diagonalLine1;
	double angle;
	bool forward = true;

	//Length from p1 ===> p2
	sideLengthHolders[0] = (double)sqrt((pow((rectangleSides[2] - rectangleSides[0]), 2)) + (pow((rectangleSides[3] - rectangleSides[1]), 2)));
	//Length from p2 ===> p3
	sideLengthHolders[1] = (double)sqrt((pow((rectangleSides[4] - rectangleSides[2]), 2)) + (pow((rectangleSides[5] - rectangleSides[3]), 2)));
	//Length from p3 ===> p4
	sideLengthHolders[2] = (double)sqrt((pow((rectangleSides[6] - rectangleSides[4]), 2)) + (pow((rectangleSides[7] - rectangleSides[5]), 2)));
	//Length from p4 ===> p1
	sideLengthHolders[3] = (double)sqrt((pow((rectangleSides[0] - rectangleSides[6]), 2)) + (pow((rectangleSides[1] - rectangleSides[7]), 2)));

	//simple for loop to add together the lengths
	for (int i = 0; i < 4; i++)
	{
		total = total + sideLengthHolders[i];
	}
	printf("\nThe total perimeter of this shape is %f", total);


	// This is to check if the opposide sides of the shape are the same length.

	if (sideLengthHolders[0] == sideLengthHolders[2] && sideLengthHolders[1] == sideLengthHolders[3])
	{
	}

	else {
		printf("\nOpposite sides are not equal.");
		printf("\nThis is not a rectangle.");
		forward = false;
	}


	//This is for checking if the x and y coordinates match in making a rectangle.
	if (forward)
	{

		if (rectangleSides[0] == rectangleSides [2] && rectangleSides [1] == rectangleSides [7] && rectangleSides[3] == rectangleSides [5] && rectangleSides [4] == rectangleSides [6])
		{
			printf("\nThis is a rectangle. Calcuating Area now. ");
			total = sideLengthHolders[0] * sideLengthHolders[1];
			printf("\nThe area of this rectangle is %.2f.", total);
		}

		//Failing the above test means that this rectangle could possible be on an angle.
		else
		{
			printf("\nCertain coordinates are not matching. Running though one last test. ");
			
			
			//Creates a diagonal line from point 1 to point 3 and finds the length of the line
			diagonalLine0 = (double) sqrt ( (pow (rectangleSides [4] - rectangleSides [0],2)) + (pow ( rectangleSides [5] - rectangleSides [1], 2 )) );

			//Creates a diagonal line from point 2 to point 4 and finds the length of the line
			diagonalLine1 = (double) sqrt ( (pow (rectangleSides [6] - rectangleSides[2], 2)) + (pow ( rectangleSides [7] - rectangleSides [3], 2 )) );


			if (diagonalLine0 == diagonalLine1)
			{
				printf("\nThis is a rectangle. Calcuating Area now. ");
				total = sideLengthHolders[0] * sideLengthHolders[1];
				printf("\nThe area of this rectangle is %.2f.\n\n", total);
			}

			else {
				printf("\nOpposite sides are not equal.\n\n");
				printf("\nThis is not a rectangle.\n\n");
				forward = false;
			}


		}
	}
	
	else {
		printf("\nThis is not a rectangle.");
		forward = false;
	}
	return forward;
	PrintFunctions();
}


void TriangleAngle(int side1, int side2, int side3)
{
	double angle1, angle2, angle3;

	// Angle formula using radians. Angle returned in radians due to acos. 1 radian is default to: 57.2958
	angle1 = RADIAN_DEGREES * acos((double)((side2 * side2) + (side3 * side3) - (side1 * side1)) / (2.0 * side2 * side3));
	angle2 = RADIAN_DEGREES * acos((double)((side3 * side3) + (side1 * side1) - (side2 * side2)) / (2.0 * side1 * side3));

	// 3rd angle found using total degrees
	angle3 = TOTALDEGREES - (angle1 + angle2);

	printf("%f, %f, and %f", angle1, angle2, angle3);
}