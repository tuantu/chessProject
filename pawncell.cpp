#include "pawncell.h"
#include "chessboard.h"

PawnCell::PawnCell(ChessBoard *board, int position, bool isBlackChess) : ChessCell(board, position, isBlackChess)
{
    mPieceName = PAWN_STR;
    int firstPawnPos = (isBlackChess) ? INITIAL_POSITION_BLACK_FIRST_PAWN
                                      : INITIAL_POSITION_WHITE_FIRST_PAWN;
    if (position >= firstPawnPos && position < firstPawnPos + NUM_OF_CELLS_PER_LINE) {
        mInitialPosition = position;
    } else {
        mInitialPosition = -1;
    }

    mImagePath = PAWN_PRE_IMG_PATH;
    if (isBlackChess) {
        mImagePath = mImagePath + IMAGE_BLACK_SUFFIX;
    } else {
        mImagePath = mImagePath + IMAGE_WHITE_SUFFIX;
    }
}

PawnCell::~PawnCell()
{

}

QList<int> PawnCell::getPossibleMoves() const
{
    QList<int> possibleMoveList;

    QPoint xyPosition = getCurrentPosInXY();

    int direction = 1;
    if (!isBlackChess()) {
        direction = -1;
    }

    // Check the head-to-head cell
    bool isBlocked = false;
    QPoint headToHeadXYPos;
    headToHeadXYPos.setX(xyPosition.x());
    headToHeadXYPos.setY(xyPosition.y() + direction);
    int headToHeadPos = mBoard->convertPosInXYToBase(headToHeadXYPos);
    if (mBoard->isValidBlankCell(headToHeadPos)) {
        possibleMoveList.append(headToHeadPos);
    } else {
        isBlocked = true;
    }

    // If initial, the pawn can move 2 cell further
    if (!isBlocked && mCurrentPosition == mInitialPosition) {
        int headTwoCellPos = mBoard->convertPosInXYToBase(headToHeadXYPos.x(), headToHeadXYPos.y() + direction);
        if (mBoard->isValidBlankCell(headTwoCellPos)) {
            possibleMoveList.append(headTwoCellPos);
        }
    }

    // Check left for capture
    int leftHeadX = headToHeadXYPos.x() - 1;
    int headLeftCellPos = mBoard->convertPosInXYToBase(leftHeadX, headToHeadXYPos.y());
    if (mBoard->isValidNotBlankCellXY(leftHeadX, headToHeadXYPos.y())
            && !mBoard->isTeamMateCellXY(mIsBlackChess, leftHeadX, headToHeadXYPos.y())) {
        possibleMoveList.append(headLeftCellPos);
    }

    // Check right for capture
    int rightHeadX = headToHeadXYPos.x() + 1;
    int headRightCellPos = mBoard->convertPosInXYToBase(rightHeadX, headToHeadXYPos.y());
    if (mBoard->isValidNotBlankCellXY(rightHeadX, headToHeadXYPos.y())
            && !mBoard->isTeamMateCellXY(mIsBlackChess, rightHeadX, headToHeadXYPos.y())) {
        possibleMoveList.append(headRightCellPos);
    }

    return possibleMoveList;
}
