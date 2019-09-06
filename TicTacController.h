#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H
#include <iostream>
#include "AIPlayerTicTacToe.h"
#include <QObject>
#include <thread>

class TicTacController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int  rowCount READ getRows WRITE setRows NOTIFY rowChanged)
    Q_PROPERTY(unsigned int gridCount READ getGridSize WRITE setGridSize NOTIFY gridChanged)
    Q_PROPERTY(char  playerSymbol READ getPlayerSymbol WRITE setPlayerSymbol NOTIFY playerChanged)
    Q_PROPERTY(bool  playLock READ getPlayLock WRITE setPlayLock NOTIFY playLockChanged)

public:
    explicit TicTacController(QObject *parent = nullptr, const unsigned int gridCount = 3);
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
    void  humanPlayerAtHelper(const unsigned int row,const unsigned int column);

signals:
    void gridChanged();
    void playLockChanged();
    void rowChanged();
    void columnChanged();
    void playerChanged();
    void aIplayer(unsigned int row, unsigned int column);
    /**
     * @brief reset-signify the the reset has happened on the controller side
     */
    void resetSignifier();
    void moveProcessed(unsigned int row, unsigned int column);

public slots:
    void humanPlayerAt(const unsigned int row,const unsigned int column);
    void reset();
    void moveReceived(unsigned int row, unsigned int column);
};

#endif // TICTACCONTROLLER_H


