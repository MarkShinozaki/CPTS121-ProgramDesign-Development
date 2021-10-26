#ifndef YahtzeeGame
#define YahtzeeGame
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define SIZE 5


int get_Menu_Option();
void print_Game_Rules();
void start_Game_Of_Yahtzee();
void roll_Dice(int diceArr[], int dice);
void print_Dice(int diceArr[]);
int get_Sum_Of_Dice(int diceArr[]);
int get_Score_Of_Combination_1(int diceArr[], int comb);
int get_Score_Of_Combination_2(int diceArr[], int comb);

#endif
