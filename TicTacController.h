#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H
#include <iostream>
#include "AIPlayerTicTacToe.h"
#include <QObject>

class TicTacController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int  rowCount READ getRows WRITE setRows NOTIFY rowChanged)
    Q_PROPERTY(unsigned int  columnCount READ getColumns WRITE setColumns NOTIFY columnChanged)
    Q_PROPERTY(char  playerSymbol READ getPlayerSymbol WRITE setPlayerSymbol NOTIFY playerChanged)
    Q_PROPERTY(bool  playLock READ getPlayLock WRITE setPlayLock NOTIFY playLockChanged)
public:
    explicit TicTacController(QObject *parent = nullptr, const int row = 3, const int column =3);
    //Getter Setter Funcitons
    unsigned int getRows() const;
    void setRows(unsigned int value);

    unsigned int getColumns() const;
    void setColumns(unsigned int value);
    //Player Symbol
    char getPlayerSymbol() const;
    void setPlayerSymbol(char value);
    //A.I Symbol
    char getAiSymbol() const;
    void setAiSymbol(char value);
    //
    std::unique_ptr<BoardFieldGame> gameState;
    std::unique_ptr<AIPlayerTicTacToe> aImplement;
    unsigned int getGridSize() const;
    void setGridSize(unsigned int value);

    bool getPlayLock() const;
    void setPlayLock(bool value);

private:
    //Stop A Player From Playing A Second Time Until The Lock Is Released
    bool playLock;
    unsigned int rows;
    unsigned int columns;
    unsigned int gridSize;
    char playerSymbol;
    char aiSymbol;

signals:
    void playLockChanged();
    void rowChanged();
    void columnChanged();
    void playerChanged();
    void aIplayer(unsigned int row, unsigned int column);
    /**
     * @brief reset-signify the the reset has happened on the controller side
     */
    void resetSignifier();

public slots:
    void humanPlayerAt(const unsigned int row,const unsigned int column);
    void reset();
};

#endif // TICTACCONTROLLER_H


