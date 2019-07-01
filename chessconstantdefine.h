#ifndef CHESSCONSTANTDEFINE
#define CHESSCONSTANTDEFINE

#define NUM_OF_CHESS_CELLS 64
#define NUM_OF_CELLS_PER_LINE 8

#define INITIAL_POSITION_BLACK_KING 4
#define INITIAL_POSITION_WHITE_KING 60

#define INITIAL_POSITION_BLACK_QUEEN 3
#define INITIAL_POSITION_WHITE_QUEEN 59

#define INITIAL_POSITION_BLACK_FIRST_ROOK 0
#define INITIAL_POSITION_BLACK_SECOND_ROOK 7
#define INITIAL_POSITION_WHITE_FIRST_ROOK 56
#define INITIAL_POSITION_WHITE_SECOND_ROOK 63

#define INITIAL_POSITION_BLACK_FIRST_KNIGHT 1
#define INITIAL_POSITION_BLACK_SECOND_KNIGHT 6
#define INITIAL_POSITION_WHITE_FIRST_KNIGHT 57
#define INITIAL_POSITION_WHITE_SECOND_KNIGHT 62

#define INITIAL_POSITION_BLACK_FIRST_BISHOP 2
#define INITIAL_POSITION_BLACK_SECOND_BISHOP 5
#define INITIAL_POSITION_WHITE_FIRST_BISHOP 58
#define INITIAL_POSITION_WHITE_SECOND_BISHOP 61

#define INITIAL_POSITION_BLACK_FIRST_PAWN 8
#define INITIAL_POSITION_WHITE_FIRST_PAWN 48

#define KING_STR "King"
#define QUEEN_STR "Queen"
#define ROOK_STR "Rook"
#define KNIGHT_STR "Knight"
#define BISHOP_STR "Bishop"
#define PAWN_STR "Pawn"

#define KING_PRE_IMG_PATH "qrc:/images/king_"
#define QUEEN_PRE_IMG_PATH "qrc:/images/queen_"
#define ROOK_PRE_IMG_PATH "qrc:/images/rook_"
#define KNIGHT_PRE_IMG_PATH "qrc:/images/knight_"
#define BISHOP_PRE_IMG_PATH "qrc:/images/bishop_"
#define PAWN_PRE_IMG_PATH "qrc:/images/pawn_"
#define IMAGE_BLACK_SUFFIX "black.png"
#define IMAGE_WHITE_SUFFIX "white.png"

#define MODEL_ROLE_NAME "name"
#define MODEL_ROLE_TEAM "team"
#define MODEL_ROLE_IMAGE "image"

#define MODEL_TEAM_BLACK_COLOR "#b8e293"
#define MODEL_TEAM_WHITE_COLOR "#f39a9a"

#define FILE_LOAD_CANNOT_OPEN "Cannot open the selected file"
#define FILE_LOAD_WRONG_CONTENT "Selected file's content is corrupted"

#define FILE_SAVE_CANNOT_OPEN "Cannot create file for saving"

#define FILE_OP_SUCESS ""

#define FILE_NUM_OF_COMP_PER_PIECE 3
#define FILE_NUM_OF_COMP_OF_FIRST_LINE 3

#define FILE_MAIN_SEP "|"
#define FILE_PIECE_COMP_SEP ","

#define FILE_FIRST_LINE_HIST_POS 0
#define FILE_FIRST_LINE_HIST_STEP_POS 1
#define FILE_FIRST_LINE_TURN_POS 2

#define FILE_PIECE_NAME_POS 0
#define FILE_PIECE_TEAM_POS 1
#define FILE_PIECE_INDEX_POS 2

#define KNIGHT_POSSIBLE_NUM_OF_MOVES 8

#endif // CHESSCONSTANTDEFINE
