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
	virtual ~Grid();
	virtual void setCell(const size_t x, const size_t y, const string& cellName, const T& inCell);
	virtual pair<string, T>& getCell(const size_t x, const size_t y);
	virtual void addCell(const size_t x, const size_t y, const T& inCell);
	virtual string getInfoAt(const size_t x, const size_t y);
	virtual size_t getKHeight() const;
	virtual size_t hgtKWidth() const;

private:
	bool inRange(const size_t x, const size_t y);
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
Grid<T>::~Grid() {}


template <typename T>
void Grid<T>::setCell(const size_t x, const size_t y, const string& cellName, const T& inCell) {
	cells[x][y] = make_pair(cellName, inCell);
}

template <typename T>
pair<string, T>& Grid<T>::getCell(const size_t x, const size_t y) {
	return cells[x][y];
}

template <typename T>
void Grid<T>::addCell(const size_t x, const size_t y, const T& inCell) {
	auto tmp = cells[x][y];
	cells[x][y].second = tmp.second + inCell;
}

template <typename T>
string Grid<T>::getInfoAt(const size_t x, const size_t y) {
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

template <typename T>
size_t Grid<T>::getKHeight() const {
	return kHeight;
}

template <typename T>
size_t Grid<T>::hgtKWidth() const {
	return kWidth;
}

template <typename T>
bool Grid<T>::inRange(const size_t x, const size_t y) {
	if (x < 0 || x >= kWidth || y < 0 || y >= kHeight) {
		return false;
	}

	return true;
}

