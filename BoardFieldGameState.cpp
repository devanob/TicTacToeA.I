#include "BoardFieldGameState.h"
#include <iostream>
/**
 * @brief Construct a new Board Field Game:: Board Field Game object
 * 
 */
BoardFieldGame::BoardFieldGame(unsigned int gridSize)
{
    this->row_played = 0;
    this->column_played= 0;
    this->setGridSize(gridSize);
    //Intialize With All Blanks
    std::vector<std::vector<char> > internalDat(this->gridSize,std::vector<char>(this->gridSize,BLANK));
    //Set Board Game Data Structure
    this->gameBoard = std::move(internalDat);
    this->utilityValue = 0;
    this->depth =0;//depth always start off as zero as a rule

}
/**
 * @brief Construct a new Board Field Game:: Board Field Game object- Copy Contructor
 * 
 * @param boardState - a board instance to be copied from or target
 */
BoardFieldGame::BoardFieldGame(const BoardFieldGame &boardState)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;
    this->depth = boardState.depth;
    this->setGridSize(boardState.getGridSize());


}
/**
 * @brief Copy Operator
 * 
 * @param boardState -a board instance to be copied from or target
 *
 * @return BoardFieldGame& 
 */
BoardFieldGame & BoardFieldGame::operator =(const BoardFieldGame &boardState)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;
    this->setGridSize(boardState.gridSize);
    return *this;
}
/**
 * @brief Construct a new Board Field Game:: Board Field Game object Move Contructor
 * 
 * @param boardState -a board instance to be copied from or target
 */
BoardFieldGame::BoardFieldGame(BoardFieldGame &&boardState)
{
    //Move Contructor//
    this->row_played = std::move(boardState.row_played);
    this->column_played = std::move(boardState.column_played);
    this->gameBoard = std::move(boardState.gameBoard);
    this->utilityValue = std::move(boardState.utilityValue);
    this->gridSize = std::move(boardState.gridSize);
    this->depth = std::move(boardState.depth);
}
/**
 * @brief - Move Operator 
 * 
 * @param boardState -a board instance to be copied from or target
 * @return BoardFieldGame& returns a reference to this instance
 */
BoardFieldGame &BoardFieldGame::operator =(BoardFieldGame &&boardState)
{
    //Move operator//
    this->row_played = std::move(boardState.row_played);
    this->column_played = std::move(boardState.column_played);
    this->gameBoard = std::move(boardState.gameBoard);
    this->utilityValue = std::move(boardState.utilityValue);
    this->gridSize = std::move(boardState.gridSize);
    this->depth = std::move(boardState.depth);
    return *this;

}
/**
 * @brief Construct a new Board Field Game:: Board Field Game object given a row, colum and player character symbol
 * 
 * @param boardState -a board instance to be copied from or target
 * @param row - which row was played
 * @param column - whoch column was played 
 * @param playerCharcter - player character symbol 
 */
BoardFieldGame::BoardFieldGame(const BoardFieldGame &boardState, unsigned int row, unsigned int column, char playerCharcter)
{
    //Copy Contructor//
    this->row_played = boardState.row_played;
    this->column_played = boardState.column_played;
    this->gameBoard = boardState.gameBoard;
    this->utilityValue = boardState.utilityValue;
    //Player playerCharacter At Row, Column 
    gameBoard[row][column] = playerCharcter;
    this->row_played = row;
    this->column_played = column;
    depth = boardState.depth + 1;
    this->gridSize = boardState.gridSize;
    //

}
/**
 * @brief - Play A Character At row and column in the player space
 * 
 * @param row  - row to be played 
 * @param column  - column to be played 
 * @param playerCharcter - player symbol 
 */
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
/**
 * @brief Draw An Instance Of The Board - XO Board 
 * 
 */
void BoardFieldGame::drawBoard() const
{
    std::cout <<std::endl<<"---------------------------------" <<std::endl;
    for (unsigned int i = 0 ; i < gameBoard.size(); i++){
        for (unsigned int y = 0 ; y < gameBoard.size() ; y++){
            if (gameBoard[i][y] != BLANK){
                std::cout <<std::internal << std::setw(2) << gameBoard[i][y] ;
                if (y < this->gridSize -1 ){
                    std::cout << " | ";
                }
            }
            else {
                std::cout <<std::internal << std::setw(2)<< " ";
                if (y < this->gridSize -1 ){
                    std::cout << " | ";
                }
            }

        }

        std::cout << std::endl;

    }
    std::cout <<std::endl<<"---------------------------------" <<std::endl;
}
/**
 * @brief - Generates A Set Of Possilbe Moves Given A Player Character
 * 
 * @param playerCharcter 
 * @return std::vector<std::unique_ptr<BoardFieldGame> > 
 */
std::vector<std::unique_ptr<BoardFieldGame> > BoardFieldGame::generateStates(char playerCharcter) const
{
    std::vector<std::unique_ptr<BoardFieldGame>> movesSet; //empty vector of BoardFieldGames
    for (unsigned int  row =  0 ; row < gameBoard.size() ; row++){ //Lopps Through each Row 
        for (unsigned int column = 0 ; column < gameBoard.size() ; column++){ //Loop through each colum
            if (gameBoard[row][column] == BLANK){ // if we have a free spot generate a possible outcome
                std::unique_ptr<BoardFieldGame> gameState(new BoardFieldGame(*this,row,column, playerCharcter));
                movesSet.push_back(std::move(gameState)); //add this to a vector of valid moves
            }
        }
    }
    return std::move(movesSet); // move the board fields out 

}
/**
 * @brief - A Check if player has won or a draw is found  or if the game is on going 
 * 
 * @return char - return the wining  symbol the draw on or the ongoing symbol 
 */
char BoardFieldGame::isGameState() const
{
    //Check For Row Being Equal
     //drawBoard();
     for (unsigned int row=0; row < this->gridSize; row++)
     {
      unsigned int rowCount = 0;
      for (unsigned int column =0  ; column < gridSize -1 ; column++) {

              if (gameBoard[row][column] ==  gameBoard[row][column+1] && gameBoard[row][column] != BLANK ){
                  ++rowCount;
              }
              else {
                  break;
              }


      }
      if(rowCount == (gridSize -1)){
//          std::cout << "row" << std::endl;
//          std::cout << rowCount << std::endl;
          return gameBoard[row][0];
      }
     }

     // any of the columns is same
     //Check For Row Being Equal
      for (unsigned int column=0; column < this->gridSize; column++)
      {
       unsigned int columnCount = 0;
       for (unsigned int row =0  ; row < gridSize -1 ; row++) {

               if (gameBoard[row][column] ==  gameBoard[row+1][column] && gameBoard[row][column] != BLANK){
                   ++columnCount;
               }
               else {
                   break;
               }


       }
       if(columnCount== (gridSize -1)){
           return gameBoard[0][column];
       }
      }

     // 1st diagonal is same
      unsigned int diagonalCount = 0;

      for (unsigned int index = 0 ; index < gridSize -1 ; index++ ){
          if (gameBoard[index][index]  == gameBoard[index+1][index+1] && gameBoard[index][index] != BLANK){
              ++diagonalCount;
          }
          else {
              break;
          }
      }
      if (diagonalCount == (gridSize - 1) ){
          return  gameBoard[0][0];
      }
     unsigned int antidiagonalCount = 0;
      for (unsigned int index = 0 ; index < gridSize -1 ; index++){
          if (gameBoard[index][gridSize -index -1]  == gameBoard[index+1][gridSize -index -2] && gameBoard[index][gridSize -index -1] != BLANK){
              ++antidiagonalCount;
          }
          else {
              break;
          }
      }
      if (antidiagonalCount  == (gridSize - 1) ){
//          std::cout << antidiagonalCount << std::endl;
          return  gameBoard[0][gridSize -1 ];
      }

     // if we reached here nobody has won yet

     // if any empty box on gameBoard then play on
     for(unsigned int i=0; i< gameBoard.size(); i++)
     {
        for(unsigned int j=0; j< gameBoard.size(); j++){
          //NO ONE HAS WON YET
            if(gameBoard[i][j]==BLANK){
                return ONGOING;
            }
        }
     }


     return DRAW;

}
/**
 * @brief - returns the board utility value
 * 
 * @return int - return an int representing the utility values of this board instance
 */
int BoardFieldGame::getUtilityValue() const
{
    return utilityValue;
}
/**
 * @brief 
 * Sets The Utility Value 
 * @param value - value to set the utility values
 */
void BoardFieldGame::setUtilityValue(int value)
{
    utilityValue = value;
}
/**
 * @brief 
 * Wrapper To get the value in  The Grid At row and column 
 * @param row  - row 
 * @param column - columnn 
 * @return const char& - return const reference to this internel  value at row and column
 */
const char& BoardFieldGame::at(unsigned int &row, unsigned int &column) const
{
    //might throw an exception if index bound  is beyond capicity//
    return gameBoard.at(row).at(column);
}
/**
 * @brief Return The Row Played At 
 * 
 * @return unsigned int 
 */
unsigned int BoardFieldGame::getRow_played() const
{
    return row_played;
}
/**
 * @brief 
 * Return The Row Played At Columnn
 * @return unsigned int 
 */
unsigned int BoardFieldGame::getColumn_played() const
{
    return column_played;
}
/**
 * @brief -Get Depth Of The Current Board
 * 
 * @return unsigned int 
 */
unsigned int BoardFieldGame::getDepth() const
{
    return depth;
}
/**
 * @brief Sets The depth of this baord instance
 * 
 * @param value 
 */

/**
 * @brief BoardFieldGame::setDepth
 * @param value= the depth of the search space max
 */
void BoardFieldGame::setDepth(unsigned int value)
{
    depth = value;
}

void BoardFieldGame::reset()
{
    this->row_played = 0;
    this->column_played= 0;
    //Intialize With All Blanks
    std::vector<std::vector<char> > internalDat(this->gridSize,std::vector<char>(this->gridSize,BLANK));
    //Set Board Game Data Structure
    this->gameBoard = std::move(internalDat);
    this->utilityValue = 0;
    this->depth = 0;//depth always start off as zero as a rule
}

unsigned int BoardFieldGame::getGridSize() const
{
    return gridSize;
}

void BoardFieldGame::setGridSize(unsigned int value)
{
    gridSize = value;
}




