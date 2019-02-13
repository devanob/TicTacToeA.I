#ifndef BOARDFIELDGAME_H
#define BOARDFIELDGAME_H


class BoardFieldGame
{
    public:
        BoardFieldGame();
        //PLays The Player With Symbol playerChacter At row = row+1 and column  column + 1
        bool playAt(unsigned int row, unsigned int  column, char playerCharcter);
        void drawBoard();

    private:
        int utilityValue;
        //The Position The Player Made That Lead To This Positon
        unsigned int row_played;
        unsigned int column_played;


};

#endif // BOARDFIELDGAME_H
