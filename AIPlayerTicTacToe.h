#ifndef AIPLAYERTICTACTOE_H
#define AIPLAYERTICTACTOE_H
#include "BoardFieldGameState.h"
#include <random>
std::random_device rd; // obtain a random number from hardware
std::mt19937 eng(rd()); // seed the generator
std::uniform_int_distribution<> distr(-10, 10);
class AIPlayerTicTacToe
{
    public:
        AIPlayerTicTacToe(const char& playeSymbol, const char& opponetSymbol, const unsigned int &maxDept);
        //specifiy where this plays return as a row , colum in the Board, given a copy of the board
        bool play(const BoardFieldGame& currentBoard, unsigned int &row, unsigned int &column);
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



};

#endif // AIPLAYERTICTACTOE_H
