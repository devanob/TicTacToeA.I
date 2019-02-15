TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    BoardFieldGameState.cpp \
    AIPlayerTicTacToe.cpp

HEADERS += \
    BoardFieldGameState.h \
    AIPlayerTicTacToe.h
