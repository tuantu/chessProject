#ifndef ROOKCELL_H
#define ROOKCELL_H

#include "chesscell.h"

class RookCell : public ChessCell
{
public:
    explicit RookCell(ChessBoard *board, int position, bool isBlackChess = false);
    ~RookCell();

    QList<int> getPossibleMoves() const;
};

#endif // ROOKCELL_H
