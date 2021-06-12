#include <iostream>
#include "WeakZombie.h"

using namespace std;

WeakZombies::WeakZombies(int ax, int ay, int tk, int h, bool die, int bn, int mv) {
	Xpos = ax;
	Ypos = ay;
	TakenDamage = tk;
	Health = h;
	died = die;
	baseNumber = bn;
	move = mv;
}