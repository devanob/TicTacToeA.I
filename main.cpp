#include <iostream>
#include "BoardFieldGameState.h"
#include "AIPlayerTicTacToe.h"
using namespace std;
char maxPlayer = 'X';
char minPlayer = 'Y';
//flag to see if a player has played in a spot
#define NOPLAYER 100
int possibleWinninSpots(BoardFieldGame& gameBoard, char player){
   #define NOINSTANCE '+'
   int countWinningSpot = 0;
   char FirstInstance = BLANK;
   int numTypeLine= 0;
   //chech each row for winning spots
   for (unsigned int row = 0 ; row < GRIDSIZE; row++){//Row
       for (unsigned int column = 0 ; column < GRIDSIZE; column++){
           if (gameBoard.at(row,column) != BLANK){//BLANK CHECK
               if (numTypeLine == 0 ){ //CHECK NO TYPE DETECTED
                   numTypeLine++;
                   FirstInstance = gameBoard.at(row,column);
               }//END CHECK NO TYPE DETECTED
               else if (gameBoard.at(row,column)!= FirstInstance){ //two different types same row// cant win here
                   numTypeLine++;
                   break;
               } // END two different types same row// cant win here
               //else we got the same type that we found before
           }//END //BLANK CHECK
       }
       if (numTypeLine < 2 && (FirstInstance== player || FirstInstance == BLANK) ){
           countWinningSpot++;
       }
       FirstInstance = BLANK;
       numTypeLine= 0;

   }// END ROW
   //End Row check

   //check column for win

}
int evaluatioFunction(BoardFieldGame& board){

}
int main()
{
    BoardFieldGame board;
    AIPlayerTicTacToe PlayerOne('X','O',2);
    AIPlayerTicTacToe PlayerTwo('O','X',3);
    unsigned int row ;
    unsigned int colum;
    PlayerOne.play(board);
    ////
    PlayerTwo.play(board);
    //
    PlayerOne.play(board);
    PlayerTwo.play(board);
    //
    PlayerOne.play(board);
    board.drawBoard();

    std::cout << board.isGameState();







}
