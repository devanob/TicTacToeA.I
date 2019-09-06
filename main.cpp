#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <TicTacController.h>
#include <QQmlContext>
#include "AIPlayerTicTacToe.h"
#include <memory>
//Test
void match(int matchCount, bool printStages){
    //Our Current Board
    BoardFieldGame board(3);
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
//Test
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //Register Controller As Type
    qmlRegisterType<TicTacController>("CM", 1 , 0 , "TicTacController");
    TicTacController masterController(nullptr,3);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("TicTacToaController", &masterController);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //Set Up Signal And Slot

    return app.exec();
}
