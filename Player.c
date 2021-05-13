//
// Created by enoch on 04/05/2021.
//

#include "Player.h"

#include "Moves.h"
#include <stdio.h>
#include <string.h>

#define cl 8 // max column
#define row 8 // max number of rows
#define maximumDiscs 64 // max number of discs

void playerInitialization(player *p) // function to initialize players names and scores
{
    //Takes the players Struct and ask players to enter names
    printf("Enter name of Player 1 (Black): "); // asking player 2 to enter their name
    fgets(p->Player1, 50, stdin); //using fgets to read the name and store it in  Player1

    p->Player1[strlen(p->Player1) - 1] = '\0'; // Stripping  the extra  newline character

    printf("\nEnter name of Player 2 (White): "); // asking player 2 to enter their name
    fgets(p->Player2, 50, stdin); //using fgets to read the name and store it in  Player2
    p->Player2[strlen(p->Player2) - 1] = '\0'; // Stripping the extra newline character

    p->p1_Score = 2; // initializing player 1's score to 2
    p->p2_Score = 2; // initializing player 2's score to 2

}


int winnerDisplay(player *p) // function to display the Winner of the game
{

    int s1 = p->p1_Score; // storing player 1's score in s1
    int s2 = p->p2_Score; // storing player 2's score in s2
    if (s1 > s2) // if player 1's score is greater
    {
        printf("%s is Winner with the score of %d\n", p->Player1, s1); //Printing out the player 1 is the winner and player 1's score
        return 1; //return 1 if player 2 is the winner
    }

    else if (s1 == s2) // if the two players have the same number of their pieces (W/B) on the board
    {
        printf("Game is Tied\n"); // The game is tied is printed
        return -1; // returns -1 if the game is tie
    }

    else
    {
        printf("%s is Winner with the score of %d \n", p->Player2, s2); //Printing out the player 2 is the winner and player 2's score
        return 0; // returns 0 if  player two is winner
    }
}
