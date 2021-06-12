#pragma once
#include <iostream>
#include "People.h"

using namespace std;

class Civilians : public People {
public:
	Civilians(int = 1, int = 1, int = 0, int = 30, int = 0, bool = 0, bool = 0, int = 1, int = 1);
	void Fight(int** board);
	void Multiplication(Civilians* Civil, int** board, int AmmountCivilians, int EndCivilians);
};