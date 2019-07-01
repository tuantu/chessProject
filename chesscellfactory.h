#ifndef CHESSCELLFACTORY_H
#define CHESSCELLFACTORY_H

#include "chessboard.h"

class ChessCellFactory
{
public:
    ChessCellFactory();
    ~ChessCellFactory();

    ChessCell* produceChessCell (ChessBoard *board, QString pieceName, int position, bool isBlackChess) const;
};

#endif // CHESSCELLFACTORY_H
