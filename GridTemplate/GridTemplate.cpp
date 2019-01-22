// GridTemplate.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
//#include "Grid.h"
#include "GamePieceGrid.h"
#include "StringGrid.h"
#include "GameBoard.h"

#include <iostream>
#include <string>
#include <utility>

using std::endl;
using std::cout;
using std::make_pair;


int main()
{
	Grid<string> foodPantry(3, 2);
	foodPantry.setCell(0, 1, "Box 1", "Milk");
	foodPantry.setCell(1, 1, "Box 2", "Eggs");
	foodPantry.addCell(0, 1, "Coffee");
	foodPantry.addCell(0, 1, "Orange juice");
	foodPantry.addCell(1, 1, "Flour");
	cout << foodPantry.getInfoAt(1, 1) << endl;
	cout << foodPantry.getInfoAt(0, 1) << endl;

	cout << "\n";
	Grid<int> cashRegister(2, 2);
	cashRegister.setCell(0, 0, "$50", 100);
	cashRegister.setCell(1, 1, "$100", 100);
	cashRegister.setCell(1, 0, "$200", 100);
	cashRegister.setCell(1, 1, "$500", 100);
	cout << cashRegister.getInfoAt(1, 1) << endl;
	cashRegister.addCell(1, 1, 75);
	cout << cashRegister.getInfoAt(1, 1) << endl;

	cout << "\n";
	cout << "\n";

	/*
	GameBoard triki("triki", 2, 2);
	cout << triki.getInfoAt(0, 0) << endl;
	cout << triki.getInfoAt(0, 1) << endl;

	triki.setCell(0, 0, "", GamePiece("Pawn"));
	cout << triki.getInfoAt(0, 0) << endl;
	cout << triki.getInfoAt(0, 1) << endl;

	triki.movePiece(make_pair(0, 0), make_pair(0, 1));
	cout << triki.getInfoAt(0, 0) << endl;
	cout << triki.getInfoAt(0, 1) << endl;
	*/

	return 0;
}
