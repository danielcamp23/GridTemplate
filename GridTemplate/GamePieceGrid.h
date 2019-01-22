#pragma once

#include "Grid.h"
#include "GamePiece.h"



template <>
class Grid<GamePiece>
{
public:
	Grid(const size_t width = 3, const size_t height = 3);
	virtual ~Grid();
	virtual void setCell(const size_t x, const size_t y, const string& cellName, const GamePiece& inCell);
	virtual pair<string, GamePiece>& getCell(const size_t x, const size_t y);
	virtual void addCell(const size_t x, const size_t y, const GamePiece& inCell);
	virtual string getInfoAt(const size_t x, const size_t y);
	virtual size_t getKHeight() const;
	virtual size_t hgtKWidth() const;

private:
	bool inRange(const size_t x, const size_t y);
	const size_t kWidth;
	const size_t kHeight;
	vector<vector<pair<string, GamePiece>>> cells;
};



Grid<GamePiece>::Grid(const size_t width, const size_t height) : kWidth(width), kHeight(height) {
	cells.resize(kWidth);
	for (auto& cell : cells) {
		cell.resize(kHeight);
	}
}

Grid<GamePiece>::~Grid() {}


void Grid<GamePiece>::setCell(const size_t x, const size_t y, const string& cellName, const GamePiece& inCell) {
	cells[x][y] = make_pair(cellName, inCell);
}


pair<string, GamePiece>& Grid<GamePiece>::getCell(const size_t x, const size_t y) {
	return cells[x][y];
}


void Grid<GamePiece>::addCell(const size_t x, const size_t y, const GamePiece& inCell) {
	return;//No tiene sentido sumar dos celdas
}


string Grid<GamePiece>::getInfoAt(const size_t x, const size_t y) {
	ostringstream oss;
	if (cells[x][y].first.empty()) {
		oss << "cell(" << x << "," << y << ") is empty";
	}
	else {
		oss << cells[x][y].first << "(" << x << "," << y << "): ";
		oss << cells[x][y].second.getName();
	}

	return oss.str();
}

size_t Grid<GamePiece>::getKHeight() const {
	return kHeight;
}


size_t Grid<GamePiece>::hgtKWidth() const {
	return kWidth;
}


bool Grid<GamePiece>::inRange(const size_t x, const size_t y) {
	if (x < 0 || x >= kWidth || y < 0 || y >= kHeight) {
		return false;
	}

	return true;
}
