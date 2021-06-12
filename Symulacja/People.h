#pragma once
#include <iostream>
#include "MainClass.h"


using namespace std;

class People : public MainClass {
protected:
	bool Have;
	int capacity;
public:
	int getHave();
	int getHealth();
	void setHave(bool hve);
	void setHealth(int hlt);
	void CollectingFood(int** AdditivesMap);
	void Starving();
	virtual void Fight(int** board) = 0;
	virtual void Dying(int** board, int** AdditivesMap);
	void CollectingWepons(int** AdditivesMap);
};