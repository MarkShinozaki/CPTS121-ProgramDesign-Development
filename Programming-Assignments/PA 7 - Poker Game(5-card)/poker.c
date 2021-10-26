#include "Header.h"

void Game_rules(void) {

	printf("\tWELCOME TO DRAW-5 POKER\n");
	printf("\t-----------------------\n");
	printf("\n\t*GAME RULES*");
	printf("\n\t------------\n");
	printf("\n\t1. You will be dealt 5 cards\n");
	printf("\n\t2. You get to decide which cards and   \n\thow many you would like to exchange.\n");
	printf("\n\t3. You're trying to exchange your   \n\tcards to get the best set of cards you can.\n");
	printf("\n\t4. All the sets of cards you can get is listed below.\n");
	printf("\n\t*Sets of cards(Best to least in decending order*");
	printf("\n\t--------------------------------------------\n");
	printf("\n\tRoyal Flush - A four card straight flush with an Ace high\n");
	printf("\n\tStraight Flush - All five cards have the same suit that are in sequential order\n");
	printf("\n\t4 of a kind - 4 cards with the same number value\n");
	printf("\n\tFull House - 5 cards whre it contains three of a kind and a pair\n");
	printf("\n\tFlush - 5 cards where all cards are the same suit \n");
	printf("\n\tStraight - 5 cards in sequential order\n");
	printf("\n\t3 of a kind - a set of 3 of the same face \n");
	printf("\n\t2 pair - two sets of two cards with the face \n");
	printf("\n\tpair - two cards of the same value \n");
	printf("\n\tHigh card - The highest face value card\n");
	printf("\nPress Any Key to continue...\n");
	getch();
	system("cls");
}

// This is the shuffle function
void shuffle_deck(int deck[][13])
{
    int row = 0;    
    int column = 0; 
    int card = 0;   

    for (card = 1; card <= 52; card++)
    {
        do
        {
            row = rand() % 4;
            column = rand() % 13;
        } while (deck[row][column] != 0);
        deck[row][column] = card;
    }
}



// This is the deal functions
void deal_cards(int deck[][13], int hand[][2], char* suit[], char* face[], int* changecard)
{
    int r = 0, c;
    int row;
    int col;

    for (c = 1; c <= 5; c++)
    {
        for (row = 0; row <= 3; row++)
        {
            for (col = 0; col <= 12; col++)
            {
                if (deck[row][col] == *changecard)
                {
                    hand[r][0] = row;
                    hand[r][1] = col;
                    printf("\n[%d] %5s of %-8s \n", c, face[col], suit[row]);
                    ++r;
                }
            }
        }
        *changecard = *changecard + 1;
    }
}



//Finds if there is a pair
int Pair(int hand[][2], char* suit[], char* face[])
{
    int count[13] = { 0 };
    int r, f;

    for (r = 0; r < 5; r++)
    {
        count[hand[r][1]]++;
    }
    int mCount = 0;
    int pCount = 0;

    for (f = 0; f < 13; f++)
    {
        if (count[f] > mCount)
        {
            mCount = count[f];
        }
        
        if (count[f] == 2)
        {
            pCount++;
        }
    }
    if (mCount == 2 && pCount == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Finds if there is a set of pairs
int Pairs(int hand[][2], char* suit[], char* face[])
{
    int count[13] = { 0 };
    int r, f;

    for (r = 0; r < 5; r++)
    {
        count[hand[r][1]]++;
    }

    int mCount = 0;
    int pCount = 0;

    for (f = 0; f < 13; f++)
    {

        if (count[f] > mCount)
        {
            mCount = count[f];
        }
        if (count[f] == 2)
        {
            pCount++;
        }
    }

    if (mCount == 2 && pCount == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Finds if there is a three of a kind
int Three_Of_A_Kind(int hand[][2], char* suit[], char* face[])
{
    int count[13] = { 0 };
    int r, f;

    for (r = 0; r < 5; r++)
    {
        count[hand[r][1]]++;
    }

    int mCount = 0;
    int pCount = 0;

    for (f = 0; f < 13; f++)
    {
        if (count[f] > mCount)
        {
            mCount = count[f];
        }
        if (count[f] == 2)
        {
            pCount++;
        }
    }

    if (mCount == 3 && pCount != 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Finds if there is a four of a kind
int Four_Of_A_Kind(int hand[][2], char* suit[], char* face[])
{

    int count[13] = { 0 };

    int r, f;

    /* find out the frequency of cards with each rank */

    for (r = 0; r < 5; r++)
    {
        count[hand[r][1]]++;
    }

    int mCount = 0;
    int pCount = 0;

    /* find highest frequency and pairs count */

    for (f = 0; f < 13; f++)
    {
        if (count[f] > mCount)
        {
            mCount = count[f];
        }
        if (count[f] == 2)
        {
            pCount++;
        }
    }

    if (mCount == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Straight(int hand[][2], char* suit[], char* face[])
{

    int count[13] = { 0 };
    int r, f;

    for (r = 0; r < 5; r++)
    {
        count[hand[r][1]]++;
    }

    int son = 0;

    for (f = 0; f < 13; f++)
    {
        if (count[f] == 1)
        {
            son++;
        }
        else
        {
            son = 0;
        }
    }

    if (son == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Finds if there is a flush

int Flush(int hand[][2], char* suit[], char* face[])
{
    int count[4] = { 0 };
    int r, s;

    for (r = 0; r < 5; r++)
    {
        count[hand[r][0]]++;
    }

    int mfc = 0;

    for (s = 0; s < 4; s++)
    {
        if (count[s] > mfc)
        {
            mfc = count[s];
        }
    }

    if (mfc == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// This function determines the outcomes of the hands

int Better_Hand(int hand1[][2], int hand2[][2], char* suit[], char* face[])
{
    
    if (Four_Of_A_Kind(hand1, suit, face) == 1 && Four_Of_A_Kind(hand2, suit, face) == 0)
        return 1;
    else if (Four_Of_A_Kind(hand1, suit, face) == 0 && Four_Of_A_Kind(hand2, suit, face) == 1)
        return -1;
    else
    {
        if (Flush(hand1, suit, face) == 1 && Flush(hand2, suit, face) == 0)
        {
            return 1;
        }
        else if (Flush(hand1, suit, face) == 0 && Flush(hand2, suit, face) == 1)
        {
            return -1;
        }
        else
        {
            if (Straight(hand1, suit, face) == 1 && Straight(hand2, suit, face) == 0)
            {
                return 1;
            }
            else if (Straight(hand1, suit, face) == 0 && Straight(hand2, suit, face) == 1)
            {
                return -1;
            }
            else
            {
                if (Three_Of_A_Kind(hand1, suit, face) == 1 && Three_Of_A_Kind(hand2, suit, face) == 0)
                {
                    return 1;
                }
                else if (Three_Of_A_Kind(hand1, suit, face) == 0 && Three_Of_A_Kind(hand2, suit, face) == 1)
                {
                    return -1;
                }
                else
                {
                    if (Pairs(hand1, suit, face) == 1 && Pairs(hand2, suit, face) == 0)
                    {
                        return 1;
                    }
                    else if (Pairs(hand1, suit, face) == 0 && Pairs(hand2, suit, face) == 1)
                    {
                        return -1;
                    }
                    else
                    {
                        if (Pair(hand1, suit, face) == 1 && Pair(hand2, suit, face) == 0)
                        {
                            return 1;
                        }
                        else if (Pair(hand1, suit, face) == 0 && Pair(hand2, suit, face) == 1)
                        {
                            return -1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}


void Check_hand(int hand[][2], char* suit[], char* face[])
{
    /* Evaluate dealer's hand */
    if (Pair(hand, suit, face))
    {
        printf("\nThe hand contains a pair\n ");
    }
    else
    {
        printf("\nThe hand does not contain a pair\n ");
    }
    if (Pairs(hand, suit, face))
    {
        printf("\nThe hand contains two pairs\n ");
    }
    else
    {
        printf("\nThe hand does not contain two pairs\n ");
    }
    if (Three_Of_A_Kind(hand, suit, face))
    {
        printf("\nThe hand contains three of a kind\n ");
    }
    else
    {
        printf("\nThe hand does not contain three of a kind\n ");
    }
    if (Four_Of_A_Kind(hand, suit, face))
    {
        printf("\nThe hand contains four of a kind\n ");
    }
    else
    {
        printf("\nThe hand does not contain four of a kind\n ");
    }
    if (Flush(hand, suit, face))
    {
        printf("\nThe hand contains a flush\n ");
    }
    else
    {
        printf("\nThe hand does not contain a flush\n ");
    }
    if (Straight(hand, suit, face))
    {
        printf("\nThe hand contains a straight\n");
    }
    else
    {
        printf("\nThe hand does not contain a straight\n ");
    }
}



/* Display a hand */
void print_hand(int hand[][2], char* suit[], char* face[])
{
    for (int r = 0; r < 5; r++)
    {
        printf("\n[%d] %5s of %-8s \n", r + 1, face[hand[r][1]], suit[hand[r][0]]);
    }
}
