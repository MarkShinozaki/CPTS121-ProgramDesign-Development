/*
	Computer Science 121
	Author: Mark Shinozaki
	Date: 10/31/20
	Assignment: Programming Assignement #5
	Description: Yahtzee Game
*/


#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"


int main()
{
    srand((unsigned int)time(NULL));
    int choice;

    do
    {
        choice = get_Menu_Option();

        switch (choice)
        {
        case 1:
            print_Game_Rules();
            break;

        case 2:
            start_Game_Of_Yahtzee();
            break;

        case 3:
            printf("Thanks for playing. Goodbye!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}
