#pragma once
#include <iostream>
#include "Civilians.h"
#include "Soldiers.h"
#include "WeakZombie.h"
#include "StrongZombie.h"
#include "Food.h"
#include "Weapons.h"

using namespace std;

class Map {
	int** board;
	int** AdditivesMap;
	int width, height;
public:
	Map(int w = 50, int h = 20);
	~Map();
	int getWidth();
	int getHeight();
	int** getArrayAdditivesMap();
	int** getBoard();
	void setArrayAdditivesMap(unsigned int xd, unsigned int ya, int ua);
	void setBoard(unsigned int xd, unsigned int ya, int ua);
	void CreateMap(int EndCivilian, int EndSoldier, int EndWeakZombie, int EndStrongZombie);
	void count(int& EndCivilian, int& EndSoldier, int& EndWeakZombie, int& EndStrongZombie, int& CurrentlyFood);
	void Reducing(int& EndCivilian, int& EndSoldier, int& EndWeakZombie, int& EndStrongZombie, int& CurrentlyFood);
};