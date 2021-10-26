#include "Header.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// Function - 1. print out hello, 2. explain the rules, 3. continue to the main game

void welcome_screen() {
	printf("\n <---- WELCOME TO BATTLESHIP ----> \n");
	printf("\n Created by Mark S.\n");
	printf("\n These are the Rules of BattleShip:\n");
	printf("-------------------------------------");
	printf("\n 1. Battleship is a two player game, you will be playing against a computer\n");
	printf("\n 2. You/User will be player1 and the computer will be player2\n");
	printf("\n 3. You will have 5 ships in your fleet\n");
	printf("    - Carrier('c') is 5 spaces\n");
	printf("    - Battleship('b') is 4 spaces\n");
	printf("    - Crusier('r') is 3 spaces\n");
	printf("    - Submarine('s') is 3 spaces\n");
	printf("    - Destroyer('d') is 2 spaces\n");
	printf("\n 4. When placing ships, you will enter the y,x coordinates for the position of each ship\n");
	printf("    \n\t- (4.a): For Example: the x axis is the vertical set of numbers on the left\n\t\t\t\t and the y axis is the horizontal set on the top\n");
	printf("	\n\t- (4.b): if you wish to enter the coordinates manually for your ships it would look like \n");
	printf("		-- (y,x) or 0 2 0 4 0 5 0 6 0 7\n");
	printf("		-- (Above^) 0 is compared to the 0 of the numbers listed on top/vertical and\n\t\t\t\t2 is compared to the number 2 lised on the left/horizontal\n");
	printf("\n 5. You also have the choice of having your ships be randomly placed on the board\n");
	printf("\n 6. After you select random or manual you will choose a coordinate pair on the board and fire\n");
	printf("\n 7. If your ship is hit or you hit the computers ship a '*' symbol will take its place\n");
	printf("\n 8. if you fire and you miss the letter 'm' will replace the icon on the board where you missed\n");
	printf("\n 9. A record of where you hit, miss will be displayed in the Battleship.log file\n");
	printf("\n 10. If you or the computer destorys all of eachothers ships that player will Win The Game\n");
	printf("\n -- * Press (Any key) start the game * --\n");
	getch();
	system("cls");

}
char initialize_board(int x_1, int y_1, int x_2, int y_2, char board[MAX_ROWS][MAX_COLS], int display, int user1, 
    int horizontal, int vertical, int* hits, char see_board[MAX_ROWS][MAX_COLS], char kind)
{
    int x = 0, y = 0;
    if (display != 0)
    {
        printf("\n    0 1 2 3 4 5 6 7 8 9\n");
        printf("   ---------------------\n");
    }
    for (x = 0; x < 10; x++)
    {
        if ((x < 9) && (display != 0))
        {
            printf("%d | ", x);
        }
        if ((x == 9) && (display != 0))
        {
            printf("%d | ", x);
        }
        for (y = 0; y < 10; y++)
        {
            if ((board[x][y] != 'c') && (board[x][y] != 'b') && (board[x][y] != 'r') && (board[x][y] != 's') && (board[x][y] != 'd') 
                && (board[x][y] != '*') && (board[x][y] != 'm'))
            {
                board[x][y] = '~';
                if ((((x == x_1) && (y == y_1)) || 
                    ((x == x_2) && (y == y_2))) && (display != -1))
                {
                    board[x][y] = kind;
                }
                if ((((x < x_1) && (x > x_2) && (y == y_1)) || 
                    ((x > x_1) && (x < x_2) && (y == y_1))) && (display != -1))
                {
                    board[x][y] = kind;
                }
                if ((((y < y_1) && (y > y_2) && (x == x_1)) || 
                    ((y > y_1) && (y < y_2) && (x == x_1))) && (display != -1))
                {
                    board[x][y] = kind;
                }
            }
            if (board[x][y] == '~')
            {
                see_board[x][y] = '~';
            }
            if ((board[x][y] >= 'b') && (board[x][y] <= 's') && (board[x][y] != 'm'))
            {
                see_board[x][y] = '~';
            }
            if (board[x][y] == 'm')
            {
                see_board[x][y] = 'm';
            }
            if (board[x][y] == '*')
            {
                see_board[x][y] = '*';
            }
            if ((x == horizontal) && (y == vertical))
            {
                if ((board[x][y] >= 'b') && (board[x][y] <= 's'))
                {
                    see_board[x][y] = '*';
                    board[x][y] = '*';
                    *hits = *hits + 1;
                }
                if (board[x][y] == '~')
                {
                    see_board[x][y] = 'm';
                    board[x][y] = 'm';
                }
            }
            if ((display != 0) && (user1 == 1))
            {
                printf("%c ", board[x][y]);
            }
            if ((display != 0) && (user1 == 2))
            {
                printf("%c ", see_board[x][y]);
            }
            if ((y == 9) && (display != 0))
            {
                printf("| %d\n", x);
            }
        }
    }
    if (display != 0)
    {
        printf("   ----------------------\n");
        printf("    0 1 2 3 4 5 6 7 8 9\n\n");
    }
    return board;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. get random number, 2. display which player will go first 

int select_starting_player(void)
{
	int option = 0, which_player = 0;
	option = rand() % 2;
	if (option == 0)
	{
		printf("\n<... The USER will start first ...>\n\n");
		which_player = 1;
	}
	if (option == 1)
	{
		printf("\n<... THE CPU will start first ...>\n\n");
		which_player = 2;
	}
	return which_player;
} 


//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. get random or manual input from user
int ship_placement(void)
{
	int place_ships = 0;
	printf("\n How would you like to place your ship? \n\n 1. Manually\n 2. Randomly\n\n--> ");
	scanf("%d", &place_ships);
    system("cls");
	return place_ships;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. after the user input has been gotten 2. Then this will allow the user to manually place the ship
void manual_placement (int* x_1, int* y_1, int* x_2, int* y_2, int size, char board[MAX_ROWS][MAX_COLS])
{
    int check = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x = 0, y = 0;
    do {
        do {
            check = 0; x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, * x_1 = 0; 
            printf("\nEnter the endpoint coordinates for your Ship, size: %d: \n", size);
            scanf("%d %d %d %d", y_1, x_1, y_2, x_2);
            if ((*x_1 != *x_2) && (*y_1 != *y_2))
            {
                printf("INVALID SHIP PLACEMENT error: Digonal placement\n");
            }
            if (*y_1 == *y_2)
            {
                check = abs(*x_1 - *x_2) + 1;
            }
            if (*x_1 == *x_2)
            {
                check = abs(*y_1 - *y_2) + 1;
            }
            if (check != size)
            {
                printf("\nINVALID SHIP PLACEMENT\n");
            }
        } while (((*x_1 < 0) || (*x_1 > 9)) || 
            ((*y_1 < 0) && (*y_1 > 9)) || 
            ((*x_2 < 0) || 
            (*x_2 > 9)) || 
            ((*y_2 < 0) && (*y_2 > 9)) || 
            ((*x_1 != *x_2) && (*y_1 != *y_2)) || 
            (check != size));

        if (*y_1 == *y_2)
        {
            if (*x_1 > * x_2)
            {
                if (size > 2)
                {
                    x1 = *x_2 + 1;
                    y1 = *y_1;
                }
                if (size > 3)
                {
                    x2 = *x_2 + 2;
                    y2 = *y_1;
                }
                if (size > 4)
                {
                    x3 = *x_2 + 3;
                    y3 = *y_1;
                }
            }
            if (*x_1 < *x_2)
            {
                if (size > 2)
                {
                    x1 = *x_1 + 1;
                    y1 = *y_1;
                }
                if (size > 3)
                {
                    x2 = *x_1 + 2;
                    y2 = *y_1;
                }
                if (size > 4)
                {
                    x3 = *x_1 + 3;
                    y3 = *y_1;
                }
            }
        }
        if (*x_1 == *x_2)
        {
            if (*y_1 < *y_2)
            {
                if (size > 2)
                {
                    x1 = *x_1;
                    y1 = *y_1 + 1;
                }
                if (size > 3)
                {
                    x2 = *x_1;
                    y2 = *y_1 + 2;
                }
                if (size > 4)
                {
                    x3 = *x_1;
                    y3 = *y_1 + 3;
                }
            }
            if (*y_1 > * y_2)
            {
                if (size > 2)
                {
                    x1 = *x_1;
                    y1 = *y_2 + 1;
                }
                if (size > 3)
                {
                    x2 = *x_1;
                    y2 = *y_2 + 2;
                }
                if (size > 4)
                {
                    x3 = *x_1;
                    y3 = *y_2 + 3;
                }
            }
        }
        if ((((board[*x_1][*y_1] > 'e') && (board[*x_1][*y_1] < 'y')) || 
            ((board[*x_2][*y_2] > 'e') && (board[*x_2][*y_2] < 'y')) || 
            (((board[x1][y1] > 'e') && (board[x1][y1] < 'y')) && (size > 2)) || 
            (((board[x2][y2] > 'e') && (board[x2][y2] < 'y')) && (size > 3)) || 
            (((board[x3][y3] > 'e') && (board[x3][y3] < 'y') && (size > 4)))))
        {
            printf("\nTHE SHIPS ARE NOT ALLOWED TO OVERLAP, INSERT AGAIN\n");
        }
    } while ((((board[*x_1][*y_1] > 'e') && (board[*x_1][*y_1] < 'y')) || 
        ((board[*x_2][*y_2] > 'e') && (board[*x_2][*y_2] < 'y')) || 
        (((board[x1][y1] > 'e') && (board[x1][y1] < 'y')) && (size > 2)) || 
        (((board[x2][y2] > 'e') && (board[x2][y2] < 'y')) && (size > 3)) || 
        (((board[x3][y3] > 'e') && (board[x3][y3] < 'y') && (size > 4)))));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//Function - 1. After the user input is gathered this will determine where the ship will be placed                           
void random_placement(int* x_1, int* y_1, int* x_2, int* y_2, int size, char board[MAX_ROWS][MAX_COLS])
{
    int random = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    do {
        *x_1 = rand() % 10;
        *y_1 = rand() % 10;
        random = rand() % 2;
        if (random == 0)
        {
            *x_2 = *x_1 - size + 1;
            *y_2 = *y_1;
            if (size > 2)
            {
                x1 = *x_2 + 1;
                y1 = *y_1;
            }
            if (size > 3)
            {
                x2 = *x_2 + 2;
                y2 = *y_1;
            }
            if (size > 4)
            {
                x3 = *x_2 + 3;
                y3 = *y_1;
            }
        }
        if (random == 1)
        {
            *y_2 = *y_1 - size + 1;
            *x_2 = *x_1;
            if (size > 2)
            {
                x1 = *x_1;
                y1 = *y_2 + 1;
            }
            if (size > 3)
            {
                x2 = *x_1;
                y2 = *y_2 + 2;
            }
            if (size > 4)
            {
                x3 = *x_1;
                y3 = *y_2 + 3;
            }
        }
    } while ((*x_2 < 1) || (*y_2 < 1) || (*x_2 > 9) || (*y_2 > 9) || 
        ((board[*x_1][*y_1] > 'e') && (board[*x_1][*y_1] < 'y')) || 
        ((board[*x_2][*y_2] > 'e') && (board[*x_2][*y_2] < 'y')) || 
        ((board[x1][y1] > 'e') && (board[x1][y1] < 'y')) || 
        ((board[x2][y2] > 'e') && (board[x2][y2] < 'y')) || 
        ((board[x3][y3] > 'e') && (board[x3][y3] < 'y')));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. This will allow the user or player 1 to shoot at the enemy 
void player_shoot_ship(int* horizontal, int* vertical, char board[MAX_ROWS][MAX_COLS])
{
    do {
        do {
            printf("\nEnter target coordinates (with space): \n");
            scanf("%d %d", horizontal, vertical);
            if ((*horizontal > 9) || (*horizontal < 0) || (*vertical > 9) || (*vertical < 0))
            {
                printf("\nYour target coordinates must be from 0-9!\n");
            }
        } while ((*horizontal > 9) || (*horizontal < 0) || (*vertical > 9) || (*vertical < 0));
       
        if ((board[*horizontal][*vertical] == '*') || (board[*horizontal][*vertical] == 'm'))
        {
            printf("\n You have already shot there! \n");
        }
    } while ((board[*horizontal][*vertical] == '*') || (board[*horizontal][*vertical] == 'm'));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. This will allow the computer or CPU to fire at the user using a rand() function
void computer_shoot_ship(int* horizontal, int* vertical, char board[MAX_ROWS][MAX_COLS])
{
    do {
        *horizontal = rand() % 10;
        *vertical = rand() % 10;
    } while ((board[*horizontal][*vertical] == '*') || (board[*horizontal][*vertical] == 'm'));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. This is a check function to see if any of the ships were hit 
// WARNING - there is an issue with theis function 
int check_if_sunk(char board[MAX_ROWS][MAX_COLS], int* sunked_carrier, int* sunked_battleship, int* sunked_cruiser, int* sunked_submarine, int* sunked_destroyer)
{
    int x = 0, y = 0, c = 0, b = 0, r = 0, s = 0, d = 0;
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            if ((board[x][y] == 'c') && (*sunked_carrier == 0))
            {
                c++;
            }
            if ((board[x][y] == 'b') && (*sunked_battleship == 0))
            {
                b++;
            }
            if ((board[x][y] == 'r') && (*sunked_cruiser == 0))
            {
                r++;
            }
            if ((board[x][y] == 's') && (*sunked_submarine == 0))
            {
                s++;
            }
            if ((board[x][y] == 'd') && (*sunked_destroyer == 0))
            {
                d++;
            }
        }
    }
    if ((c == 0) && (*sunked_carrier != -1))
    {
        printf("YOU SUNK MY CARRIER\n");
        *sunked_carrier = 1;
    }
    if ((b == 0) && (*sunked_battleship != -1))
    {
        printf("YOU SUNK MY BATTLESHIP\n");
        *sunked_battleship = 1;
    }
    if ((r == 0) && (*sunked_cruiser != -1))
    {
        printf("YOU SUNK MY CRUISER\n");
        *sunked_cruiser = 1;
    }
    if ((s == 0) && (*sunked_submarine != -1))
    {
        printf("YOU SUNK MY SUBMAINE\n");
        *sunked_submarine = 1;
    }
    if ((d == 0) && (*sunked_destroyer != -1))
    {
        printf("YOU SUNK MY DESTROYER\n");
        *sunked_destroyer = 1;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
 //Function - 1. The game finishes 2. This function will allow the moves of the player to be stored in a data file 
void output_player_moves(FILE* output_file, int horizontal, int vertical, int user1, int hits, int* sunked_carrier, int* sunked_battleship , int* sunked_cruiser, int* sunked_submarine, int* sunked_destroyer)
{
    if ((horizontal != -1) && (vertical != -1))
    {
        fprintf(output_file, "\nPlayer%d: (%d %d)\t", user1, horizontal, vertical);
    }
    if (hits == 1)
    {
        fprintf(output_file, "\n !!! HIT !!!\n");
    }
    if (hits == 0)
    {
        fprintf(output_file, "\n MISS... \n");
    }
    if (*sunked_carrier == 1)
    {
        fprintf(output_file, "\nTHE USER HAS SUNK: The Carrier...\n");
        *sunked_carrier = -1;
    }
    if (*sunked_battleship == 1)
    {
        fprintf(output_file, "\nTHE USER HAS SUNK: The Battleship...\n");
        *sunked_battleship = -1;
    }
    if (*sunked_cruiser == 1)
    {
        fprintf(output_file, "\nTHE USER HAS SUNK: The Cruiser...\n");
        *sunked_cruiser = -1;
    }
    if (*sunked_submarine == 1)
    {
        fprintf(output_file, "\nTHE USER HAS SUNK: Submarine...\n");
        *sunked_submarine = -1;
    }
    if (*sunked_destroyer == 1)
    {
        fprintf(output_file, "\nTHE USER HAS SUNK: Destroyer...\n");
        *sunked_destroyer = -1;
    }
    fprintf(output_file, "\n");
}
//Function - 1. The game finishes 2. This function will allow the data of the player and computer to be written into the file 
void output_player_stats(FILE* output_file, stats player)
{
    if (player.win_or_loss == 1)
    {
        fprintf(output_file, "\nPlayer%d HAS WON BATTLESHIP !!!! THANK YOU FOR PLAYING\n", player.player);
    }
    if (player.win_or_loss == 0)
    {
        fprintf(output_file, "\nPlayer%d LOSSES THANK YOU FOR PLAYING \n", player.player);
    }
    fprintf(output_file, "\n THE Player%d Stats: \t \nHits: %d\nMisses: %d\nTotal Shots TAKEN : %d\n HIT OR WIN RATIO: %.2lf\n\n", player.player, player.player_hits, player.player_misses, player.fired, player.hit_or_miss);
}
