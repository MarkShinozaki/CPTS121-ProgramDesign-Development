#include "Header.h"

// This function Shows Game options 
int get_Menu_Option()
{
    int choice;
    printf("\nWELCOME TO YAHTZEE, THANK YOU FOR PLAYING, by Mark S.\n");
    printf("\n*--*--MENU--*--*\n");
    printf("\n1. Print game rules\n");
    printf("\n2. Start a game of Yahtzee\n");
    printf("\n3. Exit\n");
    printf("\nPlease enter an option: ");
    scanf(" %d", &choice);
    system("cls");
    return choice;
}



// This function prints out Game Rules 
void print_Game_Rules()
{
    printf("\nThe Rules of Yahtzee:\n");
    printf("The scorecard used for Yahtzee is composed of two sections.\n");
    printf(" A upper section and a lower section.\n");
    printf("A total of thirteen boxes or thirteen scoring combinations are\n");
    printf(" divided amongst the sections.\n");
    printf("The upper section consists of boxes that are scored by summing the\n");
    printf(" value of the dice matching the faces of the box.\n");
    printf("If a player rolls four 3's, then the score placed in the 3's box is\n");
    printf(" the sum of the dice which is 12.\n");
    printf("Once a player has chosen to score a box, it may not be changed and the\n");
    printf(" combination is no longer in play for future rounds.\n");
    printf("If the sum of the scores in the upper section is greater than or equal to 63,\n");
    printf(" then 35 more points are added to the players overall score as a bonus.\n");
    printf("The lower section contains a number of poker like combinations.\n");
    printf(" See the table provided below : \n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Name             |Combination                  |Score                  |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Three-of-a-kind |Three dice with the          |Sum of all face values |\n");
    printf("|                 | same face                   | on the 5 dice         |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Four-of-a-kind   |Four dice with the           |Sum of all face values |\n");
    printf("|                 | same face                   | on the 5 dice         |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Full house       |One pair and a               |25                     |\n");
    printf("|                 | three-of-a-kind             |                       |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Small straight   |A sequence of four dice      |30                     |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Large straight   |A sequence of five dice      |40                     |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Yahtzee (think   |Five dice with the           |50                     |\n");
    printf("| five-of-a-kind) | same face                   |                       |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|Chance           |May be used for any sequence |Sum of all face values |\n");
    printf("|                 | of dice; this is the catch | on the 5 dice         |\n");
    printf("|                 | all combination             |                       |\n");
    printf("|-----------------------------------------------------------------------|\n\n");
}



// This Function starts the game
void start_Game_Of_Yahtzee()
{
    int diceArr[5] = { 0 };
    int rolls[2] = { 0 };
    int totalScore[2] = { 0 };
    int upperSectionScore[2] = { 0 };
    int combinations[2][13] = { { 0 } };
    int rounds = 0;
    int score;
    int comb;
    int player;
    int dice;
    char ch = '\0';
    int i;
    

    rounds = 1;
    for (player = 0; player < 2; player++)
    {
        totalScore[player] = 0;
        upperSectionScore[player] = 0;
        for (comb = 0; comb < 13; comb++)
        {
            combinations[player][comb] = 0;
        }
    }
    while (rounds <= 13)
    {
        for (player = 0; player < 2; player++)
        {
            printf("Round %d\n", rounds);
            printf("Player %d\n", player + 1);
            system("pause");
            printf("\nThe face values of each die...\n");
            rolls[player] = 0;
            dice = 12345;
            roll_Dice(diceArr, dice);
            print_Dice(diceArr);
            rolls[player]++;

            while (rolls[player] < 3)
            {
                printf("Do you want to use this roll for one of the game combinations (Y/N)? ");
                scanf(" %c", &ch);
                ch = tolower(ch);

                while (ch != 'y' && ch != 'n' )
                {
                    printf("Do you want to use this roll for one of the game combinations (Y/N)? ");
                    scanf(" %c", &ch);
                }

                if (ch == 'y')
                {
                    rolls[player] = 3;
                }

                else if (ch == 'n')
                {
                    printf("which die or dice do you want to re-roll (1-5) (enter 0 to exit): ");
                    scanf(" %d", &dice);
                    if (dice == 0)
                    {
                        printf("Thank you. Goodbye!\n");
                        exit(1);
                    }
                    roll_Dice(diceArr, dice);
                    print_Dice(diceArr);
                    rolls[player]++;
                }
            }

            if (rolls[player] == 3)
            {
                printf("Select a combination to use: ");
                printf("(Enter 0 to exit. Unused combinations:");
                for (i = 0; i < 13; i++)
                {
                    if (combinations[player][i] == 0)
                        printf(" %d", i + 1);
                }

                printf(")\n");
                printf("1. Sum of 1's\n");
                printf("2. Sum of 2's\n");
                printf("3. Sum of 3's\n");
                printf("4. Sum of 4's\n");
                printf("5. Sum of 5's\n");
                printf("6. Sum of 6's\n");
                printf("7. Three-of-a-kind\n");
                printf("8. Four-of-a-kind\n");
                printf("9. Full house\n");
                printf("10. Small straight\n");
                printf("11. Large straight\n");
                printf("12. Yahtzee\n");
                printf("13. Chance\n");
                scanf(" %d", &comb);

                if (comb == 0)
                {
                    printf("Thanks for playing. Goodbye!\n");
                    exit(1);
                }

                while (comb < 1 || comb > 13 || combinations[player][comb - 1] == 1)
                {
                    printf("Enter a valid and available combination: ");
                    scanf(" %d", &comb);
                }

                combinations[player][comb - 1] = 1;
                score = get_Score_Of_Combination_2(diceArr, comb);
                totalScore[player] += score;

                if (comb >= 1 && comb <= 6)
                {
                    upperSectionScore[player] += score;
                }

                printf("Score: %d, Total score: %d, Upper section score: %d\n", score, totalScore[player], upperSectionScore[player]);
                system("pause");
                system("cls");
            }
        }
        rounds++;
    }

    for (player = 0; player < 2; player++)
    {
        if (upperSectionScore[player] >= 63)
        {
            totalScore[player] += 35;
        }
        printf("Total score of player %d: %d\n", player + 1, totalScore[player]);
    }


    if (totalScore[0] > totalScore[1])
    {
        printf("Player 1 wins the game!\n\n");
    }
    else if (totalScore[0] < totalScore[1])
    {
        printf("Player 2 wins the game!\n\n");
    }
    else
    {
        printf("Draw the game!\n\n");
    }
}

// This function rolls the dice 1-5 

void roll_Dice(int diceArr[], int dice)
{
    int die;
    do
    {
        die = dice % 10;
        if (die >= 1 && die <= SIZE)
        {
            diceArr[die - 1] = rand() % 6 + 1;
        }
        dice = dice / 10;
    } while (dice != 0);
}


// This prints a model of the dice for user interaction 

void print_Dice(int diceArr[])
{
    int i = 0;
    int line = 1;

    while (line <= SIZE)
    {
        switch (line)
        {
        case 1:
            while (i < SIZE)
            {
                switch (diceArr[i])
                {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    printf("-----   ");
                    break;
                }
                i++;
            }
            printf("\n");
            line++;
            i = 0;
            break;
        case 2:
            while (i < SIZE)
            {
                switch (diceArr[i])
                {
                case 1:
                    printf("|   |   ");
                    break;
                case 2:
                    printf("|o |   ");
                    break;
                case 3:
                    printf("|o |   ");
                    break;
                case 4:
                    printf("|o o|   ");
                    break;
                case 5:
                    printf("|o o|   ");
                    break;
                case 6:
                    printf("|o o|   ");
                    break;

                }
                i++;
            }
            printf("\n");
            line++;
            i = 0;
            break;
        case 3:
            while (i < SIZE)
            {
                switch (diceArr[i])
                {
                case 1:
                    printf("| o |   ");
                    break;
                case 2:
                    printf("|   |   ");
                    break;
                case 3:
                    printf("| o |   ");
                    break;
                case 4:
                    printf("|   |   ");
                    break;
                case 5:
                    printf("| o |   ");
                    break;
                case 6:
                    printf("|o o|   ");
                    break;

                }
                i++;
            }
            printf("\n");
            line++;
            i = 0;
            break;
        case 4:
            while (i < SIZE)
            {
                switch (diceArr[i])
                {
                case 1:
                    printf("|   |   ");
                    break;
                case 2:
                    printf("| o|   ");
                    break;
                case 3:
                    printf("| o|   ");
                    break;
                case 4:
                    printf("|o o|   ");
                    break;
                case 5:
                    printf("|o o|   ");
                    break;
                case 6:
                    printf("|o o|   ");
                    break;

                }
                i++;
            }
            printf("\n");
            line++;
            i = 0;
            break;
        case 5:
            while (i < SIZE)
            {
                switch (diceArr[i])
                {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    printf("-----   ");
                    break;

                }
                i++;
            }
            printf("\n\n");
            line++;
            break;
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("Die %d: %d\n", i + 1, diceArr[i]);
    }
    printf("\n");
}


// This function gets the dice sum 

int get_Sum_Of_Dice(int diceArr[])
{
    int i;
    int sum = 0;
    for (i = 0; i < SIZE; i++)
    {
        sum += diceArr[i];
    }

    return sum;
}


// This function gets the initial combination 
int get_Score_Of_Combination_1(int diceArr[], int comb)
{
    int tempDiceArr[SIZE];
    int i;
    int j;
    int temp;

    for (i = 0; i < SIZE; i++)
    {
        tempDiceArr[i] = diceArr[i];
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
            if (tempDiceArr[i] > tempDiceArr[j])
            {
                temp = tempDiceArr[i];
                tempDiceArr[i] = tempDiceArr[j];
                tempDiceArr[j] = temp;
            }
        }
    }

    if (comb == 7)
    {
        if (tempDiceArr[0] == tempDiceArr[1] && tempDiceArr[1] == tempDiceArr[2] || tempDiceArr[1] == tempDiceArr[2] && tempDiceArr[2] == tempDiceArr[3] || tempDiceArr[2] == tempDiceArr[3] && tempDiceArr[3] == tempDiceArr[4])
        {
            return get_Sum_Of_Dice(tempDiceArr);
        }
    }
    else if (comb == 8)
    {
        if (tempDiceArr[0] == tempDiceArr[1] && tempDiceArr[1] == tempDiceArr[2] && tempDiceArr[2] == tempDiceArr[3] || tempDiceArr[1] == tempDiceArr[2] && tempDiceArr[2] == tempDiceArr[3] && tempDiceArr[3] == tempDiceArr[4])
        {
            return get_Sum_Of_Dice(tempDiceArr);
        }
    }
    else if (comb == 9)
    {
        if (tempDiceArr[0] == tempDiceArr[1] && tempDiceArr[2] == tempDiceArr[3] && tempDiceArr[3] == tempDiceArr[4] || tempDiceArr[0] == tempDiceArr[1] && tempDiceArr[1] == tempDiceArr[2] && tempDiceArr[3] == tempDiceArr[4])
        {
            return 25;
        }
    }
    else if (comb == 10)
    {
        if (tempDiceArr[0] == 1 && tempDiceArr[1] == 2 && tempDiceArr[2] == 3 && tempDiceArr[3] == 4 || tempDiceArr[0] == 2 && tempDiceArr[1] == 3 && tempDiceArr[2] == 4 && tempDiceArr[3] == 5 || tempDiceArr[0] == 3 && tempDiceArr[1] == 4 && tempDiceArr[2] == 5 && tempDiceArr[3] == 6 ||
            tempDiceArr[1] == 1 && tempDiceArr[2] == 2 && tempDiceArr[3] == 3 && tempDiceArr[4] == 4 || tempDiceArr[1] == 2 && tempDiceArr[2] == 3 && tempDiceArr[3] == 4 && tempDiceArr[4] == 5 || tempDiceArr[1] == 3 && tempDiceArr[2] == 4 && tempDiceArr[3] == 5 && tempDiceArr[4] == 6)
        {
            return 30;
        }
    }
    else if (comb == 11)
    {
        if (tempDiceArr[0] == 1 && tempDiceArr[1] == 2 && tempDiceArr[2] == 3 && tempDiceArr[3] == 4 && tempDiceArr[4] == 5 || tempDiceArr[0] == 2 && tempDiceArr[1] == 3 && tempDiceArr[2] == 4 && tempDiceArr[3] == 5 && tempDiceArr[4] == 6)
        {
            return 40;
        }
    }

    return 0;
}


// This function gets the second initial combination 
int get_Score_Of_Combination_2(int diceArr[], int comb)
{
    int score = 0;
    int i;
    switch (comb)
    {
    case 1:
        for (i = 0; i < SIZE; i++)
        {
            if (diceArr[i] == 1)
                score++;
        }
        break;
    case 2:
        for (i = 0; i < SIZE; i++)
        {
            if (diceArr[i] == 2)
                score += 2;
        }
        break;
    case 3:
        for (i = 0; i < SIZE; i++)
        {
            if (diceArr[i] == 3)
                score += 3;
        }
        break;
    case 4:
        for (i = 0; i < SIZE; i++)
        {
            if (diceArr[i] == 4)
                score += 4;
        }
        break;
    case 5:
        for (i = 0; i < SIZE; i++)
        {
            if (diceArr[i] == 5)
                score += 5;
        }
        break;
    case 6:
        for (i = 0; i < SIZE; i++)
        {
            if (diceArr[i] == 6)
                score += 6;
        }
        break;
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        score = get_Score_Of_Combination_1(diceArr, comb);
        break;
    case 12:
        if (diceArr[0] == diceArr[1] && diceArr[1] == diceArr[2] && diceArr[2] == diceArr[3] && diceArr[3] == diceArr[4])
        {
            score = 50;
        }
        break;
    case 13:
        score = get_Sum_Of_Dice(diceArr);
        break;
    }
    return score;
}
