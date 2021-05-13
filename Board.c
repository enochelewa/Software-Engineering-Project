//
// Created by enoch on 04/05/2021.
//

#include "Player.h"
#include "Board.h"
#include "Moves.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

#define maximumDiscs 64 // max number of discs
void printBoard(int r, int c, struct Board *b, player *p) //Function print the Board
{

    int i, j;
    // printing the names of the players with their assigned colours and  their initial scores of 2
    printf("\tScore: %s (Black) %d:%d %s (White)\n", p->Player1, p->p1_Score, p->p2_Score, p->Player2);
    printf("\t    a   b   c   d   e   f   g   h\n"); // printing the top of the board
    printf("\t   --- --- --- --- --- --- --- ---\n"); // printing lines at the top of board
    for (i = 0; i < r; i++)
    {
        printf("\t%d |", i+1); //printing vertical lines at the  left side of the board from 1-8

        for (j = 0; j < c; j++)
            printf(" %c |", b->board[i][j]); //printing the rest of the vertical lines to make the boxes

        printf("\n\t   --- --- --- --- --- --- --- ---\n"); // printing the lines in between the board
    }
    printf("\t    a   b   c   d   e   f   g   h\n"); // printing  the bottom of the board
}

int inputChecking(char a[])
{

    if (strlen(a) == 1) //if length is one
    {
        if (a[0] == 'p') // then it must be a single 'p' character otherwise error
            return 1;
        else
            return 0;
    }
    else
    {
        if (((a[0] - '0') >= 1 && (a[0] - '0') <= 8) && ((a[1]) >= 'a' && (a[1]) <= 'h')) //checking whether the input  is in the range  of(1-8) and (a-h)
            return 1;
        else
            return 0;
    }
}

void initializeBoard(int r, int c, struct Board *b)
{

    int i, j;


    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            b->board[i][j] = ' '; // making gaps between the board
    }

    //setting the starting 4 colours of the board inplace
    b->board[3][3] = 'W';
    b->board[3][4] = 'B';

    b->board[4][3] = 'B';
    b->board[4][4] = 'W';

    b->playerTurn=0;

}

void save(char data[], char WinnerName[], char score[])
{
    /*Function to store the results on the disk having date, time and result*/

    time_t now = time(0);
    char *dt = ctime(&now);		/*getting the time and removing the leading \n character*/
    dt[strlen(dt) - 1]='\0';

    FILE *fp;
    fp=fopen("C:/Users/enoch/CLionProjects/untitled23/othello-results.txt","a");//Opening the file in the append mode
    if(fp == NULL)
    {
        printf("Error occurred while creating the file.\n");//error message is printed
    }
    else
    {  //writing the date and time , The winners  name and score and into the file
        fputs(dt,fp);
        fputs(" : ",fp);
        fputs(data,fp);
        fputs(WinnerName,fp);
        fputs(" >>>  with the score of >>> ",fp);
        fputs(score,fp);
        printf("Result has been saved on the disk with file name \'othello-results.txt\' \n");
        fclose(fp);
    }

}
int scoreUpdate(struct Board *b, player *p)
{
    //This function update the score and return 1 if the board is full otherwise it return 0
    int whiteCount = 0, blackCount = 0, filled = 0;
    int i, j;	//loop variables
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (b->board[i][j] == 'W') //checking whole board for whi
            {
                whiteCount++; // counting the number of white pieces on the board
                filled++; // counting the number of pieces
            }

            if (b->board[i][j] == 'B')
            {
                blackCount++; // counting the number of white pieces on the board
                filled++; // counting the number of pieces
            }
        }
    }

    p->p1_Score = blackCount; // storing the black count of pieces in player 1's score
    p->p2_Score= whiteCount; // storing the white  count of pieces in player 2's score
    if (filled == maximumDiscs)	//max. entries in board is 64 so if filled is = to maximumDiscs then the board is full and game is over
        return 1; // return 1 if the board is full
    return 0;
}