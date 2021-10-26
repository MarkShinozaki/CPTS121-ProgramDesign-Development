#ifndef Battleship
#define Battleship

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#define MAX_ROWS 10
#define MAX_COLS 10
typedef struct
{
	int player; 
	int player_hits; 
	int player_misses; 
	int fired; 
	double hit_or_miss; 
	int win_or_loss; 
	
}stats;
void welcome_screen(void);
char initialize_board(int x_1, int y_1, int x_2, int y_2, char board[MAX_ROWS][MAX_COLS], int display, int user1, int horizontal, int vertical, int* hits, char see_board[MAX_ROWS][MAX_COLS], char kind);
int select_starting_player(void);
int ship_placement(void); 
void manual_placement(int *x_1, int *y_1, int *x_2, int *y_2, int size, char board[MAX_ROWS][MAX_COLS]);
void random_placement(int *x_1, int *y_1, int *x_2, int *y_2, int size, char board[MAX_ROWS][MAX_COLS]);
void player_shoot_ship(int *horizontal, int *vertical, char board[MAX_ROWS][MAX_COLS]);
void computer_shoot_ship(int *horizontal, int *vertical, char board[MAX_ROWS][MAX_COLS]);
int check_if_sunk(char board[MAX_ROWS][MAX_COLS], int* sunked_carrier, int* sunked_battleship , int* sunked_cruiser, int* sunked_submarine, int* sunked_destroyer);
void output_player_moves(FILE* output_file, int horizontal, int vertical, int user1, int hits, int* sunked_carrier, int* sunked_battleship, int* sunked_cruiser, int* sunked_submarine, int* sunked_destroyer);
void output_player_stats(FILE* output_file, stats player);
//FML GANG

#endif 
