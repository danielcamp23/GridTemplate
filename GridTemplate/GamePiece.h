#pragma once
#include <string>

using std::string;

class GamePiece
{
public:
	GamePiece();
	GamePiece(const string& inName);
	~GamePiece();
	string getName() const;

private:
	string name;
};

