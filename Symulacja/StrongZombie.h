#pragma once
#include <iostream>
#include "Zombie.h"

using namespace std;

class StrongZombies : public Zombie {
public:
	StrongZombies(int = 2, int = 1, int = 0, int = 30, bool = 0, int = 4, int = 3);
};