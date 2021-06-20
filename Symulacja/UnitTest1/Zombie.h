#pragma once
#include <iostream>
#include "MainClass.h"
#include "Civilians.h"
#include "Soldiers.h"

using namespace std;

class Zombie : public MainClass {
public:
	void Fight(Soldiers* Soldier, Civilians* Civil, int** board, int AmmountCivilians, int AmmountSoldiers);
};