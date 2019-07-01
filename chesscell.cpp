#include "chesscell.h"

ChessCell::ChessCell(ChessBoard *board, int position, bool isBlackChess)
{
    mPieceName = "";
    mCurrentPosition = position;
    mBoard = board;
    mIsBlackChess = isBlackChess;
    mImagePath = "";
}

ChessCell::~ChessCell()
{

}

QString ChessCell::getPieceName() const
{
    return mPieceName;
}

QList<int> ChessCell::getPossibleMoves() const
{
    QList<int> emptyList;
    return emptyList;
}

int ChessCell::getCurrentPosition() const
{
    return mCurrentPosition;
}

void ChessCell::setCurrentPosition(int position)
{
    mCurrentPosition = position;
}

bool ChessCell::isBlackChess() const
{
    return mIsBlackChess;
}

QString ChessCell::getImagePath() const
{
    return mImagePath;
}

QPoint ChessCell::getCurrentPosInXY() const
{
    QPoint xyPosition;
    xyPosition.setX(mCurrentPosition % NUM_OF_CELLS_PER_LINE);
    xyPosition.setY(mCurrentPosition / NUM_OF_CELLS_PER_LINE);

    return xyPosition;
}
