#ifndef BISHOPCELL_H
#define BISHOPCELL_H

#include "chesscell.h"

class BishopCell : public ChessCell
{
public:
    BishopCell(ChessBoard *board, int position, bool isBlackChess = false);
    ~BishopCell();

    QList<int> getPossibleMoves() const;
};

#endif // BISHOPCELL_H
