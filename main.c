#include <stdio.h>
#include <stdbool.h>
#include "Player.h"
#include "Board.h"
#include "Moves.h"


#define cl 8
#define row 8
#define maximumDiscs 64

int main(void)
{
    struct Board s_B1; //struct for Board
    player s_P; //struct for Player
    printf("***Welcome to Othello! ***\n");// Printing welcome othello Message
    playerInitialization(&s_P); //initializing the Players
    initializeBoard(row, cl, &s_B1); //initializing the Board
    printBoard(row, cl, &s_B1, &s_P); // Printing the board

    bool validMove = false;

    bool inGame = false; //inGame value is used for ending or starting the game
    char playerInput[3]; //playerInput holds the player input value


    while (inGame==false)
    {
        do {
            if (s_B1.playerTurn == 0)
                printf("%s (Black) Input: ", s_P.Player1); // Printing
            else
                printf("%s (White) Input: ", s_P.Player2);
            scanf("%s", &playerInput); // reading in the player's  input


            int r; //used for checking input result
            do {
                r = inputChecking(playerInput); // storing input inputChecking in r it returns 1 if the input is in the valid range of(1-8) and (a-h)otherwise it returns 0

                if (r != 1) {
                    printf("Input is wrong and outside bounds, Input Again: ");// telling the user that their input is outside bounds and that they should enter again
                    scanf("%s", &playerInput);// reading in their new input
                }
            } while (r == 0); // do while r is 0


            if (updateBoard(playerInput, &s_B1, s_B1.playerTurn, 1) == 1) // update function return 1 if the move by the user is not valid otherwise it changes/flips the board and returns 0
            {
                printf("%s is Invalid Move: \n", playerInput);
                if(s_B1.playerTurn == 0){
                    s_B1.playerTurn = 1;
                }else{
                    s_B1.playerTurn = 0;
                }
            }else{
                validMove = true;
            }
        }while (validMove==false);


        if (scoreUpdate(&s_B1, &s_P) == 1 ||  (moveDetection(&s_B1, 1) == 0 && moveDetection(&s_B1, 1)==0)) //scoreUpdate Board returns 1 if board is full otherwise it return 1 and in both cases update the score board
        { 									 //moveDetection return 0 if no moves left to play
            inGame = true;// So if the Board is full and there are no moves left end game

            printBoard(row, cl, &s_B1, &s_P);
            int result=winnerDisplay(&s_P);  // storing the return result of the winnerDisplay function in result to print out the winner for the file
            if(result==0)
            {
                char  scr[3];
                snprintf(scr, sizeof(scr), "%d", s_P.p2_Score);
                scr[2]='\n'; //converting the int to string
                save("Winner is ", s_P.Player2, scr ); //saving the data in the file
            }
            else if(result==1)
            {
                char  scr[3];
                snprintf(scr, sizeof(scr), "%d", s_P.p1_Score);
                scr[2]='\n';//converting the int to string
                save("Winner is : ", s_P.Player1, scr ); //saving the data in the file
            }
            else
            {
                char  scr[3];
                snprintf(scr, sizeof(scr), "%d", s_P.p1_Score);
                scr[2]='\n';//converting the int to string
                save("The Match is ", "Tie ", scr); //saving the data in the file
            }
        }
        else
        {

            printBoard(row, cl, &s_B1, &s_P);// printing board

            if (s_B1.playerTurn == 0)
                s_B1.playerTurn = 1;
            else
                s_B1.playerTurn = 0;
        }
    }

    return 0;
}
