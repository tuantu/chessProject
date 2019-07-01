#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chesscell.h"
#include "kingcell.h"
#include "queencell.h"
#include "rookcell.h"
#include "knightcell.h"
#include "bishopcell.h"
#include "pawncell.h"

class ChessBoard
{
public:
    explicit ChessBoard();
    ~ChessBoard();

    const ChessCell * getChessCellAt(int position) const;

    void initNewGame();
    void clearGame();

    QString loadGame(QString filepath);
    QString saveGame(QString filepath);

    bool isPrevStepAvailable();    // Return true if able to back to previous step in hostory
    bool isNextStepAvailable();    // Return true if able to move to next step in history
    void prevStep();
    void nextStep();

    void move(int sourceIndex, int destIndex);

    bool isValidIndex(int index) const;
    bool isValidBlankCell(int index) const;
    bool isValidBlankCellXY(int x, int y) const;
    bool isValidNotBlankCellXY(int x, int y) const;
    bool isTeamMateCellXY(bool isBlackChess, int x, int y) const;

    int convertPosInXYToBase(QPoint xyPosition) const;
    int convertPosInXYToBase(int x, int y) const;

    // give far = 0 for maximum move further
    void getListPossibleMovesForDirection(int index, int xDirection, int yDirection, int far, QList<int>& possibleMoves) const;

    bool checkForPawnPromotion(int index) const;
    void replacePawn(int index, QString newRole);

    bool isGameOver() const;

protected:
    ChessCell* mBoardContent[NUM_OF_CHESS_CELLS];

    QList<QString> mHistory;
    int mCurrentStepInHistory;
    bool mIsBlackTurn;

protected:

private:
    void setChessCellAt(int position, ChessCell * newCell);
    QString convertBoardToQString() const;
    bool isValidBoardString(QString boardContent) const;
    void restoreBoardFromQString(QString boardContent);
};

#endif // CHESSBOARD_H
