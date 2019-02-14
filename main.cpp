#include <iostream>
#include "BoardFieldGameState.h"
using namespace std;

int main()
{
    BoardFieldGame board;
    board.playAt(0,0, 'X');
    board.playAt(0,1, 'X');
    board.playAt(1,1, 'X');
    board.playAt(0,2,'O');
    board.playAt(2,2, 'X');



}
