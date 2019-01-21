// GridTemplate.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Grid.h"
#include "StringGrid.h"
#include <string>

using std::endl;
using std::cout;

int main()
{
	Grid<string> despensa(5, 5);
	despensa.setCell(0, 1, "Despensa 1", "Arroz");
	despensa.setCell(1, 1, "Despensa 2", "Panela");
	despensa.addCell(1, 1, "huevos");
	cout << despensa.getInfoAt(1, 1) << endl;

	Grid<int> registradora(4, 4);
	registradora.setCell(0, 1, "Monedas $100", 10);
	registradora.setCell(1, 1, "Monedas $200", 4);
	cout << registradora.getInfoAt(1, 1) << endl;
	registradora.addCell(1, 1, 1);
	cout << registradora.getInfoAt(1, 1) << endl;

}
