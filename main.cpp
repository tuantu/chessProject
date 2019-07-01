#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtGui>
#include <QtQml>

#include "chessboardmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // register the type DataEntryModel
    // under the url "org.example" in version 1.0
    // under the name "DataEntryModel"
    qmlRegisterType<ChessBoardModel>("org.example", 1, 0, "ChessBoardModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
