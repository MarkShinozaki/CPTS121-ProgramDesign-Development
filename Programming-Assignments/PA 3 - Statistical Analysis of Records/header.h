#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // Import standard library
#include <math.h> // Import mathematical library

double read_double(FILE* infile);
int read_integer(FILE* infile);
double calculate_sum(double num1, double num2, double num3, double num4, double num5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double num1, double num2, double num3, double num4, double num5);
double find_min(double num1, double num2, double num3, double num4, double num5);
void print_double(FILE* outfile, double number);
