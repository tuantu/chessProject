#include "kingcell.h"
#include "chessboard.h"

KingCell::KingCell(ChessBoard *board, int position, bool isBlackChess) : ChessCell (board, position, isBlackChess)
{
    mPieceName = KING_STR;
    mImagePath = KING_PRE_IMG_PATH;
    if (isBlackChess) {
        mImagePath = mImagePath + IMAGE_BLACK_SUFFIX;
    } else {
        mImagePath = mImagePath + IMAGE_WHITE_SUFFIX;
    }
}

KingCell::~KingCell()
{

}

QList<int> KingCell::getPossibleMoves() const
{
    QList<int> possibleMoveList;

    // Check right
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 1, 0, 1, possibleMoveList);
    // Check left
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, -1, 0, 1, possibleMoveList);
    // Check bottom
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 0, 1, 1, possibleMoveList);
    // Check top
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 0, -1, 1, possibleMoveList);
    // Check top left
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, -1, -1, 1, possibleMoveList);
    // Check top right
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 1, -1, 1, possibleMoveList);
    // Check bottom left
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, -1, 1, 1, possibleMoveList);
    // Check bottom right
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 1, 1, 1, possibleMoveList);

    return possibleMoveList;
}
