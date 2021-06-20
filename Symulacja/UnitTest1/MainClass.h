#pragma once
#include <iostream>

using namespace std;

class MainClass {
protected:
	int Health, TakenDamage;
	int Xpos, Ypos;
	bool died;
	int move, baseNumber;
public:
	int getXpos();
	int getYpos();
	int getDied();
	void setXpos(int x);
	void setYpos(int y);
	void setDied(bool die);
	void ArrangeSpecimens(int** board);
	void ArrangeAdditives(int** board, int** AdditivesMap);
	void Movement(int** board);
	virtual void Dying(int** board);
};