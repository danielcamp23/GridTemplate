#pragma once
#include "Grid.h"
#include "GamePiece.h"

using std::pair;
using std::string;

class GameBoard : public Grid<GamePiece>
{
public:
	GameBoard(const string& inBoardName, const size_t width, const size_t heigth);
	~GameBoard();
	void movePiece(const pair<size_t, size_t>& orig, const pair<size_t, size_t>& dst);

private:
	string boardName;
};

