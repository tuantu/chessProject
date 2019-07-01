#include <iostream>
#include "chessboardmodel.h"

ChessBoardModel::ChessBoardModel(QObject *parent)
    :QAbstractListModel(parent)
{
    // Set names to the role name hash container (QHash<int, QByteArray>)
    mRoleNames[NameRole] = MODEL_ROLE_NAME;
    mRoleNames[TeamRole] = MODEL_ROLE_TEAM;
    mRoleNames[ImageRole] = MODEL_ROLE_IMAGE;
}

ChessBoardModel::~ChessBoardModel()
{

}

int ChessBoardModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return NUM_OF_CHESS_CELLS;
}

QVariant ChessBoardModel::data(const QModelIndex & index, int role) const
{
    // the index returns the requested row and column information.
    // we ignore the column and only use the row information
    int row = index.row();

    // boundary check for the row
    if(row < 0 || row >= rowCount()) {
        return QVariant();
    }

    std::cout << "\nROW: " << row << ", Role: " << role;
    switch(role) {
    case NameRole:
        return mChessBoard.getChessCellAt(row)->getPieceName();
    case TeamRole:
        if (mChessBoard.getChessCellAt(row)->isBlackChess()) {
            return MODEL_TEAM_BLACK_COLOR;
        } else {
            return MODEL_TEAM_WHITE_COLOR;
        }
    case ImageRole:
        return mChessBoard.getChessCellAt(row)->getImagePath();
    }

    // The view asked for other data, just return an empty QVariant
    return QVariant();
}

void ChessBoardModel::newGame()
{
    emit beginResetModel();
    mChessBoard.initNewGame();
    emit endResetModel();
}

void ChessBoardModel::clearGame()
{
    emit beginResetModel();
    mChessBoard.clearGame();
    emit endResetModel();
}

QString ChessBoardModel::saveGame(QString filepath)
{
    return mChessBoard.saveGame(filepath);
}

QString ChessBoardModel::loadGame(QString filepath)
{
    emit beginResetModel();
    QString result = mChessBoard.loadGame(filepath);
    emit endResetModel();

    return result;
}

bool ChessBoardModel::isPrevStepAvailable()
{
    return mChessBoard.isPrevStepAvailable();
}

bool ChessBoardModel::isNextStepAvailable()
{
    return mChessBoard.isNextStepAvailable();
}

void ChessBoardModel::prevStep()
{
    emit beginResetModel();
    mChessBoard.prevStep();
    emit endResetModel();
}

void ChessBoardModel::nextStep()
{
    emit beginResetModel();
    mChessBoard.nextStep();
    emit endResetModel();
}

void ChessBoardModel::move(int sourceIndex, int destIndex)
{
    emit beginResetModel();
    mChessBoard.move(sourceIndex, destIndex);
    emit endResetModel();
}

bool ChessBoardModel::checkForPawnPromotion(int index)
{
    return mChessBoard.checkForPawnPromotion(index);
}

void ChessBoardModel::replacePawn(int index, QString newRole)
{
    emit beginResetModel();
    mChessBoard.replacePawn(index, newRole);
    emit endResetModel();
}

bool ChessBoardModel::isGameOver()
{
    return mChessBoard.isGameOver();
}

QHash<int, QByteArray> ChessBoardModel::roleNames() const
{
    return mRoleNames;
}
