#ifndef AIPLAYERTICTACTOE_H
#define AIPLAYERTICTACTOE_H
#include "BoardFieldGameState.h"
#include <random>
/**
 * @brief This Is A.I Implementation Using Mini-Max And Depth Bound
 * 
 */
class AIPlayerTicTacToe
{
    public:
        AIPlayerTicTacToe(const char& playeSymbol, const char& opponetSymbol, const unsigned int &maxDept);
        //specifiy where this plays return as a row , colum in the Board, given a copy of the board
        bool play(BoardFieldGame &currentBoard);
        bool playPosition(BoardFieldGame &currentBoard, unsigned int & row, unsigned int & column);
        char getMaxPlayer() const;
        void setMaxPlayer(char value);


    private:
        //he
        char maxPlayer; // the charcter of this player
        char minOpponet; // the character of your opponet
        unsigned int maxdepth; // depth of the search space before temrinal
        BoardFieldGame MiniMAxDecision (const  BoardFieldGame& currentBoard);
        //Evaluation Function State
        int evalutaionFunciton(const  BoardFieldGame& currentBoard, char player);
        //max function
        int maxValue(BoardFieldGame& childBoard, int alpha, int beta);
        //min function
        int minValue(BoardFieldGame& childBoard, int alpha, int beta);
        //min funciton
        bool terminalStateOrDepthBound(BoardFieldGame& childBoard);
        //Here Tempoaray For Testing  // seed the generator
        //Evaluation Function Helpers
        //Huerstic Function
        int heuristic(const BoardFieldGame &gameBoard, char & player);
        //Checking For Various Possible Wins Acros Different Conditions
        int checkRow(const BoardFieldGame& gameBoard, char & player);
        int checkColumns(const BoardFieldGame& gameBoard, char & player);
        int checkDiagonal(const BoardFieldGame& gameBoard, char & player);
        int checkAntiDiagonal(const BoardFieldGame& gameBoard, char & player);
};

#endif // AIPLAYERTICTACTOE_H
