#include "rookcell.h"
#include "chessboard.h"

RookCell::RookCell(ChessBoard *board, int position, bool isBlackChess) : ChessCell(board, position, isBlackChess)
{
    mPieceName = ROOK_STR;
    mImagePath = ROOK_PRE_IMG_PATH;
    if (isBlackChess) {
        mImagePath = mImagePath + IMAGE_BLACK_SUFFIX;
    } else {
        mImagePath = mImagePath + IMAGE_WHITE_SUFFIX;
    }

}

RookCell::~RookCell()
{

}

QList<int> RookCell::getPossibleMoves() const
{
    QList<int> possibleMoveList;

    // Check right
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 1, 0, 0, possibleMoveList);
    // Check left
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, -1, 0, 0, possibleMoveList);
    // Check bottom
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 0, 1, 0, possibleMoveList);
    // Check top
    mBoard->getListPossibleMovesForDirection(mCurrentPosition, 0, -1, 0, possibleMoveList);

    return possibleMoveList;
}
