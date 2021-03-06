#ifndef BOARDFIELDGAME_H
#define BOARDFIELDGAME_H
#include <memory>
#include <vector>

//Flag fIf Player HAs Won
#define WON 1
#define DRAW '-'
#define ONGOING '|'
#define BLANK '*'
#include <memory>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <exception>

#include <limits>
//Limits
/**
 * @brief The BoardFieldGame class- Represent A Board Instance
 */
class BoardFieldGame
{

    public:
        BoardFieldGame(unsigned int gridSize = 3);
        //Copy contructor and copy operator
        BoardFieldGame(const BoardFieldGame& boardState) ;
        BoardFieldGame& operator =(const BoardFieldGame& boardState);
        //End
         //Move contructor and move operator
        BoardFieldGame(BoardFieldGame &&boardState) ;
        BoardFieldGame& operator =(BoardFieldGame&& boardState);
        //End
        BoardFieldGame(const BoardFieldGame& boardState,unsigned  int row, unsigned int  column, char playerCharcter) ;
        //Begin-playAt --> plays at The Player With Symbol playerChacter At row = row+1 and column  column + 1
        void playAt(unsigned  int row, unsigned int  column, char playerCharcter);
        //End
        //Begin - drawBoard --> draws the current playing board
        void drawBoard() const;
         //End 
         //Generate New States Based On Current State 
        //throw an error if the state is a terminal state
         std::vector<std::unique_ptr<BoardFieldGame>> generateStates(char playerCharcter) const ;
         //specify which player has won
         //if draw return draw
         char isGameState() const;
        //End
        //Set Utiltity For Node and Get Utility
         int getUtilityValue() const;
         void setUtilityValue(int value);
         //get  the play at row, column user can not modify internel state//
         const char &at(unsigned int& row, unsigned int& column) const;
         //get the row played for this instance
         unsigned int getRow_played() const;
         //get the column played for this instance
         unsigned int getColumn_played() const;
        //get the depth of the search tree
         unsigned int getDepth() const;
         void setDepth(unsigned int value);
        //resets the board = non-terminal
         void reset();

         //Getter And Setter Funciton


         unsigned int getGridSize() const;
         //
         void setGridSize(unsigned int value);
         bool nextChildState(char playerCharacter, std::shared_ptr<BoardFieldGame>& childState);

private:
         //the utility value of this board
         int utilityValue;
         unsigned int depth;
         // Begin -The Position The Player Made That Lead To This Positon
        unsigned int row_played=56565;
        unsigned int column_played=56565;
        //End 
        //Data Structure Board
         std::vector<std::vector<char>> gameBoard;
         unsigned int gridSize;
         std::shared_ptr<BoardFieldGame> childrenBoard = nullptr;
         unsigned int cached_last_row_played = 0;
        unsigned  int cached_last_colum_played = 0;
        BoardFieldGame* Id = this;


        
        


};

#endif // BOARDFIELDGAME_H
