#pragma once
#include <iostream>
#include "People.h"

using namespace std;

class Soldiers : public People {
public:
	Soldiers(int = 1, int = 1, int = 0, int = 30, int = 0, bool = 0, bool = 0, int = 2, int = 1);
	virtual void Fight(int** board);
	void Multiplication(Soldiers* Soldier, int** board, int AmmountSoldiers, int EndSoldiers);
};