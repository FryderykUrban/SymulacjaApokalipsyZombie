#pragma once
#include <iostream>
#include "Zombie.h"

using namespace std;

class WeakZombies : public Zombie {
public:
	WeakZombies(int = 1, int = 1, int = 0, int = 25, bool = 0, int = 3, int = 1);
};
