#include "chessboard.h"

#include <QFile>
#include <QTextStream>

#include "chesscellfactory.h"

ChessBoard::ChessBoard()
{
    for (int index = 0; index < NUM_OF_CHESS_CELLS; index++) {
        mBoardContent[index] = new ChessCell(this);
    }

    mCurrentStepInHistory = 0;
    mIsBlackTurn = false;
}

ChessBoard::~ChessBoard()
{
    for (int index = 0; index < NUM_OF_CHESS_CELLS; index++) {
        delete mBoardContent[index];
    }
}

const ChessCell *ChessBoard::getChessCellAt(int position) const
{
    return mBoardContent[position];
}

void ChessBoard::initNewGame()
{
    clearGame();

    ChessCell *newPiece;

    // Allocate Black pieces
    newPiece = new KingCell(this, INITIAL_POSITION_BLACK_KING, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new QueenCell(this, INITIAL_POSITION_BLACK_QUEEN, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new RookCell(this, INITIAL_POSITION_BLACK_FIRST_ROOK, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new RookCell(this, INITIAL_POSITION_BLACK_SECOND_ROOK, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new KnightCell(this, INITIAL_POSITION_BLACK_FIRST_KNIGHT, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new KnightCell(this, INITIAL_POSITION_BLACK_SECOND_KNIGHT, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new BishopCell(this, INITIAL_POSITION_BLACK_FIRST_BISHOP, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new BishopCell(this, INITIAL_POSITION_BLACK_SECOND_BISHOP, true);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    for(int index = 0; index < NUM_OF_CELLS_PER_LINE; index++) {
        int position = INITIAL_POSITION_BLACK_FIRST_PAWN + index;
        newPiece = new PawnCell(this, position, true);
        setChessCellAt(position, newPiece);
    }

    // Allocate White pieces
    newPiece = new KingCell(this, INITIAL_POSITION_WHITE_KING);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new QueenCell(this, INITIAL_POSITION_WHITE_QUEEN);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new RookCell(this, INITIAL_POSITION_WHITE_FIRST_ROOK);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new RookCell(this, INITIAL_POSITION_WHITE_SECOND_ROOK);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new KnightCell(this, INITIAL_POSITION_WHITE_FIRST_KNIGHT);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new KnightCell(this, INITIAL_POSITION_WHITE_SECOND_KNIGHT);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new BishopCell(this, INITIAL_POSITION_WHITE_FIRST_BISHOP);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    newPiece = new BishopCell(this, INITIAL_POSITION_WHITE_SECOND_BISHOP);
    setChessCellAt(newPiece->getCurrentPosition(), newPiece);
    for(int index = 0; index < NUM_OF_CELLS_PER_LINE; index++) {
        int position = INITIAL_POSITION_WHITE_FIRST_PAWN + index;
        newPiece = new PawnCell(this, position, false);
        setChessCellAt(position, newPiece);
    }

    mHistory.clear();
    mHistory.append(convertBoardToQString());
    mCurrentStepInHistory = 0;
    mIsBlackTurn = false;
}

void ChessBoard::clearGame()
{
    for (int index = 0; index < NUM_OF_CHESS_CELLS; index++) {
        setChessCellAt(index, new ChessCell(this, index));
    }
    mHistory.clear();
    mCurrentStepInHistory = 0;
}

QString ChessBoard::loadGame(QString filepath)
{
    filepath = filepath.replace("file://", "");
    QFile openFile (filepath);

    if (!openFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return FILE_LOAD_CANNOT_OPEN;
    }

    QTextStream inFileStream(&openFile);
    QString readLine;

    // Try to read first line
    int sizeOfHistory = 0;
    int currentStepInHistory = 0;
    if (!inFileStream.atEnd()) {
        readLine = inFileStream.readLine();
        QStringList strList = readLine.split(FILE_MAIN_SEP, QString::SkipEmptyParts);
        if (strList.size() != FILE_NUM_OF_COMP_OF_FIRST_LINE) {
            return FILE_LOAD_WRONG_CONTENT;
        } else {
            sizeOfHistory = strList.at(FILE_FIRST_LINE_HIST_POS).toInt();
            currentStepInHistory = strList.at(FILE_FIRST_LINE_HIST_STEP_POS).toInt();
            mIsBlackTurn = (strList.at(FILE_FIRST_LINE_TURN_POS).toInt() != 0);
        }
    }

    // Try to read history
    QList<QString> loadHistory;
    while (!inFileStream.atEnd()) {
        readLine = inFileStream.readLine();
        if (isValidBoardString(readLine)) {
            loadHistory.append(readLine);
        } else {
            return FILE_LOAD_WRONG_CONTENT;
        }
    }

    if (loadHistory.size() != sizeOfHistory) {
        return FILE_LOAD_WRONG_CONTENT;
    }

    mCurrentStepInHistory = currentStepInHistory;
    mHistory.clear();

    for(int index = 0; index < sizeOfHistory; index++) {
        mHistory.append(loadHistory.at(index));
    }

    restoreBoardFromQString(mHistory.at(mCurrentStepInHistory));

    return FILE_OP_SUCESS;
}

QString ChessBoard::saveGame(QString filepath)
{
    filepath = filepath.replace("file://", "");
    QFile saveFile (filepath);
    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        return FILE_SAVE_CANNOT_OPEN;
    }

    QTextStream outFileStream(&saveFile);

    outFileStream << mHistory.size() << FILE_MAIN_SEP << mCurrentStepInHistory
                  << FILE_MAIN_SEP << mIsBlackTurn << "\n";
    for(int index = 0; index < mHistory.size(); index++) {
        outFileStream << mHistory.at(index) << "\n";
    }

    saveFile.close();

    return FILE_OP_SUCESS;
}

bool ChessBoard::isPrevStepAvailable()
{
    return (mCurrentStepInHistory > 0);
}

bool ChessBoard::isNextStepAvailable()
{
    return (mCurrentStepInHistory < (mHistory.size() - 1));
}

void ChessBoard::prevStep()
{
    if (isPrevStepAvailable()) {
        mCurrentStepInHistory--;
        restoreBoardFromQString(mHistory.at(mCurrentStepInHistory));
        mIsBlackTurn = !mIsBlackTurn;
    }
}

void ChessBoard::nextStep()
{
    if (isNextStepAvailable()) {
        mCurrentStepInHistory++;
        restoreBoardFromQString(mHistory.at(mCurrentStepInHistory));
        mIsBlackTurn = !mIsBlackTurn;
    }
}

void ChessBoard::move(int sourceIndex, int destIndex)
{
    if (!isValidIndex(sourceIndex) || !isValidIndex(destIndex)
            || mBoardContent[sourceIndex]->isBlackChess() != mIsBlackTurn
            || isGameOver()) {
        return;
    }

    QList<int> possibleMoves = mBoardContent[sourceIndex]->getPossibleMoves();
    int index = 0;
    for(index = 0; index < possibleMoves.size(); index++) {
        if (destIndex == possibleMoves.at(index)) {
            break;
        }
    }

    if (index < possibleMoves.size()) {
        mBoardContent[sourceIndex]->setCurrentPosition(destIndex);
        setChessCellAt(destIndex, mBoardContent[sourceIndex]);
        mBoardContent[sourceIndex] = new ChessCell(this, sourceIndex);

        //Clear future moves if available
        while (mHistory.size() > (mCurrentStepInHistory + 1)) {
            mHistory.removeLast();
        }

        mHistory.append(convertBoardToQString());
        mCurrentStepInHistory++;

        mIsBlackTurn = !mIsBlackTurn;
    }
}

bool ChessBoard::isValidIndex(int index) const
{
    return (index >=0 && index < NUM_OF_CHESS_CELLS);
}

bool ChessBoard::isValidBlankCell(int index) const
{
    if (isValidIndex(index)) {
        return (mBoardContent[index]->getPieceName() == "");
    }
    return false;
}

bool ChessBoard::isValidBlankCellXY(int x, int y) const
{
    if (x < 0 || x >= NUM_OF_CELLS_PER_LINE || y < 0 || y >= NUM_OF_CELLS_PER_LINE) {
        return false;
    }

    int index = convertPosInXYToBase(x, y);
    return (mBoardContent[index]->getPieceName() == "");
}

bool ChessBoard::isValidNotBlankCellXY(int x, int y) const
{
    if (x < 0 || x >= NUM_OF_CELLS_PER_LINE || y < 0 || y >= NUM_OF_CELLS_PER_LINE) {
        return false;
    }

    int index = convertPosInXYToBase(x, y);
    return (mBoardContent[index]->getPieceName() != "");
}

bool ChessBoard::isTeamMateCellXY(bool isBlackChess, int x, int y) const
{
    if (x < 0 || x >= NUM_OF_CELLS_PER_LINE || y < 0 || y >= NUM_OF_CELLS_PER_LINE) {
        return false;
    }

    int index = convertPosInXYToBase(x, y);
    return (mBoardContent[index]->getPieceName() != "" && (mBoardContent[index]->isBlackChess() == isBlackChess));
}

int ChessBoard::convertPosInXYToBase(QPoint xyPosition) const
{
    return (xyPosition.y() * NUM_OF_CELLS_PER_LINE + xyPosition.x());
}

int ChessBoard::convertPosInXYToBase(int x, int y) const
{
    return (y * NUM_OF_CELLS_PER_LINE + x);
}

void ChessBoard::getListPossibleMovesForDirection(int index, int xDirection, int yDirection,
                                                  int far, QList<int> &possibleMoves) const
{
    if (far == 0) {
        far = NUM_OF_CELLS_PER_LINE;
    }

    if (!isValidIndex(index)) {
        return;
    }

    QPoint xyPos = mBoardContent[index]->getCurrentPosInXY();
    int x = xyPos.x();
    int y = xyPos.y();
    int isBlackChess = mBoardContent[index]->isBlackChess();

    for(int delta = 1; delta <= far; delta++) {
        int newX = x + xDirection*delta;
        int newY = y + yDirection*delta;
        int newIndex = convertPosInXYToBase(newX, newY);
        if(isValidBlankCellXY(newX, newY)) {
            possibleMoves.append(newIndex);
        } else {
            if (isValidNotBlankCellXY(newX, newY) && !isTeamMateCellXY(isBlackChess, newX, newY)) {
                possibleMoves.append(newIndex);
            }

            // Blocked or not valid, no need to go further
            break;
        }
    }
}

bool ChessBoard::checkForPawnPromotion(int index) const
{
    bool ret = false;
    if (isValidIndex(index) && mBoardContent[index]->getPieceName() == PAWN_STR) {
        if (mBoardContent[index]->isBlackChess()) {  // check if the black pawn reach to the bottom line
            if(mBoardContent[index]->getCurrentPosInXY().y() == (NUM_OF_CELLS_PER_LINE - 1)) {  // y = 7
                ret = true;
            }
        } else { // check if the black pawn reach to the top line
            if(mBoardContent[index]->getCurrentPosInXY().y() == 0) {  // y = 0
                ret = true;
            }
        }
    }

    return ret;
}

void ChessBoard::replacePawn(int index, QString newRole)
{
    if (isValidIndex(index) && mBoardContent[index]->getPieceName() == PAWN_STR) {
        ChessCellFactory factory;
        setChessCellAt(index, factory.produceChessCell(this, newRole, index, mBoardContent[index]->isBlackChess()));
    }
}

bool ChessBoard::isGameOver() const
{
    //Check the remaining of the King on the board
    bool ret = true;
    if (mHistory.size() != 0) {
        for(int index = 0; index < NUM_OF_CHESS_CELLS; index++) {
            if(mBoardContent[index]->getPieceName() == KING_STR && (mBoardContent[index]->isBlackChess() == mIsBlackTurn)) {
                ret = false;
            }
        }
    } else {
        ret = false;
    }
    return ret;
}

void ChessBoard::setChessCellAt(int position, ChessCell * newCell)
{
    if (newCell != NULL) {
        delete mBoardContent[position];
        mBoardContent[position] = newCell;
    }
}

QString ChessBoard::convertBoardToQString() const
{
    QString resultStr = "";
    for(int index = 0; index < NUM_OF_CHESS_CELLS; index++) {
        if(mBoardContent[index]->getPieceName() != "") {
            resultStr = resultStr + mBoardContent[index]->getPieceName()
                    + FILE_PIECE_COMP_SEP
                    + QString::number(mBoardContent[index]->isBlackChess())
                    + FILE_PIECE_COMP_SEP
                    + QString::number(mBoardContent[index]->getCurrentPosition())
                    + FILE_MAIN_SEP;
        }
    }

    resultStr;
    return resultStr;
}

bool ChessBoard::isValidBoardString(QString boardContent) const
{
    QStringList listPieces = boardContent.split(FILE_MAIN_SEP, QString::SkipEmptyParts);
    if (listPieces.size() == 0) {
        return false;
    }

    for (int index = 0; index < listPieces.size(); index++) {
        QStringList piecesComponent = listPieces.at(index).split(FILE_PIECE_COMP_SEP, QString::SkipEmptyParts);
        if (piecesComponent.size() != FILE_NUM_OF_COMP_PER_PIECE) {
            return false;
        }
    }

    return true;
}

void ChessBoard::restoreBoardFromQString(QString boardContent)
{
    // Reset board to blank
    for(int index = 0; index < NUM_OF_CHESS_CELLS; index++) {
        setChessCellAt(index, new ChessCell(this, index));
    }

    QStringList listPieces = boardContent.split(FILE_MAIN_SEP);
    if (listPieces.size() > 0) {
        ChessCellFactory factory;
        int position;
        bool isBlackChess;
        for (int index = 0; index < listPieces.size(); index++) {
            QStringList piecesComponent = listPieces.at(index).split(FILE_PIECE_COMP_SEP, QString::SkipEmptyParts);
            if (piecesComponent.size() == FILE_NUM_OF_COMP_PER_PIECE) {
                isBlackChess = piecesComponent.at(FILE_PIECE_TEAM_POS).toInt() != 0;
                position = piecesComponent.at(FILE_PIECE_INDEX_POS).toInt();
                setChessCellAt(position,
                    factory.produceChessCell(this, piecesComponent.at(FILE_PIECE_NAME_POS), position, isBlackChess));
            }
        }
    }
}
