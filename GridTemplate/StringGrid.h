#pragma once

#include "Grid.h"

template <>
class Grid<string>
{
public:
	Grid(const size_t width = 3, const size_t height = 3);
	virtual ~Grid();
	virtual void setCell(size_t x, size_t y, const string& cellName, const string& inCell);
	virtual pair<string, string>& getCell(size_t x, size_t y);
	virtual void addCell(size_t x, size_t y, const string& inCell);
	virtual string getInfoAt(size_t x, size_t y);
	virtual size_t getKHeight() const;
	virtual size_t hgtKWidth() const;

private:
	bool inRange(const size_t x, const size_t y);
	const size_t kWidth;
	const size_t kHeight;
	vector<vector<pair<string, string>>> cells;
};


Grid<string>::Grid(const size_t width, const size_t height) : kWidth(width), kHeight(height) {
	cells.resize(kWidth);
	for (auto& cell : cells) {
		cell.resize(kHeight);
	}
}

Grid<string>::~Grid() {}

void Grid<string>::setCell(size_t x, size_t y, const string& cellName, const string& inCell) {
	cells[x][y] = make_pair(cellName, inCell);
}

pair< string, string>& Grid<string>::getCell(size_t x, size_t y) {
	return cells[x][y];
}

void Grid<string>::addCell(size_t x, size_t y, const string& inCell) {
	if (cells[x][y].first.empty() && cells[x][y].second.empty()) {
		return;
	}
	auto tmp = cells[x][y];
	cells[x][y].second += ", " + inCell;
}


size_t Grid<string>::getKHeight() const {
	return kHeight;
}


size_t Grid<string>::hgtKWidth() const {
	return kWidth;
}

string Grid<string>::getInfoAt(size_t x, size_t y) {
	ostringstream oss;
	if (cells[x][y].first.empty()) {
		oss << "cell(" << x << "," << y << ") is empty";
	}
	else {
		oss << cells[x][y].first << "(" << x << "," << y << "): ";
		oss << cells[x][y].second;
	}

	return oss.str();
}

bool Grid<string>::inRange(const size_t x, const size_t y) {
	if (x < 0 || x >= kWidth || y < 0 || y >= kHeight) {
		return false;
	}

	return true;
}
