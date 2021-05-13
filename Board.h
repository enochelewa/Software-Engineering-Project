//
// Created by enoch on 04/05/2021.
//

#include "Player.h"

#ifndef SE_ASSIGNMENT2_BOARD_H
#define SE_ASSIGNMENT2_BOARD_H

struct Board
{
    char board[8][8];
    int playerTurn;
};

#endif //SE_ASSIGNMENT2_BOARD_H

void printBoard(int, int c, struct Board *Sboard, struct Player *p); // function to print the board
void initializeBoard(int, int c, struct Board *Sboard); // function to initialize  the board
int inputChecking(char[]); // function to check users input
void save(char data[], char WinnerName[], char score[]); // function to put the date, time and results of into a file
int scoreUpdate(struct Board *b, struct Player *p); // function to update the score