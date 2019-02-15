#include "BoardFieldGameState.h"
#include <iostream>
BoardFieldGame::BoardFieldGame()
{
    this->row_played = 0;
    this->column_played= 0;
    //Intialize With All Blanks
    std::vector<std::vector<char> > internalDat(GRIDSIZE,std::vector<char>(GRIDSIZE,BLANK));
    //Set Board Game Data Structure
    this->gameBoard = std::move(internalDat);
    this->utilityValue = 0;
    this->depth =0;//depth always start off as zero as a rule

}

BoardFieldGame::BoardFieldGame(const BoardFieldGame &boardState)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;
    this->depth = boardState.depth;


}

BoardFieldGame & BoardFieldGame::operator =(const BoardFieldGame &boardState)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;
    return *this;
}

BoardFieldGame::BoardFieldGame(BoardFieldGame &&boardState)
{
    //Move Contructor//
    this->row_played = std::move(boardState.row_played);
    this->column_played = std::move(boardState.column_played);
    this->gameBoard = std::move(boardState.gameBoard);
    this->utilityValue = std::move(boardState.utilityValue);

}

BoardFieldGame &BoardFieldGame::operator =(BoardFieldGame &&boardState)
{
    //Move operator//
    this->row_played = std::move(boardState.row_played);
    this->column_played = std::move(boardState.column_played);
    this->gameBoard = std::move(boardState.gameBoard);
    this->utilityValue = std::move(boardState.utilityValue);
    return *this;

}

BoardFieldGame::BoardFieldGame(const BoardFieldGame &boardState, unsigned int row, unsigned int column, char playerCharcter)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;
    //Player playerCharacter At Row
    gameBoard[row][column] = playerCharcter;
    this->row_played = row;
    this->column_played = column;
    depth = boardState.depth + 1;
    //

}

void  BoardFieldGame::playAt(unsigned int row, unsigned int column, char playerCharcter)
{
    //If the move is legal then play playerCharacter At row, colum

    if (gameBoard.at(row).at(column) == BLANK){//throw issue eror if outof bound i
        gameBoard[row][column] = playerCharcter;
    }
    else {
        throw std::runtime_error("You Cannot Play There Another Tile Has Already Taken");
    }
}

void BoardFieldGame::drawBoard()
{
    std::cout <<std::endl<<"---------------------------------" <<std::endl;
    for (unsigned int i = 0 ; i < gameBoard.size(); i++){
        for (unsigned int y = 0 ; y < gameBoard.size() ; y++){
            if (gameBoard[i][y] != BLANK){
                std::cout <<std::right << std::setw(2) << gameBoard[i][y] ;
                if (y < GRIDSIZE -1 ){
                    std::cout << " | ";
                }
            }
            else {
                std::cout <<std::right << std::setw(2)<< " ";
                if (y < GRIDSIZE -1 ){
                    std::cout << " | ";
                }
            }

        }

        std::cout << std::endl;

    }
    std::cout <<std::endl<<"---------------------------------" <<std::endl;
}

std::vector<std::unique_ptr<BoardFieldGame> > BoardFieldGame::generateStates(char playerCharcter) const
{
    std::vector<std::unique_ptr<BoardFieldGame>> movesSet;
    for (unsigned int  row =  0 ; row < gameBoard.size() ; row++){
        for (unsigned int column = 0 ; column < gameBoard.size() ; column++){
            if (gameBoard[row][column] == BLANK){ // if we have a free spot generate a possible outcome
                std::unique_ptr<BoardFieldGame> gameState(new BoardFieldGame(*this,row,column, playerCharcter));
                movesSet.push_back(std::move(gameState));
            }
        }
    }
    return std::move(movesSet);

}

char BoardFieldGame::isGameState()
{


     // any of the rows is same
     for (int i=0; i< GRIDSIZE; i++)
     {
      if(gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][1]==gameBoard[i][2] && gameBoard[i][0]!=BLANK)
      {
        return gameBoard[i][0];
      }
     }

     // any of the columns is same
     for(unsigned int i=0; i< GRIDSIZE; i++)
     {
      if (gameBoard[0][i]==gameBoard[1][i] && gameBoard[1][i]==gameBoard[2][i] && gameBoard[0][i]!=BLANK)
      {
        return gameBoard[0][i];

      }
     }

     // 1st diagonal is same
     if(gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2] && gameBoard[0][0]!=BLANK)
     {
        return gameBoard[0][0];
     }

     // 2nd diagonal is same
     if(gameBoard[0][2]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][0] && gameBoard [0][2]!=BLANK)
     {
      return gameBoard[0][2];

     }

     // if we reached here nobody has won yet

     // if any empty box on gameBoard then play on
     for(unsigned int i=0; i<=2; i++)
     {
      for(unsigned int j=0; j<=2; j++)
      {
          //NO ONE HAS WON YET
       if(gameBoard[i][j]==BLANK)
       {

           return NOGOINGGAME;
       }
      }
     }


     return DRAW;

}

int BoardFieldGame::getUtilityValue() const
{
    return utilityValue;
}

void BoardFieldGame::setUtilityValue(int value)
{
    utilityValue = value;
}
const char& BoardFieldGame::at(unsigned int &row, unsigned int &column) const
{
    //might throw an exception if index bound  is beyond capicity//
    return gameBoard.at(row).at(column);
}

unsigned int BoardFieldGame::getRow_played() const
{
    return row_played;
}

unsigned int BoardFieldGame::getColumn_played() const
{
    return column_played;
}

unsigned int BoardFieldGame::getDepth() const
{
    return depth;
}

void BoardFieldGame::setDepth(unsigned int value)
{
    depth = value;
}
