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

}

BoardFieldGame::BoardFieldGame(const BoardFieldGame &boardState)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;


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
    //

}

void  BoardFieldGame::playAt(unsigned int row, unsigned int column, char playerCharcter)
{
    //If the move is legal then play playerCharacter At row, colum

    if (gameBoard.at(row).at(column) == BLANK){//throw issue eror if outof bound i
        gameBoard[row][column] = playerCharcter;
    }
    else {
        std::runtime_error("You Cannot Play There At");
    }
}

void BoardFieldGame::drawBoard()
{
    std::cout <<std::endl<<"-----------------------" <<std::endl;
    for (unsigned int i = 0 ; i < gameBoard.size(); i++){
        for (unsigned int y = 0 ; y < gameBoard.size() ; y++){
            if (gameBoard[i][y] != BLANK){
                std::cout <<std::right << std::setw(7) << gameBoard[i][y] << " | ";
            }
            else {
                std::cout <<std::right << std::setw(7)<< " " << " | ";
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::unique_ptr<BoardFieldGame> > BoardFieldGame::generateStates(char playerCharcter)
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

int BoardFieldGame::isGameState()
{


     // any of the rows is same
     for (int i=0; i< GRIDSIZE; i++)
     {
      if(gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][1]==gameBoard[i][2] && gameBoard[i][0]!=0)
      {
        return gameBoard[i][0];
      }
     }

     // any of the columns is same
     for(int i=0; i< GRIDSIZE; i++)
     {
      if (gameBoard[0][i]==gameBoard[1][i] && gameBoard[1][i]==gameBoard[2][i] && gameBoard[0][i]!=0)
      {
        return gameBoard[0][i];

      }
     }

     // 1st diagonal is same
     if(gameBoard[0][0]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][2] && gameBoard[0][0]!=0)
     {
        return gameBoard[0][0];
     }

     // 2nd diagonal is same
     if(gameBoard[0][2]==gameBoard[1][1] && gameBoard[1][1]==gameBoard[2][0] && gameBoard [0][2]!=0)
     {
      return gameBoard[0][2];

     }

     // if we reached here nobody has won yet

     // if any empty box on gameBoard then play on
     for(int i=0; i<=2; i++)
     {
      for(int j=0; j<=2; j++)
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
