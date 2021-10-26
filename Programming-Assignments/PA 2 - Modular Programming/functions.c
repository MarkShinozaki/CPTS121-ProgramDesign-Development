#include "Header.h"

//character encoding
char character_encryption(char plaintext_character, int shift_int)
{
  char The_char = (plaintext_character - 'a') + 'A' - shift_int;
  return(The_char);
}

//calculate resistance
int calculate_series_resistance(int r1, int r2, int r3)
{
  int res = r1 + r2 + r3;
  return(res);
}

//General Equation 
double general_equation(int a, double x, double y, double z)
{
  y = y / (3 / 17) - (double)z + (double)x / ((int)a % 2) + PI;
  return (y);
}

//calculate sales tax
double calculate_total_sales_tax(double sales_tax_rate, double item_cost)
{
  double t = sales_tax_rate * item_cost;
  return(t);
}

//calculate volume
double calculate_volume_pyramid(double l, double w, double h)
{
  double v_p = (l * w * h) / 3.0;
  return(v_p);
}

//distance from two points
double distance_positions(double x1, double y1, double x2, double y2)
{
  double distance = sqrt((pow(x1 - x2, 2)) + (pow(y1 - y2, 2)));
  return(distance);
}

//parallel resistance
float total_parallel_resistance(int r_1, int r_2, int r_3)
{
  float res = (1.0 / ((1 / r_1) + (1 / r_2) + (1 / r_3)));
  return (res);
}
