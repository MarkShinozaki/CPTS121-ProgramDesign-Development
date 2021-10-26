#define _CRT_SECURE_NO_WARNINGS
/*
Name: Mark Shinozaki
Class: CptS 121, Fall 2020
Lab Assignment: Programming Assignment 2 
Date: 09/18/2020
Description: A Modualar Approach to the Equation Evaluator 
*/

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14
#include <stdio.h>
#include <math.h>

int main(void)
{
    char The_char;
    char plain_text;
    int shift_int;
    int r1, r2, r3, series_resistance;
    int a;
    double x, y, z;
    double sales_tax_rate, item_cost, total_sales_tax, l, w, h, volume_pyramid;
    double distance = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
    float total_parallel;
    int r_1, r_2, r_3;
     
     
    printf("\n\n-----*Charecter Encoding*-----\n");
    printf("\nEnter the plain text charecter to Encrypt (Only Single Charecter ): ");
    scanf("%c", &plain_text);
    printf("\nEnter the value for shifting (Only Integer value ):");
    scanf("%d", &shift_int);
    The_char = character_encryption(plain_text, shift_int);
    printf("\nFinal Encoded Charecter is %c \n", The_char);
     
     
    printf("\n\n-----*Total Series Resistance*-----\n\n");
    printf("Enter the resistance values R1, R2, R3 :");
    scanf("%d%d%d", &r1, &r2, &r3);
    series_resistance = calculate_series_resistance(r1, r2, r3);
    printf("The series resistance is %d \n", series_resistance);

    printf("\n\n-----*General Equation*-----\n");
    printf("Enter the value of 'a' :");
    scanf("%d", &a);
    printf("Enter the values of X, Y and Z :");
    scanf("%lf%lf%lf", &x, &y, &z);
    y = general_equation(a, x, y, z);
    printf("The Value of General Equation is %lf ", y);


    printf("\n\n-----*Total Sales Tax*-----\n");
    printf("Enter the Sales Tax rate and Item Cost (for example .5 5): ");
    scanf("%lf%lf", &sales_tax_rate, &item_cost);
    total_sales_tax = calculate_total_sales_tax(sales_tax_rate, item_cost);
    printf("Total Sales tax is %lf \n", total_sales_tax);



    printf("\n\n-----*Volume of Pyramid*-----\n");
    printf("Enter length and width of base (pyramid): ");
    scanf("%lf %lf", &l, &w);
    printf("Enter the height of pyramid : ");
    scanf("%lf", &h);
    volume_pyramid = calculate_volume_pyramid(l, w, h);
    printf("Volume of Pyramid is %lf \n", volume_pyramid);


    printf("\nWith this program you will be entering two points each point in used to find the distance\n");
    printf("\nEnter all four numbers with a space inbetween them, x1, x2, y1, y2 : ");
    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
    distance = distance_positions(x1, x2, y1, y2);
    printf("\ndistance between two points  %lf \n ", distance);


    printf("\n\n-----*Total Parallel Resistance*-----\n");
    printf("Enter the resistance values R1, R2, R3: ");
    scanf("%d %d %d", &r_1, &r_2, &r_3);
    total_parallel = total_parallel_resistance(r_1, r_2, r_3);
    printf("Total Parallel Resistance is %f \n", total_parallel);
     
     
}
