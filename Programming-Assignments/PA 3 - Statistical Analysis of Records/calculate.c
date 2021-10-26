#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // Import standard library
#include <math.h> // Import mathematical library
#include "header.h" // Import header file

double read_double(FILE* infile)
{
    double number = 0.0;
    fscanf(infile, "%lf", &number);
    return number;
}

int read_integer(FILE* infile)
{
    int number = 0;
    fscanf(infile, "%d", &number);
    return number;
}

double calculate_sum(double num1, double num2, double num3, double num4, double num5)
{
    double sum = 0.0;
    sum = num1 + num2 + num3 + num4 + num5;
    return sum;
}

double calculate_mean(double sum, int number)
{
    double mean = 0.0;

    if (number == 0)
    {
        return -1.0;
    }

    else
    {
        mean = sum / number;
        return mean;
    }
}

double calculate_deviation(double number, double mean)
{
    double deviation = 0.0;
    deviation = number - mean;
    return deviation;
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
    double variance = 0.0;
    variance = ((deviation1 * deviation1) + (deviation2 * deviation2)
        + (deviation3 * deviation3) + (deviation4 * deviation4)
        + (deviation5 * deviation5)) / number;
    return variance;
}

double calculate_standard_deviation(double variance)
{
    double standard_deviation = 0.0;
    standard_deviation = sqrt(variance);
    return standard_deviation;
}

double find_max(double num1, double num2, double num3, double num4, double num5)
{
    double max = num1;

    if (num2 > max)
    {
        max = num2;
    }

    if (num3 > max)
    {
        max = num3;
    }

    if (num4 > max)
    {
        max = num4;
    }

    if (num5 > max)
    {
        max = num5;
    }

    return max;
}

double find_min(double num1, double num2, double num3, double num4, double num5)
{
    double min = num1;

    if (num2 < min)
    {
        min = num2;
    }

    if (num3 < min)
    {
        min = num3;
    }

    if (num4 < min)
    {
        min = num4;
    }

    if (num5 < min)
    {
        min = num5;
    }

    return min;
}

void print_double(FILE* outfile, double number)
{
    fprintf(outfile, "%.2lf\n", number);
}
