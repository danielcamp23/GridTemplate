#pragma once
#include "GamePiece.h"
#include "GamePieceGrid.h"

class GameBoard : public Grid<GamePiece>
{
public:
	GameBoard(const string& inBoardName, const size_t width, const size_t heigth);
	virtual ~GameBoard();
	void movePiece(const pair<size_t, size_t>& orig, const pair<size_t, size_t>& dst);
private:
	string boardName;
};

