#ifndef PAWNCELL_H
#define PAWNCELL_H

#include "chesscell.h"

class PawnCell : public ChessCell
{
public:
    explicit PawnCell(ChessBoard *board, int position, bool isBlackChess = false);
    ~PawnCell();

    QList<int> getPossibleMoves() const;

private:
    int mInitialPosition;
};

#endif // PAWNCELL_H
