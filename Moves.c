//
// Created by enoch on 04/05/2021.
//

#include "Moves.h"
#include "Player.h"
#include "Board.h"

#include <stdio.h>



int updateBoard(char a[], struct Board *b, int t, int update)
{

    if (a[0] == 'p') // If user input 'p' for passing  , if it is then return 0 otherwise 1
    {
        if (moveDetection(b, t)) // using  then it checks if the move is passable
        {
            printf("You can not pass your move right now.\n");
            return 1; // if it is not  then return 1 otherwise 0
        }
        else
            return 0;
    }
    else
    {
        int r, c;
        r = (a[0] - '0') - 1; // converting to int and subtracting 1 because index starts from zero

        char temp = 'a'; // temp variable will have  initial 'a' character stored in it , we will use  it to compare and iterate
        for (c = 0; c < 8; c++)
        {
            if (a[1] == temp)
                break;
            else
                temp++;
        }

        char matchCharacter, InsertCharacter;
        if (t) //if the player is the Black disc, then matchCharacter is W, and insertCharacter is B and otherwise */
        {
            matchCharacter = 'B';
            InsertCharacter = 'W';
        }
        else
        {
            matchCharacter = 'W';
            InsertCharacter = 'B';
        }

        struct Board prevBoard; //storing the current snapshot of the board
        int m, n;
        for (m = 0; m < 8; m++)
            for (n = 0; n < 8; n++)
                prevBoard.board[m][n] = b->board[m][n];

        int invalidMove = 1;
        if (b->board[r][c] == ' ') // here we have 8 possible cases where can made effect on board by the user input
        {
            if (b->board[r][c + 1] != ' ' && b->board[r][c + 1] == matchCharacter) //case for right side
            {
                int k, start = c, end = -1;  //storing the column index in start variable if we successfully found the Unmatched character in the row
                                               //after consecutive matched character then we are saving the end cell index
                for (k = c + 1; k < 8; k++)
                {
                    if (prevBoard.board[r][k] == matchCharacter)
                        continue;
                    else
                    {
                        if (prevBoard.board[r][k] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                if (end != -1) // if we found the match successfully then this will run
                {
                    if (update) //if this function is called for update then we update the board
                    {
                        for (k = start; k <= end; k++)
                            b->board[r][k] = InsertCharacter;
                    }

                    invalidMove = 0; // if we didn't find consecutive matched character between Unmatched character then this move is invalid
                }
                else
                {
                    invalidMove = 1;
                }
            }

            if (b->board[r][c - 1] != ' ' && b->board[r][c - 1] == matchCharacter) //case for left side
            {
                int k, start = c, end = -1;
                for (k = c - 1; k >= 0; k--)
                {
                    if (prevBoard.board[r][k] == matchCharacter)
                        continue;
                    else
                    {
                        if (prevBoard.board[r][k] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                if (end != -1)
                {
                    if (update)
                    {
                        for (k = end; k <= start; k++)
                            b->board[r][k] = InsertCharacter;
                    }

                    invalidMove = 0;
                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            if (b->board[r - 1][c] != ' ' && b->board[r - 1][c] == matchCharacter) //case for upper side
            {
                int k, start = r, end = -1;
                for (k = r - 1; k >= 0; k--)
                {
                    if (prevBoard.board[k][c] == matchCharacter)
                        continue;
                    else
                    {
                        if (prevBoard.board[k][c] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                if (end != -1)
                {
                    if (update)
                    {
                        for (k = end; k <= start; k++)
                            b->board[k][c] = InsertCharacter;
                    }

                    invalidMove = 0;
                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            if (b->board[r + 1][c] != ' ' && b->board[r + 1][c] == matchCharacter) //case for bottom side
            {
                int k, start = r, end = -1;
                for (k = r + 1; k < 8; k++)
                {
                    if (prevBoard.board[k][c] == matchCharacter)
                        continue;
                    else
                    {
                        if (prevBoard.board[k][c] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                if (end != -1)
                {
                    if (update)
                    {
                        for (k = start; k <= end; k++)
                            b->board[k][c] = InsertCharacter;

                    }

                    invalidMove = 0;
                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            if (b->board[r + 1][c + 1] != ' ' && b->board[r + 1][c + 1] == matchCharacter) //case for lower right diagonal
            {
                int k, start = c, end = -1;
                int temp = r + 1;
                for (k = c + 1; k < 8; k++)
                {
                    if (prevBoard.board[temp][k] == matchCharacter)
                        temp++;
                    else
                    {
                        if (prevBoard.board[temp][k] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                temp = r;
                if (end != -1)
                {
                    if (update)
                    {
                        for (k = start; k <= end; k++)
                            b->board[temp++][k] = InsertCharacter;
                    }

                    invalidMove = 0;
                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            if (b->board[r - 1][c - 1] != ' ' && b->board[r - 1][c - 1] == matchCharacter) //case for upper left diagonal
            {
                int k, l = r - 1, start = c, end = -1;

                for (k = c - 1; k >= 0; k--)
                {
                    if (prevBoard.board[l][k] == matchCharacter)
                    {
                        l--;
                    }
                    else
                    {
                        if (prevBoard.board[l][k] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                l = r;
                if (end != -1)
                {
                    if (update)
                    {
                        for (k = start; k != end; k--)
                            b->board[l--][k] = InsertCharacter;
                    }

                    invalidMove = 0;
                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            if (b->board[r - 1][c + 1] != ' ' && b->board[r - 1][c + 1] == matchCharacter) //case for upper right side
            {
                int k, start = r, end = -1;

                int temp = c + 1;

                for (k = r - 1; k >= 0; k--)
                {
                    if (prevBoard.board[k][temp] == matchCharacter)
                        temp++;
                    else
                    {
                        if (prevBoard.board[k][temp] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                temp = c;
                if (end != -1)
                {
                    if (update)
                    {
                        for (k = start; k >= end; k--)
                            b->board[k][temp++] = InsertCharacter;
                    }

                    invalidMove = 0;

                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            if (b->board[r + 1][c - 1] != ' ' && b->board[r + 1][c - 1] == matchCharacter) //case for lower left side
            {
                int k, start = r, end = -1;
                int temp = c - 1;
                for (k = r + 1; k < 8; k++)
                {
                    if (prevBoard.board[k][temp] == matchCharacter)
                        temp--;
                    else
                    {
                        if (prevBoard.board[k][temp] == InsertCharacter)
                            end = k;
                        break;
                    }
                }

                temp = c;
                if (end != -1)
                {
                    if (update)
                    {
                        for (k = start; k <= end; k++)
                            b->board[k][temp--] = InsertCharacter;
                    }

                    invalidMove = 0;
                }
                else
                {
                    if (invalidMove != 0)
                        invalidMove = 1;
                }
            }

            return invalidMove;

        }
        else
            return invalidMove;
    }
}

int moveDetection(struct Board *b, int t) { // Function to check whether the board has available moves for the players


    char r[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    char c[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char temp[2];
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            temp[0] = r[i]; // storing rows in temp
            temp[1] = c[j]; // storing  the columns in
            int x = updateBoard(temp, b, t, 0); // calling the update function to check if there are still available moves
            if (x == 0)
                return 1; // it return 1 if there are still moves left
        }
    }

    return 0;
}
