#include "pch.h"
#include "GameBoard.h"


GameBoard::GameBoard(const string& inBoardName, const size_t width, const size_t height) : Grid<GamePiece>(width, height), boardName(inBoardName) {

}


GameBoard::~GameBoard()
{
}

void GameBoard::movePiece(const pair<size_t, size_t>& orig, const pair<size_t, size_t>& dst) {
	auto& tmp = getCell(orig.first, orig.second);
	setCell(dst.first, dst.second, "something", tmp.second);
	setCell(orig.first, orig.second, "", GamePiece());
	//setCell(dst.first, dst.second, "something", std::move(tmp.second))
	//implementar move semantics
}
