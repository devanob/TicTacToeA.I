#include "TicTacController.h"

TicTacController::TicTacController(QObject *parent, const unsigned int gridCount) : QObject(parent)
{
    this->gridSize = gridCount;
    std::cout << "Constuctor" << gridCount << std::endl;
    this->setPlayerSymbol('X');
    this->setAiSymbol('O');
    this->gameState = std::unique_ptr<BoardFieldGame>(new BoardFieldGame(getGridSize()));
    this->aImplement =
            std::unique_ptr<AIPlayerTicTacToe>(
                new AIPlayerTicTacToe(getAiSymbol(),getPlayerSymbol(),5));
    this->setPlayLock(true);
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
//        std::cout << "setGridSizeL" << std::endl;
//        std::cout << getGridSize() << std::endl;
//        std::cout << gameState.get() << std::endl;
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

void TicTacController::humanPlayerAt(const unsigned int row, const unsigned int column)
{
    try {
        this->setPlayLock(false);
        this->gameState->playAt(row,column,this->getPlayerSymbol());
        if (this->gameState->isGameState() != ONGOING){
            //std::cout << gameState->isGameState() << std::endl;
            std::cout << "NOT ONGNNG" << std::endl;
            return;
        }
        std::thread(&TicTacController::humanPlayerAtHelper,this, row, column).detach();
        //std::cout << "HumanPlayerAt" << std::endl;
    }
    catch(...){

    }

}

void TicTacController::humanPlayerAtHelper(const unsigned int row, const unsigned int column)
{

        //std::cout << "HumanPlayerAtHelper" << std::endl;
        unsigned int rowAI ;
        unsigned int columnAI;
        this->aImplement->playPosition(*gameState,rowAI,columnAI);

        emit moveProcessed(rowAI,columnAI);



}

void TicTacController::reset()
{

    this->gameState->reset();
    this->setPlayLock(true);
    emit resetSignifier();
}

void TicTacController::moveReceived(unsigned int row, unsigned int column)
{
    //std::cout << "moveReceived" << std::endl;
    this->gameState->playAt(row,column,this->getAiSymbol());
    if (this->gameState->isGameState() == ONGOING){
        this->setPlayLock(true);
    }
    emit aIplayer(row,column);
}
