#include "bishopcell.h"
#include "chessboard.h"

BishopCell::BishopCell(ChessBoard *board, int position, bool isBlackChess) : ChessCell(board, position, isBlackChess)
{
    mPieceName = BISHOP_STR;
    mImagePath = BISHOP_PRE_IMG_PATH;
    if (isBlackChess) {
        mImagePath = mImagePath + IMAGE_BLACK_SUFFIX;
    } else {
        mImagePath = mImagePath + IMAGE_WHITE_SUFFIX;
    }

}

BishopCell::~BishopCell()
{

}

QList<int> BishopCell::getPossibleMoves() const
{
    QList<int> possibleMoveList;

    // Check top left
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, -1, -1, 0, possibleMoveList);
    // Check top right
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 1, -1, 0, possibleMoveList);
    // Check bottom left
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, -1, 1, 0, possibleMoveList);
    // Check bottom right
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 1, 1, 0, possibleMoveList);

    return possibleMoveList;
}
