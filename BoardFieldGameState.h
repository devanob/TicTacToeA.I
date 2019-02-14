#ifndef BOARDFIELDGAME_H
#define BOARDFIELDGAME_H
#include <memory>
#include <vector>
class BoardFieldGame
{
    public:
        BoardFieldGame();
        //Begin-playAt --> plays at The Player With Symbol playerChacter At row = row+1 and column  column + 1
        bool playAt(unsigned int row, unsigned int  column, char playerCharcter);
        //End
        //Begin - drawBoard --> draws the current playing board
        void drawBoard();
         //End 
         //Generate New States Based On Current State 
        //throw an error if the state is a terminal state
         std::vector<std::unique_ptr<BoardFieldGame>> generateStates();
        //End
        
        //Set Utiltity For Node and Get Utility
         int getUtilityValue() const;
         void setUtilityValue(int value);

private:
         int utilityValue;
         // Begin -The Position The Player Made That Lead To This Positon
        unsigned int row_played;
        unsigned int column_played;
        //End 
        
        


};

#endif // BOARDFIELDGAME_H
