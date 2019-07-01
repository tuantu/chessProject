#include "queencell.h"
#include "chessboard.h"

QueenCell::QueenCell(ChessBoard *board, int position, bool isBlackChess) : ChessCell (board, position, isBlackChess)
{
    mPieceName = QUEEN_STR;
    mImagePath = QUEEN_PRE_IMG_PATH;
    if (isBlackChess) {
        mImagePath = mImagePath + IMAGE_BLACK_SUFFIX;
    } else {
        mImagePath = mImagePath + IMAGE_WHITE_SUFFIX;
    }

}

QueenCell::~QueenCell()
{

}

QList<int> QueenCell::getPossibleMoves() const
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
