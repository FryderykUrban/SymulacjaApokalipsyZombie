#include <iostream>
#include "StrongZombie.h"

using namespace std;

StrongZombies::StrongZombies(int ax, int ay, int tk, int h, bool die, int bn, int mv) {					// konstruktor
	Xpos = ax;
	Ypos = ay;
	TakenDamage = tk;
	Health = h;
	died = die;
	baseNumber = bn;
	move = mv;
}