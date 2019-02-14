#ifndef BOARDFIELDGAME_H
#define BOARDFIELDGAME_H
#include <memory>
#include <vector>

//Flag If Player HAs Won
#define WON 1
#define DRAW '-'
#define NOGOINGGAME '|'

#define GRIDSIZE 3
#define BLANK '*'
#include <memory>
#include <algorithm>
#include <iostream>
#include <iomanip>
class BoardFieldGame
{
    public:
        BoardFieldGame();
        BoardFieldGame(const BoardFieldGame& boardState) ;
        BoardFieldGame(const BoardFieldGame& boardState,unsigned  int row, unsigned int  column, char playerCharcter) ;
        //Begin-playAt --> plays at The Player With Symbol playerChacter At row = row+1 and column  column + 1
        void playAt(unsigned  int row, unsigned int  column, char playerCharcter);
        //End
        //Begin - drawBoard --> draws the current playing board
        void drawBoard();
         //End 
         //Generate New States Based On Current State 
        //throw an error if the state is a terminal state
         std::vector<std::unique_ptr<BoardFieldGame>> generateStates(char playerCharcter);
         //specify which player has won
         //if draw return draw
         char isGameState();
        //End
        
        //Set Utiltity For Node and Get Utility
         int getUtilityValue() const;
         void setUtilityValue(int value);

private:
         int utilityValue;
         // Begin -The Position The Player Made That Lead To This Positon
        unsigned int row_played;
        unsigned int column_played;
        //End 
        //Data Structure Board
         std::vector<std::vector<char>> gameBoard;
        
        


};

#endif // BOARDFIELDGAME_H
