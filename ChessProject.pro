TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    chessboardmodel.cpp \
    chesscell.cpp \
    kingcell.cpp \
    chessboard.cpp \
    queencell.cpp \
    rookcell.cpp \
    knightcell.cpp \
    bishopcell.cpp \
    pawncell.cpp \
    chesscellfactory.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    images/Chess_Board.png \
    ChessCellElement.ui.qml \
    PromotionDialog.ui.qml

HEADERS += \
    chessboardmodel.h \
    chesscell.h \
    kingcell.h \
    chessboard.h \
    chessconstantdefine.h \
    queencell.h \
    rookcell.h \
    knightcell.h \
    bishopcell.h \
    pawncell.h \
    chesscellfactory.h
