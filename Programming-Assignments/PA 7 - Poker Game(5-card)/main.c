/*
	Computer Science 121
	Author: Mark Shinozaki
	Dates Worked on:
	- 11/30/20
	Assignment: Programming Assignment #7
	Description: Creating 5-draw poker in C language 

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Header.h"


int main(void)

{
    Game_rules();
    
    char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    
    int deck[4][13];

    
    int dealerHand[5][2];
    int playerHand[5][2];

    int row, col;
    int card = 1; 
    int dCards2Replace = 0;
    int playerWon = 0, dealerWon = 0;
    
    for (row = 0; row <= 3; row++)
    {
        for (col = 0; col <= 12; col++)
        {
            deck[row][col] = 0;
        }
    }
    srand(time(NULL));
 
    shuffle_deck(deck);
    
    for (int game = 0; game < 5; game++)
    {
        printf("\nGame %d: ", game + 1);
        printf("\n------------\n");
        deal_cards(deck, dealerHand, suit, face, &card);
        int rCard = 0;
        
        if (Three_Of_A_Kind(dealerHand, suit, face))
        {
            int threeface = 0;
            int count[13] = { 0 };
            int r;
            
            for (r = 0; r < 5; r++)
            {
                count[dealerHand[r][1]]++;
                if (count[dealerHand[r][1]] == 3)
                {
                    threeface = dealerHand[r][1];
                    break;
                }
            }
            
            for (int r1 = 0; r1 < 5; r1++)
            {
                if (dealerHand[r1][1] != threeface)
                {
                    
                    for (row = 0; row <= 3; row++)
                    {
                        for (col = 0; col <= 12; col++)
                        {
                            if (deck[row][col] == card)
                            {
                                dealerHand[r1][0] = row;
                                dealerHand[r1][1] = col;
                            }

                        }
                    }
                    card = card + 1;
                }
            }
        }
        else if (Pairs(dealerHand, suit, face))
        {
            int twopairface = 0;
            int count[13] = { 0 };
            int r;
            
            for (r = 0; r < 5; r++)
            {
                count[dealerHand[r][1]]++;
            }
            for (r = 0; r < 13; r++)
            {
                if (count[r] == 1)
                {
                    twopairface = r;
                    break;
                }
            }
            
            for (int r1 = 0; r1 < 5; r1++)
            {
                if (dealerHand[r1][1] == twopairface)
                {
                    
                    for (row = 0; row <= 3; row++)
                    {
                        for (col = 0; col <= 12; col++)
                        {
                            if (deck[row][col] == card)
                            {
                                dealerHand[r1][0] = row;
                                dealerHand[r1][1] = col;
                            }
                        }
                    }
                    card = card + 1;
                }
            }
        }
        else
        {
            int apairface = 0;
            int count[13] = { 0 };
            int r;
            
            for (r = 0; r < 5; r++)
            {
                count[dealerHand[r][1]]++;
            }
            
            for (r = 0; r < 13; r++)
            {
                if (count[r] == 2)
                {
                    apairface = r;
                    break;
                }
            }
            
            for (int r1 = 0; r1 < 5; r1++)
            {
                if (dealerHand[r1][1] != apairface)
                {
                    
                    for (row = 0; row <= 3; row++)
                    {
                        for (col = 0; col <= 12; col++)
                        {
                            if (deck[row][col] == card)
                            {
                                dealerHand[r1][0] = row;
                                dealerHand[r1][1] = col;
                            }
                        }
                    }
                    card = card + 1;
                    if (apairface == 0 && r1 == 2)
                        break;
                }
            }
        }
        printf("\nPlayer hand: ");
        printf("\n------------\n");
        deal_cards(deck, playerHand, suit, face, &card);
        print_hand(playerHand, suit, face);
        printf(" ");
        
        Check_hand(playerHand, suit, face);
        printf(" ");
        
        printf("\nHow many cards do you want to replace: ");
        scanf("%d", &dCards2Replace);
        
        for (int i = 0; i < dCards2Replace; i++)
        {
            printf("\nWhich card you want to replace: ");
            scanf("%d", &rCard);
            
            for (row = 0; row <= 3; row++)
            {
                for (col = 0; col <= 12; col++)
                {
                    if (deck[row][col] == card)
                    {
                        printf("\n %s of %s is replaced with ", face[playerHand[rCard - 1][1]], suit[playerHand[rCard - 1][0]]);
                        playerHand[rCard - 1][0] = row;
                        playerHand[rCard - 1][1] = col;
                        printf(" %s of %s ", face[col], suit[row]);
                    }
                }
            }
            card = card + 1;
        }
        
        printf(" \nPlayer's hand after replaces: ");
        print_hand(playerHand, suit, face);
        printf(" ");
        
        
        Check_hand(playerHand, suit, face);
        printf(" ");

        
        printf(" \nDealer hand: ");
        printf("\n------------\n");
        print_hand(dealerHand, suit, face);
        printf(" ");
        
        Check_hand(dealerHand, suit, face);

        if (Better_Hand(playerHand, dealerHand, suit, face) > 0)
        {
            printf("\nPlayerHand is better than dealerHand ");
            playerWon++;
        }
        else if (Better_Hand(playerHand, dealerHand, suit, face) < 0)
        {
            printf("\nDealerHand is better than playerHand ");
            dealerWon++;
        }
        else
        {
            printf("\nBoth hands are equal in ranking ");
        }
    }
    printf("\nScore: Player won: %d game(s)\n Dealer won: %d game(s)\n ", playerWon, dealerWon);
    return 0;

}
