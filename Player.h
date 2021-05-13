//
// Created by enoch on 04/05/2021.
//


#ifndef SE_ASSIGNMENT2_PLAYER_H
#define SE_ASSIGNMENT2_PLAYER_H

typedef struct Player // player Struct
{
    char Player1[50]; // variable for player 1's name
    char Player2 [50];// variable for player 2's name

    int p1_Score; // variable for player 1's Score
    int p2_Score; // variable for player 2's Score

}player;


#endif //SE_ASSIGNMENT2_PLAYER_H

void playerInitialization(struct Player *p); // function to initialize player
int winnerDisplay(struct Player *p); // function to display the winner