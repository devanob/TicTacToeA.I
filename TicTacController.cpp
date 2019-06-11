#include "TicTacController.h"

TicTacController::TicTacController(QObject *parent, const int row, const int column) : QObject(parent)
{
    this->setRows(row);
    this->setColumns(column);
    this->setPlayerSymbol('O');

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

void TicTacController::humanPlayerAt(const unsigned int row, const unsigned int column)
{
    emit aIplayer(0,0);
}
