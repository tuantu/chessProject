#ifndef KNIGHTCELL_H
#define KNIGHTCELL_H

#include "chesscell.h"

class KnightCell : public ChessCell
{
public:
    explicit KnightCell(ChessBoard *board, int position, bool isBlackChess = false);
    ~KnightCell();

    QList<int> getPossibleMoves() const;
};

#endif // KNIGHTCELL_H
