#include "AIPlayerTicTacToe.h"

/**
 * @brief Construct a new AIPlayerTicTacToe::AIPlayerTicTacToe object
 * 
 * @param playeSymbol - the char symbol of the current player 
 * @param opponetSymbol -the char symbol of the  opposing player
 * @param maxDept - the maximuim depth search of the user (search space)
 */
AIPlayerTicTacToe::AIPlayerTicTacToe(const char &playeSymbol, const char &opponetSymbol, const unsigned int &maxDept)
{
    this->maxPlayer = playeSymbol;
    this->minOpponet = opponetSymbol;
    this->maxdepth = maxDept;
}
/**
 * @brief - pass a reference to the current board then the current player makes a move on that board 
 * 
 * @param currentBoard - reference to the a board
 * @return bool if playing was succesful return true or false if an error occured like memory allocation issues
 * @return false 
 */
bool AIPlayerTicTacToe::play(BoardFieldGame &currentBoard)
{
    try {

    BoardFieldGame copyGameState = currentBoard;//get a copy of the current board
    auto bestMove = MiniMAxDecision(currentBoard); // calculate the best move
    currentBoard.playAt(bestMove.getRow_played(),bestMove.getColumn_played(),maxPlayer);//play at our best spot
    return true;
    }
    catch(std::exception& expt){
        //We werent able to lay for some reason
        std::cout << expt.what();
        return false;
    }

}
/**
 * @brief - return the char symbol of the max player 
 * 
 * @return char 
 */
char AIPlayerTicTacToe::getMaxPlayer() const
{
    return maxPlayer;
}
/**
 * @brief - set the value of the max player
 * 
 * @param value - the char symbol for the max player
 */
void AIPlayerTicTacToe::setMaxPlayer(char value)
{
    maxPlayer = value;
}
/**
 * @brief -Passed In A copy of the current board using the MinMax Algo With Dept Bound To Find The Best Move
 * 
 * @param currentBoard - playing board
 * @return BoardFieldGame return a board with the best move
 */
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
/**
 * @brief - Given A Board Evaluates The Current Board Game Using An Custom Evaluation Function 
 * 
 * @param currentBoard - referece to a current board instance
 * @return int return a evaluation value between -int max to + int max 
 * where -INF = MIN WIN +INF = MAX WIN AND Any Finite Number Is Eval Score
 */
int AIPlayerTicTacToe::evalutaionFunciton(const BoardFieldGame &currentBoard)
{
    if (currentBoard.isGameState() == maxPlayer){ // if you have won =INF
        return std::numeric_limits<int>::max(); //force win
    }
    else if (currentBoard.isGameState() == minOpponet){ // if your opponet has won =INF
        return  std::numeric_limits<int>::min(); //force loss or you
    }
    else if (currentBoard.isGameState() == DRAW){ // if draw
        return 0;
    }
    else {//game is still on going
        return heuristic(currentBoard, maxPlayer) -  heuristic(currentBoard, minOpponet);
    }
}
/**
 * @brief 
 * 
 * @param childBoard 
 * @return int 
 */
int AIPlayerTicTacToe::maxValue(BoardFieldGame &childBoard)
{
    if (terminalStateOrDepthBound(childBoard)){
        return evalutaionFunciton(childBoard);
    }
    int nodeValue = std::numeric_limits<int>::min(); // set to -inf or min(int)
    //std::cout << nodeValue;
    auto possibleMoves = std::move(childBoard.generateStates(maxPlayer));//generate state in which you are next player
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

    auto possibleMoves = std::move(childBoard.generateStates(minOpponet));//generate state in which you are next player
    for (auto & stateNode : possibleMoves){
        nodeValue = std::min(nodeValue, maxValue(*stateNode));
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
        //std::cout << childBoard.getDepth();
        return true; // we have reach our max dept
    }
    else {

        return false; // game is still ongoing
    }
}

int AIPlayerTicTacToe::heuristic(const BoardFieldGame &gameBoard, char &player)
{
    //check everything return the count
    return checkRow(gameBoard,player) + checkColumns(gameBoard,player) +
            + checkDiagnonal(gameBoard, player) + checkAntiDiagonal(gameBoard,player);
}
//check rows
int AIPlayerTicTacToe::checkRow(const BoardFieldGame &gameBoard, char &player)
{
    int countWinningSpot = 0;
    char FirstInstance = BLANK;
    int numTypeLine= 0;
    //chech each row for winning spots
    for (unsigned int row = 0 ; row < GRIDSIZE; row++){//Row
        for (unsigned int column = 0 ; column < GRIDSIZE; column++){
            if (gameBoard.at(row,column) != BLANK){//BLANK CHECK
                if (numTypeLine == 0 ){ //CHECK NO TYPE DETECTED
                    numTypeLine++;
                    FirstInstance = gameBoard.at(row,column);
                }//END CHECK NO TYPE DETECTED
                else if (gameBoard.at(row,column)!= FirstInstance){ //two different types same row// cant win here
                    numTypeLine++;
                    break;
                } // END two different types same row// cant win here
                //else we got the same type that we found before
            }//END //BLANK CHECK
        }
        if (numTypeLine < 2 && (FirstInstance== player || FirstInstance == BLANK) ){
            countWinningSpot++;
        }
        FirstInstance = BLANK;
        numTypeLine= 0;

    }// END ROW
    return countWinningSpot;
}
//check  colums
int AIPlayerTicTacToe::checkColumns(const BoardFieldGame &gameBoard, char &player)
{
    char FirstInstance = BLANK;
    int numTypeLine= 0;
    int countWinningSpot = 0;
    //check column for win
    for (unsigned int column = 0 ; column < GRIDSIZE; column++){//Row
        for (unsigned int row = 0 ; row< GRIDSIZE; row++){
            if (gameBoard.at(row,column) != BLANK){//BLANK CHECK
                if (numTypeLine == 0 ){ //CHECK NO TYPE DETECTED
                    numTypeLine++;
                    FirstInstance = gameBoard.at(row,column);
                }//END CHECK NO TYPE DETECTED
                else if (gameBoard.at(row,column)!= FirstInstance){ //two different types same column// cant win here
                    numTypeLine++;
                    break;
                } // END two different types same colomn// cant win here
                //else we got the same type that we found before
            }//END //BLANK CHECK
        }
        if (numTypeLine < 2 && (FirstInstance== player || FirstInstance == BLANK) ){
            countWinningSpot++;
        }
        FirstInstance = BLANK;
        numTypeLine= 0;

    }// END Colum Check
    return countWinningSpot;

}

int AIPlayerTicTacToe::checkDiagnonal(const BoardFieldGame &gameBoard, char &player)
{
    //Time To Check diagnonals
    char FirstInstance = BLANK;
    int numTypeLine= 0;
    int countWinningSpot = 0;
    for (unsigned int item = 0 ; item < GRIDSIZE; item++){//Row

        if (gameBoard.at(item,item) != BLANK){//BLANK CHECK
                       if (numTypeLine == 0 ){ //CHECK NO TYPE DETECTED
                           numTypeLine++;
                           FirstInstance = gameBoard.at(item,item);
                       }//END CHECK NO TYPE DETECTED
                       else if (gameBoard.at(item,item)!= FirstInstance){ //two different types same column// cant win here
                           numTypeLine++;
                           break;
                       } // END two different types same colomn// cant win here
                       //else we got the same type that we found before
                   }//END //BLANK CHECK
    }//End
    if (numTypeLine < 2 && (FirstInstance== player || FirstInstance == BLANK) ){
        countWinningSpot++;
    }
    return  countWinningSpot;
}

int AIPlayerTicTacToe::checkAntiDiagonal(const BoardFieldGame &gameBoard, char &player)
{
    //Time To Check AntiDiagonal
    int FirstInstance = BLANK;
    int numTypeLine= 0;
    int countWinningSpot = 0;
    for (unsigned int row = 0 ; row < GRIDSIZE && numTypeLine < 2;  row++){
        for(unsigned int column = 0 ; column < GRIDSIZE;  column++){
            if ((row + column) == (GRIDSIZE - 1) ){ //check anti diagonal
                if (gameBoard.at(row,column) != BLANK){//BLANK CHECK
                               if (numTypeLine == 0 ){ //CHECK NO TYPE DETECTED
                                   numTypeLine++;
                                   FirstInstance = gameBoard.at(row,column);
                               }//END CHECK NO TYPE DETECTED
                               else if (gameBoard.at(row,column)!= FirstInstance){ //two different types same column// cant win here
                                   numTypeLine++;
                                   break;
                               } // END two different types same colomn// cant win here
                               //else we got the same type that we found before
                           }//END //BLANK CHE
            }// End is antidiagonal
        }
    }
    if (numTypeLine < 2 && (FirstInstance== player || FirstInstance == BLANK) ){
        countWinningSpot++;
    }
    return countWinningSpot;
}
