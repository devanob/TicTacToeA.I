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

bool AIPlayerTicTacToe::playPosition(BoardFieldGame &currentBoard, unsigned int &row, unsigned int &column)
{
    try {

        BoardFieldGame copyGameState = currentBoard;//get a copy of the current board
        auto bestMove = MiniMAxDecision(currentBoard); // calculate the best move
        //set the best moves
        row = bestMove.getRow_played();
        column = bestMove.getColumn_played();

        return true;
    }
    catch(std::exception& expt){
        //We werent able to lay for some reason
        //Debugging Purposes
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
    if (possibleMoves.size() ==0 ){// tried to pay in a draw or already won game
        throw std::runtime_error(std::string("No Mode Moves TO Pay").append(std::string(1,maxPlayer)));
    }
    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();
    BoardFieldGame* bestMove = &(*possibleMoves[0]);
    for (auto & stateNode : possibleMoves){
        stateNode->setUtilityValue(minValue(*stateNode,alpha,beta));
        std::cout << "alpha:" <<alpha<< std::endl;
        std::cout << "beta:" <<beta<< std::endl;
        if (stateNode->getUtilityValue() > alpha){
            alpha = stateNode->getUtilityValue();
            bestMove = &*stateNode;
        }
        }
    //Now Time To Get The biggest values of
//    auto max = std::max_element(possibleMoves.begin(),  possibleMoves.end(),
//                                 []( const std::unique_ptr<BoardFieldGame> &left, const std::unique_ptr<BoardFieldGame> &right )
//                                 {
//                                     return left->getUtilityValue() < right->getUtilityValue();
//                                 });
    return std::move(*bestMove);//return the best move theorically

}
/**
 * @brief - Given A Board Evaluates The Current Board Game Using An Custom Evaluation Function 
 * 
 * @param currentBoard - referece to a current board instance
 * @return int return a evaluation value between -int max to + int max 
 * where -INF = MIN WIN +INF = MAX WIN AND Any Finite Number Is Eval Score
 */
int AIPlayerTicTacToe::evalutaionFunciton(const BoardFieldGame &currentBoard, char player)
{
    if (currentBoard.isGameState() == maxPlayer){ // if you have won =INF
//        currentBoard.drawBoard();
        return std::numeric_limits<int>::max(); //force win

    }
    else if (currentBoard.isGameState() == minOpponet){ // if your opponet has won =INF
        return std::numeric_limits<int>::min(); //force loss or you
    }
    else if (currentBoard.isGameState() == DRAW){ // if draw
        return 0;
    }
    else {//game is still on going
        if (player == maxPlayer)
            return heuristic(currentBoard, maxPlayer);
        else{
            return -heuristic(currentBoard,minOpponet);
        }
    }
}
/**
 * @brief 
 * Return a eval score from the perspective of  max player 
 * @param childBoard -  a current intance of a board
 * @return int - return the evaluation score
 */
int AIPlayerTicTacToe::maxValue(BoardFieldGame &childBoard,int alpha, int beta)
{
    if (terminalStateOrDepthBound(childBoard)){


        return evalutaionFunciton(childBoard, maxPlayer);
    }
    int nodeValue = std::numeric_limits<int>::min(); // set to -inf or min(int)
    //std::cout << nodeValue;
    auto possibleMoves = std::move(childBoard.generateStates(maxPlayer));//generate state in which you are next player
    for (auto & stateNode : possibleMoves){
        nodeValue = std::max(nodeValue, minValue(*stateNode,alpha,beta));
        if (nodeValue >= beta){

            return nodeValue;
        }
        alpha = std::max(alpha,nodeValue);

    }
    return nodeValue;

}

/**
 * @brief 
 * Return a eval score from the perspective of min player 
 * @param childBoard -  a current intance of a board
 * @return int - return the evaluation score
 */
int AIPlayerTicTacToe::minValue(BoardFieldGame &childBoard, int alpha, int beta)
{
    if (terminalStateOrDepthBound(childBoard)){ // check if player  game has ended due to a player win or depth bound 
        return evalutaionFunciton(childBoard,minOpponet);
    }
    int nodeValue = std::numeric_limits<int>::max(); // set to -inf or min(int)

    auto possibleMoves = std::move(childBoard.generateStates(minOpponet));//generate state in which you are next player
    for (auto & stateNode : possibleMoves){
        nodeValue = std::min(nodeValue, maxValue(*stateNode,alpha,beta));

        if (nodeValue <= alpha){
              return nodeValue;
        }
        beta = std::min(beta,nodeValue);

    }
    return nodeValue;
}
/**
 * @brief 
 * Check if a ending state has been reach either through a win, draw , loss or depth bound 
 * @param childBoard - instance of a board
 * @return true - game as ended 
 * @return false - game is ongoing
 */
bool AIPlayerTicTacToe::terminalStateOrDepthBound(BoardFieldGame &childBoard)
{
    auto WinLossState = childBoard.isGameState();
    if (WinLossState== maxPlayer || WinLossState == minOpponet || WinLossState == DRAW){

        //childBoard.drawBoard();
        return true; // game has ended with a win for someone or a draw
    }
    else if (childBoard.getDepth() >= maxdepth){
        //std::cout << childBoard.getDepth();
        return true; // we have reach our max dept
    }
    else {

        return false; // game is still ongoing
    }
}
/**
 * @brief 
 * An Evaluation heuristic that conciders possible winning moves as a score
 * @param gameBoard - instance of a board game 
 * @param player  - the player to calculate the hueristic for 
 * @return int - evaluation score 
 */
int AIPlayerTicTacToe::heuristic(const BoardFieldGame &gameBoard, char &player)
{
    //check everything return the count
    auto countRoW=  checkRow(gameBoard,player) ;
    auto countcolumn =checkColumns(gameBoard,player) ;
    auto countDiag =checkDiagonal(gameBoard, player);
    auto countAnti =checkAntiDiagonal(gameBoard,player);

    return countRoW + countcolumn + countDiag + countAnti;
}
/**
 * @brief 
 * Check Winning Moves Across The Row For The currentplayer
 * @param gameBoard - instance of a board game
 * @param player - player symbol 
 * @return int - evalutation score 
 */
int AIPlayerTicTacToe::checkRow(const BoardFieldGame &gameBoard, char &player)
{
    int countWinningSpot = 0;
    char FirstInstance = BLANK;
    int numTypeLine= 0;
    //chech each row for winning spots
    for (unsigned int row = 0 ; row < gameBoard.getGridSize(); row++){//Row
        for (unsigned int column = 0 ; column < gameBoard.getGridSize(); column++){
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
/**
 * @brief 
 * Check Winning Moves Across The  columns  For The currentplayer
 * @param gameBoard - instance of a board game
 * @param player - player symbol 
 * @return int - evalutation score 
 */
int AIPlayerTicTacToe::checkColumns(const BoardFieldGame &gameBoard, char &player)
{
    char FirstInstance = BLANK;
    int numTypeLine= 0;
    int countWinningSpot = 0;
    //check column for win
    for (unsigned int column = 0 ; column < gameBoard.getGridSize(); column++){//Row
        for (unsigned int row = 0 ; row< gameBoard.getGridSize(); row++){
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
/**
 * @brief 
 * Check Winning Moves Across The  diagonals  For The currentplayer
 * @param gameBoard - instance of a board game
 * @param player - player symbol 
 * @return int - evalutation score 
 */
int AIPlayerTicTacToe::checkDiagonal(const BoardFieldGame &gameBoard, char &player)
{
    //Time To Check diagnonals
    char FirstInstance = BLANK;
    int numTypeLine= 0;
    int countWinningSpot = 0;
    for (unsigned int item = 0 ; item < gameBoard.getGridSize(); item++){//Row

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

/**
 * @brief 
 * Check Winning Moves Across The  anti-diagonals  For The currentplayer
 * @param gameBoard - instance of a board game
 * @param player - player symbol 
 * @return int - evalutation score 
 */
int AIPlayerTicTacToe::checkAntiDiagonal(const BoardFieldGame &gameBoard, char &player)
{
    //Time To Check AntiDiagonal
    int FirstInstance = BLANK;
    int numTypeLine= 0;
    int countWinningSpot = 0;
    for (unsigned int row = 0 ; row < gameBoard.getGridSize() && numTypeLine < 2;  row++){
        for(unsigned int column = 0 ; column < gameBoard.getGridSize();  column++){
            if ((row + column) == (gameBoard.getGridSize() - 1) ){ //check anti diagonal
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
