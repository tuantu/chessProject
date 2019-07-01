#include "knightcell.h"
#include "chessboard.h"

KnightCell::KnightCell(ChessBoard *board, int position, bool isBlackChess) : ChessCell(board, position, isBlackChess)
{
    mPieceName = KNIGHT_STR;
    mImagePath = KNIGHT_PRE_IMG_PATH;
    if (isBlackChess) {
        mImagePath = mImagePath + IMAGE_BLACK_SUFFIX;
    } else {
        mImagePath = mImagePath + IMAGE_WHITE_SUFFIX;
    }
}

KnightCell::~KnightCell()
{

}

QList<int> KnightCell::getPossibleMoves() const
{
    QList<int> possibleMoveList;

    QPoint xyPosition = getCurrentPosInXY();
    int x = xyPosition.x();
    int y = xyPosition.y();

    QList<int> possibleXMoves;
    QList<int> possibleYMoves;

    // check up->right pos
    possibleXMoves.append(x + 1);
    possibleYMoves.append(y - 2);

    // check up->left pos
    possibleXMoves.append(x - 1);
    possibleYMoves.append(y - 2);

    // check bottom->right pos
    possibleXMoves.append(x + 1);
    possibleYMoves.append(y + 2);

    // check bottom->left pos
    possibleXMoves.append(x - 1);
    possibleYMoves.append(y + 2);

    // check right->up pos
    possibleXMoves.append(x + 2);
    possibleYMoves.append(y - 1);

    // check right->bottom pos
    possibleXMoves.append(x + 2);
    possibleYMoves.append(y + 1);

    // check left->up pos
    possibleXMoves.append(x - 2);
    possibleYMoves.append(y - 1);

    // check left->bottom pos
    possibleXMoves.append(x - 2);
    possibleYMoves.append(y + 1);

    for(int index = 0; index < possibleXMoves.size(); index++) {
        int newX = possibleXMoves.at(index);
        int newY = possibleYMoves.at(index);
        int newIndex = mBoard->convertPosInXYToBase(newX, newY);
        if (mBoard->isValidBlankCellXY(newX, newY)) {
            possibleMoveList.append(newIndex);
        } else if (mBoard->isValidNotBlankCellXY(newX, newY) &&
                   !mBoard->isTeamMateCellXY(mIsBlackChess, newX, newY)) {
            possibleMoveList.append(newIndex);
        }
    }
    return possibleMoveList;
}
