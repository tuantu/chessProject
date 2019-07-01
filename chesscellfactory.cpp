#include "chesscellfactory.h"

ChessCellFactory::ChessCellFactory()
{

}

ChessCellFactory::~ChessCellFactory()
{

}

ChessCell* ChessCellFactory::produceChessCell (ChessBoard *board, QString pieceName, int position, bool isBlackChess) const
{
    if (pieceName == KING_STR) {
        return new KingCell(board, position, isBlackChess);
    } else if (pieceName == QUEEN_STR) {
        return new QueenCell(board, position, isBlackChess);
    } else if (pieceName == ROOK_STR) {
        return new RookCell(board, position, isBlackChess);
    } else if (pieceName == KNIGHT_STR) {
        return new KnightCell(board, position, isBlackChess);
    } else if (pieceName == BISHOP_STR) {
        return new BishopCell(board, position, isBlackChess);
    } else if (pieceName == PAWN_STR) {
        return new PawnCell(board, position, isBlackChess);
    } else {
        return new ChessCell(board, position, isBlackChess);
    }
}
