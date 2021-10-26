#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////


// Reason - This gives the user the rules to review before the game
// Varible - Returns the function it self 
// Called - This is called each time the user wants to review the rules 
void print_game_rules(void) {
	printf("\n--------------------------------\n");
	printf("\nTHESE ARE THE RULES OF THE GAME:\n");
	printf("\n--------------------------------\n");
	printf("\n1. Player rolls two dice with 6 faces each.\n");
	printf("\n2. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("\n3. The sum of the dice is calculated.\n");
	printf("\n4. If the sum is 7 or 11 on the first throw, the player wins.\n");
	printf("\n5. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses\n");
	printf("\n6. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
	printf("\n7. To win, you must continue rolling the dice until you make your point.\n");
	printf("\n8. The player loses by rolling a 7 before making the point.\n");
	printf("\n----------------------------------------------------------------\n");
	return (print_game_rules);
}

/////////////////////////////////////////////////////////////////////////////////////////

// Reason - get starting bank balance 
// varible - I_B get Initial bank balance 
// Called - each new game
double get_bank_balance(void) {
	int I_B;
	printf("\nEnter Initial Balance --------: ");
	scanf("%d", &I_B);
	return I_B;
}

/////////////////////////////////////////////////////////////////////////////////////////

// Reason - This gets the wager amount each roll 
// varible - g_wager askss the user for the amount they want to wager 
// Called - This is called every time a wager is going to occur 
double get_wager_amount(void) {
	int g_wager;
	printf("\nEnter Wager --------:");
	scanf("%d", &g_wager);
	return g_wager;
}

/////////////////////////////////////////////////////////////////////////////////////////

// Reason - This makes sure the user puts a wager amount that is greater than 0 and less than thier bank 
// varible - 
// Called - 

double check_wager_amount(double g_wager, double I_B) {
	int set_wager;
	char answer, option;

	if (g_wager > I_B)
	{
		do {
			printf("\n$%.2lf is more than you have in your balance\n", g_wager);
			printf("\npick a New wager amount\n");
			scanf("%d", g_wager);
			printf("\nYour new wager amount is set at $%.2lf\n", g_wager);
			set_wager = g_wager;
			return set_wager;
		} while (g_wager > I_B);
	}
	// if wager is less than or equal to zero 
	if (g_wager <= 0.0)
	{
		do {
			printf("\nYou cant have zero or below bet!!!!\n");
			printf("\npick a New wager amount: ");
			scanf("%d", g_wager);
			printf("\nYour new wager amount is set at $%.2lf\n", g_wager);
			set_wager = g_wager;
			return set_wager;
		} while (g_wager <= 0.0);
	}
	else {
		set_wager = g_wager;
		return set_wager;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

// Reason - generates one random number  
// varible - num is the return value for the random number generator
// calling - This is called before each roll 
int roll_die(void) {
	int lower = 1, upper = 6, count = 1, num;
	num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

////////////////////////////////////////////////////////////////////////////////////////

	// Reason - Calculates one roll 
	// varible - v_sum returns the sum of the dice, die_1 and die_2
	// calling - This is called before each roll to get the roll value
int calculate_sum(int die_1, int die_2) {
	int v_sum;
	v_sum = die_1 + die_2;
	return v_sum;
}


/////////////////////////////////////////////////////////////////////////////////////////

// Reason - Determines the result of the first dice roll
// varible - point_val is point value and that is the amount that you need for the need roll
// calling - This is called to calculate whether the user won or not 

int is_win_loss_or_point(int v_sum) {
	switch (v_sum)
	{
	case 7:
	case 11:
		return 1;

	case 2:
	case 3:
	case 12:
		return 0;


	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
	case 10:
		return -1;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////

// Reason - Determine the result of the dice roll after first roll 
// varible - after_roll becomes the amount need to win after the first roll 
// calling - This is called after the first roll function is called  

int is_point_loss_or_neither(int v_sum, int point_val) {

	switch (point_val)
	{
	case 7:
		return 0;

	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		return 1;

	}
}
