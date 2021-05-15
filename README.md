# Software-Engineering-Project
Software Engineering Assignment 2
Enoch Elewa (20376351) 
Implementation of Othello:
How I implemented the Players:
I used a struct to implement the players’ the struct called "Player", the struct holds the players 
name using a string array and has an integer array to hold their score. I created a function called player Initialization, 
the function asks the Players to enter their name and allocates them a colour it also
initializes their scores to 2 as there are four starting pieces already on the board two for each player.

How I Implemented the Board:
I implemented the Board is using a struct. The struct contains a 2-dimensional 8x8 array of 
characters (row x column) this represents the board itself and contains the variable 
playerturn which is used to switch from player to player. 
I also created a function called printBoard which contained several printf statements and nested for loops in order to create an evenly 8x8 formed board with grids. 
InitalizeBoard is another function i produced used to initialize the board with spaces and place the starting 4 pieces 2 black and 2 white assigned to the players. 
It also initializes player turn to 0.
Saving the game to file:
The function save is used to append the time and date of when the game ended (I had to look up so ways to do this).
It also saves the Winner if there is one and their score depending on the output 
of the function Winnerdisplay which has the return statistic of the outcome of the game(eg. -1 ,means a tie) all of this gets 
saved into a file called Othello-result.txt as a requirement of the program functionality.

Ending the Game:
There are two functions that I created to end the game ScoreUpdate and Movedetection. 
Scoreupdate keeps track of the number of white pieces and black pieces on the board to update the score as well as keeping the total pieces. 
The variable filled is used to keep track of the total pieces on the board. This variable is compared to the constant Maximum discs which is 64. 
When the number of pieces is equal to 64 then one is returned to end the game. The Game has ended as all the 64 pieces have been used to fill the board.
I created moveDetection as a secondary way to end the game , this function calls for each possible input on updateBoard function (a function stated in Game logic) 
also setting the update parameter to 0, for player turn, if 1 is returned it means that we have some moves available for the players to make to play 
and player cannot pass otherwise there are no moves available, and the games is over.
Game Logic:
I created the UpdateBoard as multi-functional function to carry out of 3 functions. 
Update Board function first figures out the row and column from input, then it a set two variables matchCharacter and InsertedCharacter,
for example if the turn is of the WhitePlayer then matchCharacter will be 'B' and inserted Character will be 'W', because we want to insert 'W' on all places where 'B' is covered by 'W'.
We have 8 different cases basically a full 360 of the board (and at most we are running 2 or 3 cases in each input of user, (3 and 4 cases run on each input is very rare).
Then we run a loop according to the placement and check where we have matchCharacter lying between the insertedCharacter. after that, we do a  flip of the board, then check the status of it  (update the score and check the board is completed or not). 
Another thing the Update Board function was created to do is check if the user input is valid or not, 
here valid means the player piece is allowable to place where player is wanting.
 if it is not allowed then UpdateBoard does not change the board, and the user is asked to give a valid move as invalid move will be returned. 
If it is a valid move, it carries out the move by flipping the necessary tiles.
