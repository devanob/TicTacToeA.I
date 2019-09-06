#include "TicTacController.h"
/**
 * @brief TicTacController::TicTacController- Contructor
 * @param parent - QParent ptr - reponsible  for delete and mananging children instances
 * @param gridCount - the starting grid count
 */
TicTacController::TicTacController(QObject *parent, const unsigned int gridCount) : QObject(parent)
{
    this->gridSize = gridCount;
    this->setPlayerSymbol('X'); //sets the current player symbol X to be customized later
    this->setAiSymbol('O'); //sets the current player symbol to O to be customized later
    //generate a new a.i and board instance manages memory through smart pointers
    this->gameState = std::unique_ptr<BoardFieldGame>(new BoardFieldGame(getGridSize()));
    this->aImplement =
            std::unique_ptr<AIPlayerTicTacToe>(
                new AIPlayerTicTacToe(getAiSymbol(),getPlayerSymbol(),5));
    this->setPlayLock(true);
    //makes symbol connection for moves processed (ieA.I) to the controller receiving the move
    connect(this,&TicTacController::moveProcessed, this,& TicTacController::moveReceived);

}

unsigned int TicTacController::getRows() const
{
    return rows;
}

void TicTacController::setRows(unsigned int value)
{
    if (value != this->rows){
        rows = value;
        emit rowChanged();
    }
}

unsigned int TicTacController::getColumns() const
{
return columns;
}

void TicTacController::setColumns(unsigned int value)
{
    if (value != this->columns){
        columns = value;
        emit columnChanged();
    }

}

char TicTacController::getPlayerSymbol() const
{
    return playerSymbol;
}

void TicTacController::setPlayerSymbol(char value)
{
    playerSymbol = value;
}

char TicTacController::getAiSymbol() const
{
    return aiSymbol;
}

void TicTacController::setAiSymbol(char value)
{
    aiSymbol = value;
}

unsigned int TicTacController::getGridSize() const
{
    return gridSize;
}

void TicTacController::setGridSize(unsigned int value)
{
    if (value != this->gridSize){
        gridSize = value;
        this->gameState->setGridSize(getGridSize());
        reset();
        emit gridChanged();
    }
}

bool TicTacController::getPlayLock() const
{
    return playLock;
}

void TicTacController::setPlayLock(bool value)
{
    playLock = value;
    emit  playLockChanged();
}

/**

//reives a signal as the user playing
*/
void TicTacController::humanPlayerAt(const unsigned int row, const unsigned int column)
{
    try {
//        sets the player lock to false so the current human player cannot play on board until the a.i has produced a move
        this->setPlayLock(false);
        this->gameState->playAt(row,column,this->getPlayerSymbol());
        //check if the game is on goiing
        if (this->gameState->isGameState() != ONGOING){
            return;
        }
        //launches and detaches a seperate thread for a.i processing
        std::thread(&TicTacController::humanPlayerAtHelper,this, row, column).detach();
    }
    catch(...){

    }

}

/**
//signal to relay that the player is done procesing the current move board
*/
void TicTacController::humanPlayerAtHelper(const unsigned int row, const unsigned int column)
{

        unsigned int rowAI ;
        unsigned int columnAI;
        this->aImplement->playPosition(*gameState,rowAI,columnAI);
        //emits a threads safe signl from the a.i to the board
        emit moveProcessed(rowAI,columnAI);



}
/**
 * @brief TicTacController::reset - reset the current internal board game instance-fresh new game
 */
void TicTacController::reset()
{

    this->gameState->reset();
    this->setPlayLock(true);
    emit resetSignifier();
}
/**
 * @brief TicTacController::moveReceived - recived a move from the front end to the controller ie Human made a move
 * @param row
 * @param column
 */
void TicTacController::moveReceived(unsigned int row, unsigned int column)
{
    //std::cout << "moveReceived" << std::endl;
    this->gameState->playAt(row,column,this->getAiSymbol());
    if (this->gameState->isGameState() == ONGOING){
        this->setPlayLock(true);
    }
    emit aIplayer(row,column);
}
