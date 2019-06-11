#ifndef TICTACCONTROLLER_H
#define TICTACCONTROLLER_H
#include <iostream>

#include <QObject>

class TicTacController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int  rowCount READ getRows WRITE setRows NOTIFY rowChanged)
    Q_PROPERTY(unsigned int  columnCount READ getColumns WRITE setColumns NOTIFY columnChanged)
    Q_PROPERTY(char  playerSymbol READ getPlayerSymbol WRITE setPlayerSymbol NOTIFY playerChanged)
public:
    explicit TicTacController(QObject *parent = nullptr, const int row = 3, const int column =3);
    //Getter Setter Funcitons
    unsigned int getRows() const;
    void setRows(unsigned int value);

    unsigned int getColumns() const;
    void setColumns(unsigned int value);

    char getPlayerSymbol() const;
    void setPlayerSymbol(char value);

private:
    unsigned int rows;
    unsigned int columns;
    char playerSymbol;
    char aiSymbol;

signals:
    void rowChanged();
    void columnChanged();
    void playerChanged();
    void aIplayer(unsigned int row, unsigned int column);
public slots:
    void humanPlayerAt(const unsigned int row,const unsigned int column);
};

#endif // TICTACCONTROLLER_H


