/*
	Computer Science 121
	Author: Mark Shinozaki
	Date: 10/15/20
	Assignment: Programming Assignement #4
	Description: This program Lets a user play the game CRAPS
*/


#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int
		die1,
		die2,
		p_value,
		out_come,
		point_val,
		v_sum,
		after_f_roll,
		decision,
		choices,
		outcome,
		p2_value,
		die1_value,
		die2_value,
		roll_again,
		choices2;

	double
		bank_balance,
		wager_amount,
		set_wager,
		current_bank_balance;


	srand(time(NULL));


	printf("\n WELCOME TO THE CRAPS GAME\n");
	printf("\n------------------------------\n");
	printf("\n 1. Start the game\n");
	printf("\n 2. See the Rules\n");
	printf("\nWhat would you like you do:");
	scanf("%d", &decision);

	if (decision == 2 || decision == 1) {
		print_game_rules();
	}




	do {

		bank_balance = get_bank_balance();
		printf("\nInitial amount is set to ( - $%.2lf - ) \n", bank_balance);

		do {
			current_bank_balance = bank_balance;
			// prints the wager amount 
			wager_amount = get_wager_amount();

			// checking wager amount 
			set_wager = check_wager_amount(wager_amount, current_bank_balance);
			printf("\n Wager amount is ( - $%.2lf -) \n", set_wager);


			printf("\n-----------------------------------\n");
			printf("\n Rolling in 3........ \n");
			printf("\n Rolling in 2........ \n");
			printf("\n Rolling in 1........ \n");
			printf("\n-----------------------------------\n");
			// * change printf before finish*
		// rolling die 1 
			die1 = roll_die();
			printf("\nDie 1 is ----- ( - %d - )\n", die1);

			// * change printf before finish*
			// rolling die 2
			die2 = roll_die();
			printf("\nDie 2 is ----- ( - %d - )\n", die2);


			// * change printf before finish*
		// Calulating the sum of die 1 and die 2
			p_value = calculate_sum(die1, die2);



			out_come = is_win_loss_or_point(p_value);
			if (out_come == 1) {
				printf("\nYou rolled a (- %d - )\n", p_value);
				printf("\n !!!!!!!! You Win !!!!!!!\n");
				current_bank_balance = current_bank_balance + set_wager;
				printf("\nYou added +(- $%.2lf -) to your account \n", set_wager);
				printf("\nYour bank balance is now ----- ( - $%.2lf - ) \n", current_bank_balance);
				printf("\n------------------------------\n");

				// ask if they would want to play again
			}
			if (out_come == 0) {

				current_bank_balance = current_bank_balance - set_wager;
				printf("\nYou rolled a %d\n", p_value);
				printf("\nDeduction: --(- $%.2lf - ) \n", set_wager);
				printf("\nYour bank balance is ( - $%.2lf - ) \n", current_bank_balance);
				printf("\nYou lose, You Have Crapped out, HOUSE WINS!\n");
				printf("\nTHANK YOU FOR PLAYING!!!\n");
			}

			else if (out_come == -1) {
				p2_value = p_value;
				printf("\n-----------------------------------\n");
				printf("\nRoll Until you get ( -- * %d * --) again\n", p2_value);
				printf("\n * if a 4, 5, 6, 8, 9, or 10 sum is rolled the balance stays the same after the first roll * \n");
				printf("\n-----------------------------------\n");

				do {
					wager_amount = get_wager_amount();
					set_wager = check_wager_amount(wager_amount, current_bank_balance);
					printf("\n New Wager amount is --- ( - $%.2lf - )\n", set_wager);
					printf("\n-----------------------------------\n");
					printf("\n Rolling in 3........ \n");
					printf("\n Rolling in 2........ \n");
					printf("\n Rolling in 1........ \n");
					printf("\n-----------------------------------\n");
					die1_value = roll_die();
					die2_value = roll_die();
					p2_value = calculate_sum(die1_value, die2_value);

					if (p2_value != p_value) {
						printf("\nDie 1 is --- ( - %d - )\n", die1_value);
						printf("\nDie 2 is --- ( - %d - )\n", die2_value);
						printf("\nDice Total --- (- %d - )\n", p2_value);
						printf("\n-------------\n");
						printf("\nDeduction: --(- $%.2lf - ) \n", set_wager);
						current_bank_balance = (current_bank_balance - set_wager);
						printf("\n Updated Balance --- ( - $%.2lf - ) \n", current_bank_balance);
						printf("\n-----------------------------------\n");
					}
					else {
						choices = 3 - 3;
						printf("\nDie 1 is --- %d\n", die1_value);
						printf("\nDie 2 is --- %d\n", die2_value);
						printf("\nTotal --- ( - %d - )", p2_value);
						current_bank_balance = (current_bank_balance + set_wager);
						printf("\nUpdated Balance --- + ( - $%.2lf - )\n", current_bank_balance);
						printf("\n!!!!!!!You Win!!!!!!!\n");
						printf("\nIf you would like to keep playing with your balance, put in a new wager, if not close the program\n");
						printf("\nTHANK YOU FOR PLAYING\n");

					}

				} while (p2_value != 7 || current_bank_balance != 0.0 || current_bank_balance > 0.0);


				printf("\n--------------------------\n");
				printf("\n 1. Start the game\n");
				printf("\n 3. Exit the game\n");
				printf("\nWhat would you like you do:");
				scanf("%d", &decision);
				if (decision == 1) {
					continue;
				}
				else {
					decision == 3;
				}
			}


		} while (current_bank_balance != 0.0 || current_bank_balance > 0.0);



	} while (decision != 3);

}
