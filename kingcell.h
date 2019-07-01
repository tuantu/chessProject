#ifndef KINGCELL_H
#define KINGCELL_H

#include "chesscell.h"

class KingCell : public ChessCell
{
public:
    explicit KingCell(ChessBoard *board, int position, bool isBlackChess = false);
    ~KingCell();

    QList<int> getPossibleMoves() const;
};

#endif // KINGCELL_H
