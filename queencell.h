#ifndef QUEENCELL_H
#define QUEENCELL_H

#include"chesscell.h"

class QueenCell : public ChessCell
{
public:
    explicit QueenCell(ChessBoard *board, int position, bool isBlackChess = false);
    ~QueenCell();

    QList<int> getPossibleMoves() const;
};

#endif // QUEENCELL_H
