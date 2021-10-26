#ifndef PokerGame
#define PokerGame

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void Game_rules(void);

void shuffle_deck(int deck[][13]); 

void deal_cards(int deck[][13], int hand[][2], char* suit[], char* face[], int*); 

int Pair(int hand[][2], char* suit[], char* face[]); 

int Pairs(int hand[][2], char* suit[], char* face[]); 

int Three_Of_A_Kind(int hand[][2], char* suit[], char* face[]); 

int Four_Of_A_Kind(int hand[][2], char* suit[], char* face[]); 

int Straight(int hand[][2], char* suit[], char* face[]); 

int Flush(int hand[][2], char* suit[], char* face[]);

int Better_Hand(int hand1[][2], int hand2[][2], char* suit[], char* face[]); 

void Check_hand(int hand[][2], char* suit[], char* face[]); 

void print_hand(int hand[][2], char* suit[], char* face[]); 





#endif
