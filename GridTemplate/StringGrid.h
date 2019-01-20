#pragma once

#include "Grid.h"


using std::vector;
using std::pair;
using std::string;
using std::ostringstream;

template <>
class Grid<string>
{
public:
	Grid(const size_t width = 3, const size_t height = 3);
	void setCell(size_t x, size_t y, const string& cellName, const string& inCell);
	void addCell(size_t x, size_t y, const string& inCell);
	string getInfoAt(size_t x, size_t y);
	size_t getHeight();
private:
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

size_t Grid<string>::getHeight() {
	return kHeight;
}

void Grid<string>::setCell(size_t x, size_t y, const string& cellName, const string& inCell) {
	cells[x][y] = make_pair(cellName, inCell);
}


void Grid<string>::addCell(size_t x, size_t y, const string& inCell) {
	if (cells[x][y].first.empty() && cells[x][y].second.empty()) {
		return;
	}
	auto tmp = cells[x][y];
	cells[x][y].second += ", " + inCell;
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
