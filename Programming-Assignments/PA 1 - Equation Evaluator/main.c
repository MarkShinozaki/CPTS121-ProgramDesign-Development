/*
Name: Mark Shinozaki
Class: CptS 121, Fall 2020
Lab Assignment: Programming Assignment 1
Date: 09/09/2020
Description: Equation Evaluator
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(void)
{
	// PART 1 - Total resistance series
	printf("----------------------------Total Resistance Series - Part 1----------------------------\n");
	int R1 = 0,R2 = 0,R3 = 0,total1 = 0;
	printf("\nPlease enter the values of 3 resistors in series(separated by a space): ");
	scanf("%d %d %d", &R1, &R2, &R3);
	total1 = (R1 + R2 + R3);
	printf("\nThe total series resistance: resistance_series = R1 + R2 + R3 = %d + %d + %d = %d\n", R1, R2, R3, total1);

	// PART 2 - SALES TAX
	printf("\n----------------------------Sales Tax - Part 2---------------------------------\n");
	double sales_tax_rate, item_cost, total_sales_tax, total2;
	printf("\nWhat is the cost of the item (in decimal or integer form): ");
	scanf("%lf", &item_cost);
	printf("\nWhat is the sales tax rate at your location (in decimal form): ");
	scanf("%lf", &sales_tax_rate);
	sales_tax_rate = (sales_tax_rate / 100);
	total_sales_tax = (sales_tax_rate * item_cost);
	printf("\nYour total sales tax is: %.3lf \n", total_sales_tax);
	total2 = (total_sales_tax + item_cost);
	printf("\nThis means your subtotal is $%.3lf \n", total2);

	// PART 3 - VOLUME  OF A RIGHT RECTANGULAR PYRAMID
	printf("\n----------------Volume Of A Right Rectangular Pyramid - Part 3------------------\n");
	int length, width, height, volume;
	printf("\nType the Length, Width & Height with a space inbetween each number: ");
	scanf("%d %d %d", &length, &width, &height);
	volume = (length * width * height) / 3;
	printf("\n The volume of the pyramid with %d length, %d width and %d height, is %d cubic units \n ",length, width,height, volume);

	// PART 4 - TOTAL PARALLEL RESISTANCE
	printf("\n----------------------------Total Parallel Resistance - Part 4-------------------\n");
	double R_1, R_2, R_3, parallel_resistance;
	printf("\nPlease enter the 3 integer values in the parallel resistance series(separated by a space): ");
	scanf("%lf %lf %lf", &R_1, &R_2, &R_3);
	printf("\n The three values are R1 = %lf  R2 = %lf R3 = %lf \n", R_1, R_2, R_3);
	parallel_resistance = 1 / ((1 / R_1) + (1 / R_2) + (1 / R_3));
	printf("\n The Total Parallel Resistance: 1 / ( 1 / R1 + 1 / R2 + 1 / R3) = %lf + %lf + %lf = %lf \n", R_1, R_2, R_3, parallel_resistance);

	// PART 5 - CHARACTER ENCODING
	char plaintext_character, encoded_character;
	int shift;
	printf("\n----------------------------Character Encoding - Part 5---------------------------------\n");
	printf("\nCharacter encoding: encoded_character = (plaintext_character - 'A') + 'a' - shift\n");
	printf("\nEnter a plaintext_character: ");
	scanf("%c", &plaintext_character);
	printf("\nEnter the value of shift(here shift is an integer): ");
	scanf("%d", &shift);
	encoded_character = (plaintext_character - 'A') + 'a' - shift;
	printf("\nEncoded character = (%c - 'A') + 'a' - %d = %c \n ",plaintext_character,shift, encoded_character);

	// PART 6 - DISTANCE BETWEEN TWO POINTS
	float x1, x2, y1, y2, distance;
	printf("\n----------------------------Distance Between Two Points - Part 6--------------------------\n");
	printf("\nWith this program you will be entering two points each point in used to find the distance\n");
	printf("\nfirst point(Enter both numbers): ");
	scanf("%f%f", &x1, &y1);
	printf("\nSecond point(Enter both numbers): ");
	scanf("%f%f", &x2, &y2);
	distance = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	printf("\ndistance between these two points (%lf,%lf) & (%lf, %lf) is %f \n ",x1,x2,y1,y2, distance);

	// PART 7 - GENERAL EQUATION
	float x, y, z;
	int a;
	printf("\n----------------------------General Equation - Part 7---------------------------------\n");
	printf("\n GENERAL EQUATION \n");
	//inputs
	printf("\n x value:");
	scanf("%f", &x);
	printf("\n z value:");
	scanf("%f", &z);
	printf("\n a value:");
	scanf("%d", &a);
	printf("\n y value:");
	scanf("%d", &y);
	//general equation with type casting
	y = (float) y / ((float)3 / (float) 17) - (float)z + (float)x / ((float)(a % 2) + PI);
	
	printf("\n y = %lf \n ", y);


	return 0;
}
