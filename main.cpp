#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <TicTacController.h>
#include <QQmlContext>
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //Register Controller As Type
    qmlRegisterType<TicTacController>("CM", 1 , 0 , "TicTacController");
    TicTacController masterController;
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
