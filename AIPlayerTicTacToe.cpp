#include "AIPlayerTicTacToe.h"


AIPlayerTicTacToe::AIPlayerTicTacToe(const char &playeSymbol, const char &opponetSymbol, const unsigned int &maxDept)
{
    this->maxPlayer = playeSymbol;
    this->minOpponet = opponetSymbol;
    this->maxdepth = maxDept;
}

bool AIPlayerTicTacToe::play(BoardFieldGame &currentBoard)
{
    try {

    BoardFieldGame copyGameState = currentBoard;//get a copy of the current board
    auto bestMove = MiniMAxDecision(currentBoard); // calculate the best move
    currentBoard.playAt(bestMove.getRow_played(),bestMove.getColumn_played(),maxPlayer);//play at our best spot
    }
    catch(std::exception& expt){
        //We werent able to lay for some reason
        std::cout << expt.what();
        return false;
    }

}

char AIPlayerTicTacToe::getMaxPlayer() const
{
    return maxPlayer;
}

void AIPlayerTicTacToe::setMaxPlayer(char value)
{
    maxPlayer = value;
}

BoardFieldGame AIPlayerTicTacToe::MiniMAxDecision(const BoardFieldGame &currentBoard)
{
    auto possibleMoves = currentBoard.generateStates(maxPlayer);//generate state in which you are next player
    if (possibleMoves.size()){// tried to pay in a draw or already won game
        std::runtime_error(std::string("No Mode Moves TO Pay").append(std::string(1,maxPlayer)));
    }
    for (auto & stateNode : possibleMoves){
        stateNode->setUtilityValue(minValue(*stateNode));
    }
    //Now Time To Get The biggest values of
    auto max = std::max_element(possibleMoves.begin(),  possibleMoves.end(),
                                 []( const std::unique_ptr<BoardFieldGame> &left, const std::unique_ptr<BoardFieldGame> &right )
                                 {
                                     return left->getUtilityValue() < right->getUtilityValue();
                                 } );
    return std::move(*(*max));//return the best move theorically

}

int AIPlayerTicTacToe::evalutaionFunciton(const BoardFieldGame &currentBoard)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-10, 10);
    return distr(eng);
}

int AIPlayerTicTacToe::maxValue(BoardFieldGame &childBoard)
{
    if (terminalStateOrDepthBound(childBoard)){
        return evalutaionFunciton(childBoard);
    }
    int nodeValue = std::numeric_limits<int>::min(); // set to -inf or min(int)
    auto possibleMoves = std::move(childBoard.generateStates(minOpponet));//generate state in which you are next player
    for (auto & stateNode : possibleMoves){
        nodeValue = std::max(nodeValue, minValue(*stateNode));
    }
    return nodeValue;
}

int AIPlayerTicTacToe::minValue(BoardFieldGame &childBoard)
{
    if (terminalStateOrDepthBound(childBoard)){
        return evalutaionFunciton(childBoard);
    }
    int nodeValue = std::numeric_limits<int>::max(); // set to -inf or min(int)
    auto possibleMoves = std::move(childBoard.generateStates(maxPlayer));//generate state in which you are next player
    for (auto & stateNode : possibleMoves){
        nodeValue = std::min(nodeValue, minValue(*stateNode));
    }
    return nodeValue;
}

bool AIPlayerTicTacToe::terminalStateOrDepthBound(BoardFieldGame &childBoard)
{
    auto WinLossState = childBoard.isGameState();
    if (WinLossState== maxPlayer || WinLossState == minOpponet || WinLossState == DRAW){
        //childBoard.drawBoard();
        return true; // game has ended with a win for someone or a draw
    }
    else if (childBoard.getDepth() == maxdepth){
        return true; // we have reach our max dept
    }
    else {

        return false; // game is still ongoing
    }
}
