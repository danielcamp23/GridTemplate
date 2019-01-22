#include "pch.h"
#include "GamePiece.h"

GamePiece::GamePiece(){}

GamePiece::GamePiece(const string & inName) : name(inName)
{
}

GamePiece::~GamePiece()
{
}



string GamePiece::getName() const
{
	return name;
}
