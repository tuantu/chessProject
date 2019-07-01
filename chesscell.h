#ifndef CHESSCELL_H
#define CHESSCELL_H

#include <QList>
#include <QString>
#include <QPoint>

#include "chessconstantdefine.h"

class ChessBoard;

class ChessCell
{
public:
    explicit ChessCell(ChessBoard *board = 0, int position = 0, bool isBlackChess = false);

    virtual ~ChessCell();

    virtual QList<int> getPossibleMoves() const;

    QString getPieceName() const;

    int getCurrentPosition() const;
    void setCurrentPosition(int position);
    bool isBlackChess() const;

    QString getImagePath() const;

    QPoint getCurrentPosInXY() const;
protected:
    QString mPieceName;     // Piece name: king, queen, rook, ...
    int mCurrentPosition;   // Current position of the piece
    bool mIsBlackChess;     // The piece is black or white team

    QString mImagePath;

    ChessBoard *mBoard;
};

#endif // CHESSCELL_H
