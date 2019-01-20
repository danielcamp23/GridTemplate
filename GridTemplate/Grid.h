#pragma once

#include <vector>
#include <string>
#include <utility>
#include <sstream>

using std::vector;
using std::pair;
using std::string;
using std::ostringstream;

template <typename T>
class Grid
{
public:
	Grid(const size_t width = 3, const size_t height = 3);
	void setCell(size_t x, size_t y, const string& cellName, const T& inCell);
	void addCell(size_t x, size_t y, const T& inCell);
	string getInfoAt(size_t x, size_t y);

private:
	const size_t kWidth;
	const size_t kHeight;
	vector<vector<pair<string, T>>> cells;
};


template <typename T>
Grid<T>::Grid(const size_t width, const size_t height) : kWidth(width), kHeight(height) {
	cells.resize(kWidth);
	for (auto& cell : cells) {
		cell.resize(kHeight);
	}
}


template <typename T>
void Grid<T>::setCell(size_t x, size_t y, const string& cellName, const T& inCell) {
	cells[x][y] = make_pair(cellName, inCell);
}

template <typename T>
void Grid<T>::addCell(size_t x, size_t y, const T& inCell) {
	auto tmp = cells[x][y];
	cells[x][y].second = tmp.second + inCell;
}

template <typename T>
string Grid<T>::getInfoAt(size_t x, size_t y) {
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
