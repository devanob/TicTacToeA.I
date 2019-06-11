#include <iostream>
#include "BoardFieldGameState.h"
#include "AIPlayerTicTacToe.h"
using namespace std;

void match(int matchCount, bool printStages){
    //Our Current Board
    BoardFieldGame board;
     std::cout << std::endl<<"-------------------------";
    std::cout << "MATCH:" << matchCount << std::endl;
    std::cout<< "X vs O" << std::endl;
    //PLayers
    int playerOneID = 0;
    AIPlayerTicTacToe PlayerOne('X','O',3);
    //
    int playerTwoID = 1;
    AIPlayerTicTacToe PlayerTwo('O','X',5);
    //
    int playerTurn = playerOneID;
    AIPlayerTicTacToe*  playersPtr[2];
    //
    playersPtr[0] = &PlayerOne;
    playersPtr[1] = &PlayerTwo;

    char playerWonOrDraw = board.isGameState();

    while(playerWonOrDraw == ONGOING){
        playersPtr[playerTurn]->play(board);
        if (printStages == true){
            board.drawBoard();
        }
        playerTurn = (playerOneID +playerTwoID) - playerTurn;
        playerWonOrDraw = board.isGameState();
    }
    std::cout << "Final Results" << std::endl;
    board.drawBoard();
    if (playerWonOrDraw != DRAW){
        std::cout << "Player " << playerWonOrDraw << " Has Won" << std::endl;
    }
    else {
        std::cout << "Match Ended In A Draw" << std::endl;
    }
    std::cout << "-------------------------";


}

int main1()
{
    match(2,true);
    //To be Continued


}
