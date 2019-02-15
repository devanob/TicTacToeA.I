#ifndef AIPLAYERTICTACTOE_H
#define AIPLAYERTICTACTOE_H
#include "BoardFieldGameState.h"
#include <random>

class AIPlayerTicTacToe
{
    public:
        AIPlayerTicTacToe(const char& playeSymbol, const char& opponetSymbol, const unsigned int &maxDept);
        //specifiy where this plays return as a row , colum in the Board, given a copy of the board
        bool play(BoardFieldGame &currentBoard);
        char getMaxPlayer() const;
        void setMaxPlayer(char value);

private:
        char maxPlayer; // the charcter of this player
        char minOpponet; // the character of your opponet
        unsigned int maxdepth; // depth of the search space before temrinal
        BoardFieldGame MiniMAxDecision (const  BoardFieldGame& currentBoard);
        //Evaluation Function State
        int evalutaionFunciton(const  BoardFieldGame& currentBoard);
        //max function
        int maxValue(BoardFieldGame& childBoard);
        //min function
        int minValue(BoardFieldGame& childBoard);
        //min funciton
        bool terminalStateOrDepthBound(BoardFieldGame& childBoard);
        //Here Tempoaray For Testing  // seed the generator
        //Testing Purposes



};

#endif // AIPLAYERTICTACTOE_H
