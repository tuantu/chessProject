#ifndef CHESSBOARDMODEL_H
#define CHESSBOARDMODEL_H

#include <QAbstractListModel>

#include "chessboard.h"

class ChessBoardModel : public QAbstractListModel
{
    Q_OBJECT
public:
    // Define the role names to be used
    enum RoleNames {
        NameRole = Qt::UserRole,   // King, Queen, ...
        TeamRole,                  // Black or White piece
        ImageRole                  // Image path for showing
    };

    explicit ChessBoardModel(QObject *parent = 0);
    virtual ~ChessBoardModel();

    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void newGame();
    Q_INVOKABLE void clearGame();
    Q_INVOKABLE QString saveGame(QString filepath);
    Q_INVOKABLE QString loadGame(QString filepath);
    Q_INVOKABLE bool isPrevStepAvailable();
    Q_INVOKABLE bool isNextStepAvailable();
    Q_INVOKABLE void prevStep();
    Q_INVOKABLE void nextStep();
    Q_INVOKABLE void move(int sourceIndex, int destIndex);
    Q_INVOKABLE bool checkForPawnPromotion(int index);
    Q_INVOKABLE void replacePawn(int index, QString newRole);
    Q_INVOKABLE bool isGameOver();

protected:
    virtual QHash<int, QByteArray> roleNames() const;

private:
    ChessBoard mChessBoard;
    QHash<int, QByteArray> mRoleNames;
};

#endif // CHESSBOARDMODEL_H
