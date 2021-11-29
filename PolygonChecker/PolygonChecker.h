#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#pragma once

#define RADIAN_DEGREES 57.2958
#define TOTALDEGREES 180
#define M_PI 3.14159265358979323846

void PrintFunctions();

char* TriangleChecker(int side1, int side2, int side3);
void TriangleAngle(int side1, int side2, int side3);

bool RectangleChecker(int rectangleSides[]);